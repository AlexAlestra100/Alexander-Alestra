#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
   int *pid;
   int *arrival;
   int *burst;
   struct node *next;
   struct node *prev;
};

typedef struct queue{
   struct node *head;
   struct node *tail;
}queue;

void enqueue(queue *q, int *pid, int *arrival, int *burst);

void dequeue(queue *q, int *pid, int *arrival, int *burst);

void printQueue(queue *q);

void sortQueuebyArrival(queue *q);

void sortQueuebyBurst(queue *q);

int countNodes(queue *q);

void printAll(queue *q, int count);

void printFCFS(queue *q, int count, char *alg, char *fileN);

void printSRTF(queue *q, int count, char *alg, char *fileN);

void printRR(queue *q, int count, char *alg, char *fileN, int quantum);

void pressEnter();

int isEmpty(queue *q);

int search(int count, int arr[count][2], int pid);

int main(int argc, char *argv[])
{
   int count = 0;

   if(argc == 2){
      printf("Must have a scheduling algorithm chosen!");
   }
   else{
      FILE *fp;

      fp = fopen(argv[1], "r");

      char *line = NULL;
      size_t len = 0;
      ssize_t read;
      queue *q = malloc(sizeof(queue));
      q->head = NULL;
      q->tail = NULL;

      while((read = getline(&line, &len, fp)) != -1){
         char *token = strtok(line, " ");
         int *pid = malloc(sizeof(int));
         int *arrival = malloc(sizeof(int));
         int *burst = malloc(sizeof(int));
         *pid = atoi(token);
         token = strtok(NULL, " ");
         *arrival = atoi(token);
         token = strtok(NULL, " ");
         *burst = atoi(token);
         enqueue(q, pid, arrival, burst);
      }
      fclose(fp);

      count = countNodes(q);
      sortQueuebyArrival(q);

      if(fp == NULL){
         printf("File not found!");
         return 1;
      }
      
      if(strcmp(argv[2], "FCFS") == 0){
         printFCFS(q, count, argv[2], argv[1]);

      }
      else if(strcmp(argv[2], "SRTF") == 0){
         printSRTF(q, count, argv[2], argv[1]);
      }
      else if(strcmp(argv[2], "RR") == 0){
         if(argv[3]){
            printRR(q, count, argv[2], argv[1], atoi(argv[3]));
         }
         else{
            printf("No quantum value given!\n");
         }
      }
      else{
         printf("Invalid algorithm!\n");
         printf("%s\n", argv[2]);
      }
   }
   return 0;
}

void enqueue(queue *q, int *pid, int *arrival, int *burst){
   struct node *temp = (struct node*)malloc(sizeof(struct node));
   temp->pid = pid;
   temp->arrival = arrival;
   temp->burst = burst;
   temp->next = NULL;
   temp->prev = NULL;
   if(q->head == NULL){
      q->head = temp;
      q->tail = temp;
   }
   else{
      q->tail->next = temp;
      temp->prev = q->tail;
      q->tail = temp;
   }
}

void dequeue(queue *q, int *pid, int *arrival, int *burst){
   struct node *temp = q->head;
   pid = temp->pid;
   arrival = temp->arrival;
   burst = temp->burst;
   q->head = temp->next;
   free(temp);
}

void printQueue(queue *q){
   struct node *temp = q->head;
   while(temp != NULL){
      printf("PID: %d, Arrival: %d, Burst: %d\n", *(temp->pid), *(temp->arrival), *(temp->burst));
      temp = temp->next;
   }
}

int countNodes(queue *q){
   int count = 0;
   struct node *temp = q->head;
   while(temp != NULL){
      count++;
      temp = temp->next;
   }
   return count;
}

void sortQueuebyBurst(queue *q){
   struct node *temp = q->head;
   struct node *temp2 = q->head;
   while(temp != NULL){
      temp2 = temp->next;
      while(temp2 != NULL){
         if(*(temp->burst) > *(temp2->burst)){
            int *tempPID = temp->pid;
            int *tempArrival = temp->arrival;
            int *tempBurst = temp->burst;
            temp->pid = temp2->pid;
            temp->arrival = temp2->arrival;
            temp->burst = temp2->burst;
            temp2->pid = tempPID;
            temp2->arrival = tempArrival;
            temp2->burst = tempBurst;
         }
         temp2 = temp2->next;
      }
      temp = temp->next;
   }
}

