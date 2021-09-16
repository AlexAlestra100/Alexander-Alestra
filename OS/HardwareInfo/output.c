/*Alexander Alestra*/
/*CSC 139 Assignment 1*/

#include <stdio.h>
#include <stdlib.h>

int partB();

int main()
{
    printf("\nPart B\n");
    partB();

    return 0;
}

int partB()
{
    FILE *cpu;
    char model[100];

    cpu = fopen("/proc/cpuinfo", "r");

    if(cpu)
    {
        int i;

        for(i = 0; i < 5; i++)
        {
            fgets(model, 100, cpu);
        }

        printf("\n%s\n", model);

        fclose(cpu);

    }
    else
    {
        printf("Unable to open file!\n");
    }

    return 0;
}
