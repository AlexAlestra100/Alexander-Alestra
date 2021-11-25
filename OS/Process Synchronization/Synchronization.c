#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include "buffer.h"
#include <time.h>
#define RAND_MAX 99999

int bCount = 0;
buffer_item buffer[BUFFER_SIZE];
sem_t full, empty;
pthread_mutex_t mutex;
int numItems;
int numProducers = 0;
int numConsumers = 0;
int head = 0, tail = 0;


int insert_item(buffer_item item) {
   if(bCount < BUFFER_SIZE) {
      buffer[tail] = item;
      tail = (tail + 1) % BUFFER_SIZE;
      bCount++;
      return 0;
   }
   else {
      return -1;
   }
}

int remove_item(buffer_item *item) {
   if(bCount > 0) {
      *item = buffer[(head)];
      head = (head + 1) % BUFFER_SIZE;
      bCount--;
      return 0;
   }
   else {
      return -1;
   }
}

void *producer(void *param) {
   int p = (int)param;
   unsigned int seed;
   seed = (unsigned int)(time(NULL) + param);

   buffer_item item;
   while (1) {
      srand(time(0));
      int random = rand_r(&seed) % RAND_MAX;

      item = random;
      /* sleep for a random amount of milliseconds */
      usleep(random % BUFFER_SIZE);

      sem_wait(&empty);
      pthread_mutex_lock(&mutex);

      if(numProducers == numItems){
         pthread_mutex_unlock(&mutex);
         sem_post(&full);
         break;
      }

      /* generate a random number */
      item = random;
      if (insert_item(item) == -1)
         printf("Producer %d has an error inserting item!\n", p);
      else
         // numProducers++;
         printf("Producer %d produced %d\n", p, item);

      numProducers++;
      pthread_mutex_unlock(&mutex);
      sem_post(&full);
   }
}

void *consumer(void *param) {
   int p = (int)param;
   unsigned int seed;
   seed = time(NULL);

   buffer_item item;
   while (1) {
      sem_wait(&full);
      pthread_mutex_lock(&mutex);

      srand(time(0));
      int random = rand_r(&seed) % RAND_MAX;

      if(bCount == 0){
         pthread_mutex_unlock(&mutex);
         sem_post(&empty);
         break;
      }

      item = random;
      /* sleep for a random amount of milliseconds */
      usleep(random % BUFFER_SIZE);
      if (remove_item(&item) == -1)
         printf("Consumer %d has an error removing item!\n", p);
      else
         printf("Consumer %d consumed %d\n", p, item);

      numConsumers++;
      pthread_mutex_unlock(&mutex);
      sem_post(&empty);
   }
}

int main(int argc, char *argv[]) {
   /* 1. Get command line arguments argv[1],argv[2],argv[3] */
   if(argc != 4) {
      fprintf(stderr, "Usage: %s <# of producers> <# of consumers> <# of items to be produced>\n", argv[0]);
      exit(1);
   }

   pthread_t tid;
   pthread_attr_t attr;
   int numProds = atoi(argv[1]);
   int numCons = atoi(argv[2]);
   numItems = atoi(argv[3]);

   if(numItems <= 0) {
      fprintf(stderr, "Error: Number of items to be produced must be greater than 0\n");
      exit(1);
   }

   if(numProds <= 0 || numCons <= 0) {
      fprintf(stderr, "Error: Number of producers and consumers must be greater than 0\n");
      exit(1);
   }

   /* 2. Initialize buffer */
   pthread_mutex_init(&mutex, NULL);
   sem_init(&full, 0, 0);
   sem_init(&empty, 0, BUFFER_SIZE);

   /* 3. Create producer thread(s) */
   int i = 0;
   for (i = 0; i < numProds; i++) {
      pthread_attr_init(&attr);
      pthread_create(&tid, &attr, producer, (void*)(i + 1));
   }

   /* 4. Create consumer thread(s) */
   int j = 0;
   for (j = 0; j < numCons; j++) {
      pthread_attr_init(&attr);
      pthread_create(&tid, &attr, consumer, (void*)(j + 1));
   }

   /* 5. Wait until the specified number of items are produced and consumed */
   while (numProducers < numItems || numConsumers < numItems) {
      sleep(1);
   }

   printf("Process Complete!\n");

   return 0;
}
