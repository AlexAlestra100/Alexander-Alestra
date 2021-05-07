#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
	int num = 0;
	printf("Please enter the number of packets: ");
	scanf("%d", &num);
   
	if(num<=0){
		printf("Wrong input: the number of packets must be greater than 0.\n");
		return 0;
	}

	char packet[num];
	int high[num];
	int low[num];
	float buffer_size = 3;
   
	printf("Please enter the priority of the packets with no space between (H represents high priority, L represents low priority):\n");
	scanf("%s", packet);

	for(int i=0;i<num;i++){
		if(packet[i] != 'H' && packet[i] != 'L')
		{
			printf("Wrong input: the priority must be H or L.\n");
			return 0;
		}
	}

	if((unsigned)strlen(packet) != num){
		printf("Wrong input: the number of packets is wrong.\n");
		return 0;
	}

    for(int f = 0; f < num; f++){
        low[f] = -1;
        high[f] = -1;
    }
    
	int a = 0, b = 0;
	for(int x = 0; x < num; x++){
		if(packet[x] == 'H')
		{
			high[a] = x;
			a++;
		}
		else
		{
			low[b] = x;
			b++;
		}
	}
	
	for(int last = 0; last < num; last++){
	   	for(int j = 0; j < num; j++){
	    	if(high[j] >= (buffer_size * last) && high[j] < (buffer_size * (last+1)) && high[j] != -1)
	    	{
	    	    printf("%d ", high[j]);
	    	}
	   	}
	   	for(int k = 0; k < num; k++){
		    if(low[k] >= (buffer_size * last) && low[k] < (buffer_size * (last+1)) && low[k] != -1)
		    {
		        printf("%d ", low[k]);
		    }
	    }
	}
	
	printf("\n");
	
  return 0;
}
