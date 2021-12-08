#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *pageBuffer;
int *frameBuffer;
int *tempBuffer;
int pages;
int frames;
int pageRequests;
int pageFaults = 0;
int clockPointer;

void printBuffer(int size)
{
   int i;
   for(i = 0; i <= size; i++)
   {
      printf("%d ", tempBuffer[i]);
   }
   printf("\n");
}

void printFrameBuffer()
{
   int i;
   for(i = 0; i < frames; i++)
   {
      printf("%d ", frameBuffer[i]);
   }
   printf("\n");
}

void printTempFBuffer()
{
   int i;
   for(i = 0; i < pageRequests; i++)
   {
      printf("%d ", tempBuffer[i]);
   }
   printf("\n");
}

void copyBuffer(int num)
{
   int i;
   for(i = 0; i <= num; i++)
   {
      tempBuffer[i] = pageBuffer[i];
   }
}

void removeNumbers(int num)
{
   int i;
   for(i = 0; i <= pageRequests; i++)
   {
      if(tempBuffer[i] == num)
      {
         tempBuffer[i] = -1;
      }
   }
}

void removeFrame(int num)
{
   int i;
   for(i = 0; i <= frames; i++)
   {
      if(frameBuffer[i] == num)
      {
         frameBuffer[i] = -1;
      }
   }
}

void findLeast(int page, int starti)
{
   int index = 0;
   int replacementPage = 0;
   int count = 0;
   int i;

   //allocate memory to tempBuffer and copy pageBuffer to tempBuffer
   tempBuffer = (int*)malloc(sizeof(int) * (pageRequests + 1));
   removeNumbers(0);
   copyBuffer(pageRequests);

   for(i = 0; i < frames; i++)
   {
      int start = starti;
      int j = 1;
      for(start; start >= 0; start--)
      {  
         // printf("Page: %d\n", page);
         // printBuffer(start);
         // printf("%d == %d && %d < %d && %d != %d", tempBuffer[start], frameBuffer[i], j, count, replacementPage, frameBuffer[i]);
         if(tempBuffer[start] == frameBuffer[i] && j > count && replacementPage != frameBuffer[i])
         {
            // printf(" YES\n");
            count = j;
            replacementPage = frameBuffer[i];
            index = i;
            removeNumbers(frameBuffer[i]);
            break;
         }
         if(tempBuffer[start] == frameBuffer[i] && j <= count)
         {
            // printf(" NO\n");
            removeNumbers(frameBuffer[i]);
         }
         // else
         // {
         //    printf(" NO\n");
         // }
         j++;
         // printFrameBuffer();
      }
   }
   frameBuffer[index] = page;
   printf("Page %d unloaded from Frame %d, Page %d loaded into Frame %d\n", replacementPage, index, page, index);
   pageFaults++;
   free(tempBuffer);
}

void checkOpenening(int page, int index)
{
   int i;
   int foundNegOne = 0;

   for(i = 0; i < frames; i++)
   {
      if(frameBuffer[i] == -1)
      {
         // printFrameBuffer();
         frameBuffer[i] = page;
         printf("Page %d loaded into Frame %d\n", frameBuffer[i], i);
         pageFaults++;
         foundNegOne = 1;
         break;
      }
   }

   if(foundNegOne == 0)
   {
      findLeast(page, index);
   }
}

void checkFreeSpot(int page)
{
   int i;
   int foundNegOne = 0;
   int tempPage = 0;
   int tempIndex = 0;

   for(i = 0; i < frames; i++)
   {
      if(frameBuffer[i] == -1)
      {
         // printFrameBuffer();
         frameBuffer[i] = page;
         printf("Page %d loaded into Frame %d\n", frameBuffer[i], i);
         pageFaults++;
         clockPointer = i;
         foundNegOne = 1;
         clockPointer = (clockPointer + 1) % frames;
         break;
      }
   }

   if(foundNegOne == 0)
   {
      while(1)
      {
         // printFrameBuffer();
         // printTempFBuffer();
         // printf("Frame Index: %d, Ref: %d == 0", clockPointer, tempBuffer[clockPointer]);
         if(tempBuffer[clockPointer] == 0)
         {
            // printf(" - YES\n");
            tempPage = frameBuffer[clockPointer];
            tempIndex = clockPointer;
            frameBuffer[clockPointer] = page;
            printf("Page %d unloaded from Frame %d, Page %d loaded into Frame %d\n", tempPage, tempIndex, page, tempIndex);
            pageFaults++;
            tempBuffer[clockPointer] = 0;
            clockPointer = (clockPointer + 1) % frames;
            break;
         }
         else
         {
            // printf(" - NO\n");
            tempBuffer[clockPointer] = 0;
            clockPointer = (clockPointer + 1) % frames;
         }
      }
   }
}

int CheckFrameBuffer(int page)
{
   int i;

   for(i = 0; i < frames; i++)
   {
      if(frameBuffer[i] == page)
      {
         return i;
         break;
      }
   }
   return -1;
}

