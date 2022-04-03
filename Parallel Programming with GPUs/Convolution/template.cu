#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <wb.h>

#define MASK_WIDTH 5
#define O_TILE_WIDTH 16
#define clamp(x) (min(max((x), 0.0), 1.0))
#define TILE_SIZE O_TILE_WIDTH * O_TILE_WIDTH * 3
#define BLOCK_WIDTH O_TILE_WIDTH + (MASK_WIDTH - 1)

//@@ INSERT CODE HERE 
//implement the tiled 2D convolution kernel with adjustments for channels
//use shared memory to reduce the number of global accesses, handle the boundary conditions when loading input list elements into the shared memory
//clamp your output values

__global__ void convolution_2D(const float* __restrict__ mask, float* P, float* input, int height, int width, int channels) {
	int tx = threadIdx.x;
	int ty = threadIdx.y;

	int K = threadIdx.z;
	int maskRadius = MASK_WIDTH / 2;

	int col = blockIdx.x * blockDim.x + tx;
	int row = blockIdx.y * blockDim.y + ty;

	int row_i = row - ((MASK_WIDTH - 1) * blockIdx.y) - maskRadius;
	int col_i = col - ((MASK_WIDTH - 1) * blockIdx.x) - maskRadius;

	int i, j, k, ind;
	float imagePixel, maskV;
	__shared__ float I[TILE_SIZE];

	k = (ty * blockDim.y + tx) * channels + K;
	ind = (row_i * width + col_i) * channels + K;
	if (row_i >= 0 && row_i < height && col_i >= 0 && col_i < width) {
		I[k] = input[ind];
	}
	else {
		I[k] = 0.0f;
	}

	__syncthreads();

    if(row_i >= 0 && row_i < height && col_i >= 0 && col_i < width) {
        if(tx >= maskRadius && tx < (blockDim.x - maskRadius) && ty >= maskRadius && ty < (blockDim.y - maskRadius)) {
            float accum = 0.0f;
            for(i = 0; i < MASK_WIDTH; i++) {
                for(j = 0; j < MASK_WIDTH; j++) {
                    int xOffset = ty - maskRadius + i;
                    int yOffset = tx - maskRadius + j;
                    imagePixel = I[(xOffset * blockDim.y + yOffset) * channels + K];
                    maskV = mask[i * MASK_WIDTH + j];
                    accum += imagePixel * maskV;
                }
            }
            P[(row_i * width + col_i) * channels + K] = clamp(accum, 0, 1);
        }
    }
}

int main(int argc, char *argv[]) {
  wbArg_t arg;
  int maskRows;
  int maskColumns;
  int imageChannels;
  int imageWidth;
  int imageHeight;
  char *inputImageFile;
  char *inputMaskFile;
  wbImage_t inputImage;
  wbImage_t outputImage;
  float *hostInputImageData;
  float *hostOutputImageData;
  float *hostMaskData;
  float *deviceInputImageData;
  float *deviceOutputImageData;
  float *deviceMaskData;

  arg = wbArg_read(argc, argv); /* parse the input arguments */

  inputImageFile = wbArg_getInputFile(arg, 0);
  inputMaskFile  = wbArg_getInputFile(arg, 1);

  inputImage   = wbImport(inputImageFile);
  hostMaskData = (float *)wbImport(inputMaskFile, &maskRows, &maskColumns);

  assert(maskRows == MASK_WIDTH);    /* mask height is fixed to 5 */
  assert(maskColumns == MASK_WIDTH); /* mask width is fixed to 5 */

  imageWidth    = wbImage_getWidth(inputImage);
  imageHeight   = wbImage_getHeight(inputImage);
  imageChannels = wbImage_getChannels(inputImage);

  outputImage = wbImage_new(imageWidth, imageHeight, imageChannels);

  hostInputImageData  = wbImage_getData(inputImage);
  hostOutputImageData = wbImage_getData(outputImage);

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");

  wbTime_start(GPU, "Doing GPU memory allocation");
  //@@ INSERT CODE HERE
  //allocate device memory

  int Size = imageWidth * imageHeight * imageChannels * sizeof(float);
  int MSize = maskRows * maskColumns * sizeof(float);

  cudaMalloc((void**)&deviceInputImageData, Size);
  cudaMalloc((void**)&deviceOutputImageData, Size);
  cudaMalloc((void**)&deviceMaskData, MSize);

  wbTime_stop(GPU, "Doing GPU memory allocation");

  wbTime_start(Copy, "Copying data to the GPU");
  //@@ INSERT CODE HERE
  //copy host memory to device

  cudaMemcpy(deviceInputImageData, hostInputImageData, Size, cudaMemcpyHostToDevice);
  cudaMemcpy(deviceOutputImageData, hostOutputImageData, Size, cudaMemcpyHostToDevice);
  cudaMemcpy(deviceMaskData, hostMaskData, MSize, cudaMemcpyHostToDevice);

  wbTime_stop(Copy, "Copying data to the GPU");

  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ INSERT CODE HERE
  //initialize thread block and kernel grid dimensions
  //invoke CUDA kernel	

  dim3 dimBlock(O_TILE_WIDTH, O_TILE_WIDTH, imageChannels);
  dim3 dimGrid((imageWidth - 1) / (O_TILE_WIDTH - MASK_WIDTH) + 1, (imageHeight - 1) / (O_TILE_WIDTH - MASK_WIDTH) + 1, 1);
  convolution_2D <<<dimGrid, dimBlock>>>(deviceMaskData, deviceOutputImageData, deviceInputImageData, imageHeight, imageWidth, imageChannels);

  wbTime_stop(Compute, "Doing the computation on the GPU");

  wbTime_start(Copy, "Copying data from the GPU");
  //@@ INSERT CODE HERE
  //copy results from device to host

  cudaMemcpy(hostOutputImageData, deviceOutputImageData, Size, cudaMemcpyDeviceToHost);

  wbTime_stop(Copy, "Copying data from the GPU");

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(arg, outputImage);

  //@@ INSERT CODE HERE
  //deallocate device memory

  cudaFree(deviceInputImageData);
  cudaFree(deviceOutputImageData);
  cudaFree(deviceMaskData);

  free(hostMaskData);
  wbImage_delete(outputImage);
  wbImage_delete(inputImage);

  return 0;
}