void sortQueuebyArrival(queue *q){
   struct node *temp = q->head;
   while(temp != NULL){
      if(temp->next != NULL){
         if(*(temp->arrival) > *(temp->next->arrival)){
            struct node *temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = temp;
            temp2->prev = temp->prev;
            temp->prev = temp2;
            if(temp2->prev != NULL){
               temp2->prev->next = temp2;
            }
            else{
               q->head = temp2;
            }
            temp = temp2;
         }
      }
      temp = temp->next;
   }
}

void pressEnter(){
   getchar();
}

void printFCFS(queue *q, int count, char *alg, char *fileN){
   struct node *temp = q->head;
   int j = 0;
   int waintime = 0;
   int responsetime = 0;
   int turnaround = 0;
   int cpuU = 0;

   printf("Schdeuling algorithm: %s\n", alg);
   printf("Total %d tasks are read from \"%s\" press 'enter' to start...\n", count, fileN);
   printf("==================================================================\n");
   pressEnter();

   while(!isEmpty(q)){
      int i = 0;

      for(i; i <= *(temp->burst); i++){
         if(i == 0){
            waintime += j - *(temp->arrival);
            responsetime += j - *(temp->arrival);
            cpuU += *(temp->burst);
         }
         if(i < *(temp->burst)){
            printf("<system time %d> process %d is running.......\n", j, *(temp->pid));
            j++;
         }
         if(i == *(temp->burst)){
            printf("<system time %d> process %d is finished.......\n", j, *(temp->pid));
            turnaround += j - *(temp->arrival);
         }
      }

      dequeue(q, temp->pid, temp->arrival, temp->burst);
      temp = temp->next;
   }

   printf("<system time %d> All processes finish ....................\n", j);
   printf("==================================================================\n");
   printf("Avarage cpu usage : %.2f%%\n", (float)(cpuU / j) * 100);
   printf("Avarage waiting time : %.2f\n", (float)waintime/count); 
   printf("Avarage response time : %.2f\n", (float)responsetime/count);
   printf("Avarage turnaround time: %.2f\n", (float)turnaround/count);
   printf("==================================================================\n");
}

void printSRTF(queue *q, int count, char *alg, char *fileN){
   queue *rrQ = malloc(sizeof(queue));
   rrQ->head = NULL;
   rrQ->tail = NULL;
   struct node *temp2 = q->head;
   struct node *temp = rrQ->head;
   struct node *temp3 = q->head;

   int tempArr[count][2];
   
   int j = 0;
   int waintime = 0;
   int responsetime = 0;
   int turnaround = 0;
   int cpuUsage = 0;

   int x = 0;
   while(temp3 != NULL){
      tempArr[x][0] = *(temp3->pid);
      tempArr[x][1] = *(temp3->burst);
      x++;
      temp3 = temp3->next;
   }

   printf("Schdeuling algorithm: %s\n", alg);
   printf("Total %d tasks are read from \"%s\" press 'enter' to start...\n", count, fileN);
   printf("==================================================================\n");
   pressEnter();

   while(*(temp2->arrival) == j){
      enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
      dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
      
      temp = rrQ->head;

      if(temp2->next != NULL){
         temp2 = temp2->next;
      }
   }

   sortQueuebyBurst(rrQ);

   while(!isEmpty(q) || !isEmpty(rrQ)){
      int i = 1;

      while(isEmpty(rrQ)){
         j++;
         cpuUsage++;
         while(*(temp2->arrival) <= j){
            if(!isEmpty(q)){
               enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
               dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
            }
            if(temp2->next != NULL){
               temp2 = temp2->next;
            }
         }
         sortQueuebyBurst(rrQ);
      }
   
      for(i; i <= *(temp->burst); i++){
         if(i == 1 && *(temp->burst) == search(count, tempArr, *(temp->pid))){
            responsetime += j - *(temp->arrival);
         }
         if(i <= *(temp->burst)){
            printf("<system time %d> process %d is running.......\n", j, *(temp->pid));
            *(temp->burst) -= 1;
            j++;
            while(*(temp2->arrival) == j && temp2 != NULL && !isEmpty(q)){
               if(!isEmpty(q)){
                  enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
                  dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
               }
               if(temp2->next != NULL){
                  temp2 = temp2->next;
               }
            }
            sortQueuebyBurst(rrQ);
         }
         if(*(temp->burst) == 0){
            printf("<system time %d> process %d is finished.......\n", j, *(temp->pid));
            turnaround += j - *(temp->arrival);
            waintime += (j - *(temp->arrival)) - search(count, tempArr, *(temp->pid));
            dequeue(rrQ, temp->pid, temp->arrival, temp->burst);
            if(rrQ->head != NULL){
               temp = rrQ->head;
            }
            break;
         }
      }
   }

   printf("<system time %d> All processes finish ....................\n", j);
   printf("==================================================================\n");
   printf("Avarage cpu usage : %.2f%%\n", (float)(count - cpuUsage)/count*100);
   printf("Avarage waiting time : %.2f\n", (float)waintime/count); 
   printf("Avarage response time : %.2f\n", (float)responsetime/count);
   printf("Avarage turnaround time: %.2f\n", (float)turnaround/count);
   printf("==================================================================\n");
}