void LRU()
{  
   int i;
   for(i = 0; i < pageRequests; i++)
   {
      int checkedFrame = CheckFrameBuffer(pageBuffer[i]);

      if(checkedFrame != -1)
      {
         printf("Page %d is already in frame %d\n", frameBuffer[checkedFrame], checkedFrame);
      }
      else if(checkedFrame == -1)
      {
         checkOpenening(pageBuffer[i], i - 1);
      }
   }
   printf("%d page faults\n", pageFaults);
}

void CLOCK()
{
   int i;

   tempBuffer = (int*)malloc(sizeof(int) * frames);

   // printTempFBuffer();

   for(i = 0; i < pageRequests; i++)
   {
      int checkedFrame = CheckFrameBuffer(pageBuffer[i]);

      // printTempFBuffer();
      if(checkedFrame != -1)
      {
         printf("Page %d is already in frame %d\n", frameBuffer[checkedFrame], checkedFrame);
         tempBuffer[checkedFrame] = 1;
      }
      else if(checkedFrame == -1)
      {
         checkFreeSpot(pageBuffer[i]);
      }
   }
   printf("%d page faults\n", pageFaults);

   free(tempBuffer);
}

//create a function that sorts the array
void sortArray(int *array, int size)
{
   int i, j;
   for(i = 0; i < size; i++)
   {
      for(j = 0; j < size; j++)
      {
         if(array[i] < array[j])
         {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
         }
      }
   }
}


// take in 2 arguments:form the command line
int main(int argc, char *argv[])
{
   int i;
   int arrayPage[100];
   int numPages = 1;

   // check if the number of arguments is correct
   if (argc != 3)
   {
      printf("Usage: %s <input_file> <LRU|CLOCK>\n", argv[0]);
      exit(1);
   }

   // open the file
   FILE *fp = fopen(argv[1], "r");

   // check if the file is open
   if (fp == NULL)
   {
      printf("Error opening file %s\n", argv[1]);
      exit(1);
   }

   // read the file but the first line will fill in pages, frames, and pageRequests.
   fscanf(fp, "%d %d %d", &pages, &frames, &pageRequests);
   if(pages <= 0 || frames <= 0 || pageRequests <= 0)
   {
      printf("Error: pages, frames, and page requests must be a positive non zero integer!\n");
      exit(1);
   }

   // the rest of the lines will be inserted into the buffer
   pageBuffer = (int *)calloc(pageRequests, sizeof(int));
   frameBuffer = (int *)calloc(frames, sizeof(int));
   removeFrame(0);
   int lineN = 0;

   // read file line by line till end of file
   i = 0;

   int numPage = 0;
   while(fscanf(fp, "%d", &pageBuffer[i]) != EOF)
   {
      i++;
      lineN++;
   }

   // close the file
   fclose(fp);

   //Copy what is in the pageBuffer to the arrayPage
   for(i = 0; i < pageRequests; i++)
   {
      arrayPage[i] = pageBuffer[i];
   }

   sortArray(arrayPage, pageRequests);

   int temp = arrayPage[0];

   for(i = 0; i < pageRequests; i++)
   {
      if(temp != arrayPage[i])
      {
         numPages++;
         temp = arrayPage[i];
      }
   }

   // printf("%d > %d\n", numPages, pages);

   //compare the results of the distinctElements function and pages
   if(numPages > pages)
   {
      printf("Error: The number of distinct pages is more than the number of pages given!\n");
      exit(1);
   }

   // compares the actual number of page request given to the page request assigned
   if(lineN != pageRequests)
   {
      printf("Error: the number of given page request in the file is not equal to the number of page requests set!\n");
      exit(1);
   }

   // check if the algorithm is LRU or CLOCK
   if(strcmp(argv[2], "LRU") == 0)
   {
      printf("Algorithm: LRU\n");
      // printf("Pages: %d, Frames: %d, Page Requests: %d\n", pages, frames, pageRequests);
      // printf("Buffer: ");
      // for(i = 0; i < pageRequests; i++)
      // {
      //    if(i == pageRequests - 1)
      //    {
      //       printf("%d\n", pageBuffer[i]);
      //    }
      //    else
      //    {
      //       printf("%d, ", pageBuffer[i]);
      //    }
      // }
      LRU();
      free(pageBuffer);
      free(frameBuffer);
   }
   else if(strcmp(argv[2], "CLOCK") == 0)
   {
      // call CLOCK function
      printf("Algorithm: CLOCK\n");
      // printf("Pages: %d, Frames: %d, Page Requests: %d\n", pages, frames, pageRequests);
      // printf("Buffer: ");
      // for(i = 0; i < pageRequests; i++)
      // {
      //    if(i == pageRequests - 1)
      //    {
      //       printf("%d\n", pageBuffer[i]);
      //    }
      //    else
      //    {
      //       printf("%d, ", pageBuffer[i]);
      //    }
      // }
      CLOCK();
      free(pageBuffer);
      free(frameBuffer);
   }
   else
   {
      printf("Usage: %s <input_file> <LRU|CLOCK>\n", argv[0]);
      exit(1);
   }

   return 0;
}
   