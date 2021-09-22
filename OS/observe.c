/*Alexander Alestra*/
/*CSC 139 Assignment 1*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

FILE *ap;

char cpuinfo[] = "/proc/cpuinfo";
char hostname[] = "/proc/sys/kernel/hostname";
char loadavg[] = "/proc/loadavg";
char meminfo[] = "/proc/meminfo";
char partitions[] = "/proc/partitions";
char stat[] = "/proc/stat";
char uptime[] = "/proc/uptime";
char version[] = "/proc/version";

int partB();
int partC();
int partD(int i, int d);

int main(int argc, char *argv[]){
   char c1, c2;
   int interval, duration;

   partB();

   if(argc > 1){
      sscanf(argv[1], "%c%c", &c1, &c2);
        
      if(c1 != '-'){
        fprintf(stderr, "usage: observer [-s][-l int dur]\n\n");
        exit(1);
      }

      if(c2 == 's'){
        partC();
      }

      if(c2 == 'l'){
		partC();
		interval = atoi(argv[2]);
		duration = atoi(argv[3]);
		partD(interval, duration);
      }
   }
   
   return 0;
}

int partB(){
    printf("\nPart B\n------\n");

   char cpuModel[100];
   char host[30];
   char linuxV[42];
   int days, hours, minutes, seconds, upsec;
   double uptime1 = 0;
   time_t now = time(NULL);
   struct tm tm = *localtime(&now);
   
   ap = fopen(cpuinfo, "r");
   if(ap){
      int i;

      for(i = 0; i < 5; i++){
         fgets(cpuModel, 100, ap);
      }

      printf("\n%s\n", cpuModel);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s!\n", cpuinfo);
   }

   ap = fopen(version, "r");
   if(ap){
      fgets(linuxV, 42, ap);
      printf("%s\n", linuxV);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s!\n", version);
   }
   
   ap = fopen(uptime, "r");
   if(ap){
      fscanf(ap, "%lf", &uptime1);
      upsec = uptime1;
      days = upsec / 86400;
      hours = (upsec % 86400) / 3600;
      minutes = (upsec % 3600) / 60;
      seconds = (upsec % 60); 
      
      printf("\nTime since last reboot: (%d:%d:%d:%d)\n", days, hours, minutes, seconds);

      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s!\n", uptime);
   }

   printf("\nCurrent Time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
   ap = fopen(hostname, "r"); 
   if(ap){
      fgets(host, 30, ap);
      printf("\nMachine Host Name: %s\n", host);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s!\n", hostname);
   }

   return 0;
}

int partC(){
   printf("Part C\n------\n");

   char pros[17];
   char rw[20];
   char swit[15];
   char temp[10];
   int fuser, nuser, systm, idle;

   ap = fopen(stat,  "r");
   if(ap){ 
      fscanf(ap, "%s%d%d%d%d", temp, &fuser, &nuser, &systm, &idle);
      printf("\nUser mode: %d\nSystem mode: %d\nIdle: %d\n", (fuser + nuser), systm, idle);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("\nUnable to open file %s.\n", stat);   
   }

   ap = fopen(partitions, "r");
   if(ap){ 
      int i;
      for(i = 0; i < 11; i++)
      {
         fscanf(ap, "%s", rw);
      }
      printf("\nDisk read/write requests: %s\n", rw);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("\nUnable to open file %s.\n", partitions);   
   }
   
   ap = fopen(stat, "r");
   if(ap){
      int j;
      
      for(j = 0; j < 81; j++){
         fgets(swit, 15, ap);
      }

      printf("\nContext Switches: %s\n", swit);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s\n", stat);
   }

   ap = fopen(stat, "r");
   if(ap){
      int k;

      for(k = 0; k < 75; k++){   
         fgets(pros, 17, ap);
      }

      printf("\nProcesses since boot: %s\n\n", pros);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s\n", stat);
   }

   return 0;
}

int partD(int i, int d){
   printf("Part D\n------\n");

   char avmem[29];
   char inmem[29];
   char load[50];
   int iter = 0;

   ap = fopen(meminfo, "r");
   if(ap){
      fgets(inmem, 29, ap);
      fgets(avmem, 29, ap);
      printf("\n%s\n%s\n", inmem, avmem);
      fclose(ap);
   }
   else{
      fclose(ap);
      printf("Unable to open file %s!\n", meminfo);
   }

   printf("Load Averages\nIntervals: %d seconds\nDuration: %d seconds\n\n", i, d);
   while(iter < d){
      ap = fopen(loadavg, "r");
      fgets(load, 50, ap);
      fclose(ap);
      sleep(i);
      printf("%s\n", load);
      iter += i;
   }

   return 0;
}
