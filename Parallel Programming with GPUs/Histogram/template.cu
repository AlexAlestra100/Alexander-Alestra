#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <wb.h>

#define NUM_BINS 4096
#define BLOCK_SIZE 512 

#define CUDA_CHECK(ans)                                                   \
  { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line,
                      bool abort = true) {
  if (code != cudaSuccess) {
    fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code),
            file, line);
    if (abort)
      exit(code);
  }
}

__global__ void histogram(unsigned int *input, unsigned int *bins,
	unsigned int num_elements,
	unsigned int num_bins) {
	//@@ Write the kernel that computes the histogram
	//@@ Make sure to use the privitization technique
	//(hint: since NUM_BINS=4096 is larger than maximum allowed number of threads per block, 
	//be aware that threads would need to initialize more than one shared memory bin 
	//and update more than one global memory bin)
	__shared__ unsigned int histo_kernel[NUM_BINS];
	unsigned int a;
	unsigned int b;

	int i = threadIdx.x + blockDim.x * blockIdx.x;
	int stride = blockDim.x * gridDim.x;

	for (b = threadIdx.x; b < NUM_BINS; b += blockDim.x)
		histo_kernel[b] = 0u;

	__syncthreads();

	for (a = i; a < num_elements; a += blockDim.x * gridDim.x)
		atomicAdd(&(histo_kernel[input[a]]), 1);

	__syncthreads();

	for (b = threadIdx.x; b < NUM_BINS; b += blockDim.x)
		atomicAdd(&(bins[b]), histo_kernel[b]);
}

__global__ void saturate(unsigned int *bins, unsigned int num_bins) {
	//@@ Write the kernel that applies saturtion to counters (i.e., if the bin value is more than 127, make it equal to 127)
	for (int j = 0; j < num_bins / BLOCK_SIZE; j++) {
		if (bins[threadIdx.x + blockDim.x * j] > 127) {
			bins[threadIdx.x + blockDim.x * j] = 127;
		}
	}
}

int main(int argc, char *argv[]) {
  wbArg_t args;
  int inputLength;
  unsigned int *hostInput;
  unsigned int *hostBins;
  unsigned int *deviceInput;
  unsigned int *deviceBins;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput = (unsigned int *)wbImport(wbArg_getInputFile(args, 0),
                                       &inputLength, "Integer");
  hostBins = (unsigned int *)malloc(NUM_BINS * sizeof(unsigned int));
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The input length is ", inputLength);
  wbLog(TRACE, "The number of bins is ", NUM_BINS);

  wbTime_start(GPU, "Allocating device memory");
  //@@ Allocate device memory here
  int IN_SIZE = sizeof(float) * inputLength;
  cudaMalloc((void**)&deviceInput, IN_SIZE);
  int BinSize = sizeof(float) * NUM_BINS;
  cudaMalloc((void**)&deviceBins, BinSize);
  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Allocating device memory");

  wbTime_start(GPU, "Copying input host memory to device");
  //@@ Copy input host memory to device
  cudaMemcpy(deviceInput, hostInput, IN_SIZE, cudaMemcpyHostToDevice);
  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Copying input host memory to device");
	
  wbTime_start(GPU, "Clearing the bins on device");
  //@@ zero out the deviceBins using cudaMemset()
  cudaMemset(deviceBins, 0, BinSize);
  wbTime_stop(GPU, "Clearing the bins on device");

  //@@ Initialize the grid and block dimensions here
  dim3 dimBlock(BLOCK_SIZE, 1);
  dim3 dimGrid((inputLength - 1) / BLOCK_SIZE + 1, 1, 1);

  wbLog(TRACE, "Launching kernel");
  wbTime_start(Compute, "Performing CUDA computation");
  //@@ Invoke kernels: first call histogram kernel and then call saturate kernel
  histogram <<<dimGrid, dimBlock>>> (deviceInput, deviceBins, inputLength, NUM_BINS);
  saturate <<<(1, 1, 1), dimBlock>>> (deviceBins, NUM_BINS);
  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output device memory to host");
  //@@ Copy output device memory to host
  cudaMemcpy(hostBins, deviceBins, BinSize, cudaMemcpyDeviceToHost);
  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(Copy, "Copying output device memory to host");

  wbTime_start(GPU, "Freeing device memory");
  //@@ Free the device memory here
  cudaFree(deviceInput);
  cudaFree(deviceBins);
  wbTime_stop(GPU, "Freeing device memory");

  wbSolution(args, hostBins, NUM_BINS);

  free(hostBins);
  free(hostInput);
  return 0;
}