void printRR(queue *q, int count, char *alg, char *fileN, int quantum){
   queue *rrQ = malloc(sizeof(queue));
   rrQ->head = NULL;
   rrQ->tail = NULL;
   struct node *temp2 = q->head;
   struct node *temp = rrQ->head;
   struct node *temp3 = q->head;

   int tempArr[count][2];
   
   int j = 0;
   int waintime = 0;
   int responsetime = 0;
   int turnaround = 0;
   int cpuUsage = 0;
   int x = 0;

   while(temp3 != NULL){
      tempArr[x][0] = *(temp3->pid);
      tempArr[x][1] = *(temp3->burst);
      x++;
      temp3 = temp3->next;
   }
   

   printf("Schdeuling algorithm: %s\n", alg);
   printf("Total %d tasks are read from \"%s\" press 'enter' to start...\n", count, fileN);
   printf("==================================================================\n");
   pressEnter();

   while(*(temp2->arrival) == j){
      enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
      dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
      
      temp = rrQ->head;

      if(temp2->next != NULL){
         temp2 = temp2->next;
      }
   }

   while(!isEmpty(q) || !isEmpty(rrQ)){
      int i = 1;
      while(isEmpty(rrQ)){
         j++;
         cpuUsage++;
         while(*(temp2->arrival) <= j){
            if(!isEmpty(q)){
               enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
               dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
            }
            if(temp2->next != NULL){
               temp2 = temp2->next;
            }
         }
      }
   
      for(i; i <= quantum; i++){
         if(i == 1 && *(temp->burst) == search(count, tempArr, *(temp->pid))){
            responsetime += j - *(temp->arrival);
         }
         if(i <= quantum){
            printf("<system time %d> process %d is running.......\n", j, *(temp->pid));
            *(temp->burst) -= 1;
            j++;
            while(*(temp2->arrival) == j && temp2 != NULL && !isEmpty(q)){
               if(!isEmpty(q)){
                  enqueue(rrQ, temp2->pid, temp2->arrival, temp2->burst);
                  dequeue(q, temp2->pid, temp2->arrival, temp2->burst);
               }
               if(temp2->next != NULL){
                  temp2 = temp2->next;
               }
            }
         }
         if(*(temp->burst) == 0){
            printf("<system time %d> process %d is finished.......\n", j, *(temp->pid));
            turnaround += j - *(temp->arrival);
            waintime += (j - *(temp->arrival)) - search(count, tempArr, *(temp->pid));
            dequeue(rrQ, temp->pid, temp->arrival, temp->burst);
            if(rrQ->head != NULL){
               temp = rrQ->head;
            }
            break;
         }
         if(i == quantum){
            if(*(temp->burst) != 0){
               enqueue(rrQ, temp->pid, temp->arrival, temp->burst);
            }
            dequeue(rrQ, temp->pid, temp->arrival, temp->burst);
            if(rrQ->head != NULL){
               temp = rrQ->head;
            }
         }
      }
   }

   printf("<system time %d> All processes finish ....................\n", j);
   printf("==================================================================\n");
   printf("Avarage cpu usage : %.2f%%\n", (float)(count - cpuUsage)/count*100);
   printf("Avarage waiting time : %.2f\n", (float)waintime/count); 
   printf("Avarage response time : %.2f\n", (float)responsetime/count);
   printf("Avarage turnaround time: %.2f\n", (float)turnaround/count);
   printf("==================================================================\n");
}

int isEmpty(queue *q){
   if(q->head == NULL){
      return 1;
   }
   else{
      return 0;
   }
}

int search(int count, int arr[count][2], int pid){
   int i;
   for(i = 0; i < count; i++){
      if(arr[i][0] == pid){
         return arr[i][1];
      }
   }
}