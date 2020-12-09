/* Alexander Alestr                                */
/* Lab 4                                           */
/* Computer the girth of a box as defined by UPS   */

#include <stdio.h>
#include <stdlib.h>

#define FILE_IN  "lab4.dat"
#define FILE_OUT "lab4out.txt"

int main(void)
{
    int count = 1;
    int length, width, depth, girth;
    //put the file pointers here
    FILE * data_in;
    FILE * data_out;


    data_in = fopen(FILE_IN, "r");
    if(data_in == NULL)
    {
        printf("Error on opening the input file \n");
        exit(EXIT_FAILURE);
    }

    data_out = fopen(FILE_OUT, "w");
    if(data_out == NULL)
    {
	    printf("Error on opening the output file \n");
        exit(EXIT_FAILURE);
    }

    fprintf(data_out, "\nAlexander Alestra.  Lab 4.\n");

	// By definition, the first value read is the length.
	while((fscanf(data_in, "%d%d%d", &length, &width, &depth)) == 3)
    {
        girth = length + (2 * width) + (2 * depth);
        fprintf(data_out, "\nBox %1d", count);
	    fprintf(data_out, "\nThe length is:    %2i", length);
        fprintf(data_out, "\nThe height is:    %2i", width);
	    fprintf(data_out, "\nThe depth is:     %2i", depth);
        fprintf(data_out, "\nThe girth is:     %2i \n", girth);
        count++;
    }
    fprintf(data_out, "\n");

    fclose(data_in);
    fclose(data_out);

    return EXIT_SUCCESS;
}
