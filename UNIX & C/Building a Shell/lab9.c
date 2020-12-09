/* Author(s): Alexander Alestra.
 *
 * This is lab9.c the csc60mshell
 * This program serves as the base for doing labs 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in the directions.
 * Date: Fall 2020
 */

/* The include files section */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* Define Section */
#define MAXLINE 80
#define MAXARGS 20
#define MAX_PATH_LENGTH 50
#define TRUE 1

/* function prototypes */
int CommandParse(char *cmdline, char **argv);

//The two function prototypes below will be needed in lab10. 
//Leave them here to be used later.
// void ProcessCommand(int argc, char **argv); 
// void CheckRedirection(int argc, char *argv[]); 


/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char cmdline[MAXLINE];
    char *argv[MAXARGS];
    int argc;
//    int status;
//    pid_t pid;

    /* Loop forever to wait and process commands */
    while (TRUE)
    {
		/*DONE Print your shell name: csc60msh (m for mini shell) */
		printf("csc60msh> ");

		/* Read the command line */
		fgets(cmdline, MAXLINE, stdin);

		/*DONE Call CommandParse to build argc/argv */
        argc = CommandParse(cmdline, argv);

		/*DONE Print the values in argc and argv as described in the directions */
        int i;
        for(i = 0; i < argc;++i)
        {
                printf("Argv %i = %s \n", i, argv[i]);
        }
				
		/*DONE If user hits enter key without a command, continue to loop */
		/* again at the beginning */
		/*  Hint: if argc is zero, no command declared */
		/*  Hint: look up for the keyword "continue" in C */
		if(argc == 0)
        {
                continue;
        }

		/*DONE Handle build-in command: exit, pwd, or cd */
		/* Put the rest of your code here */
        if(strcmp(argv[0], "exit") == 0)
        {
                break;
        }
        else if(strcmp(argv[0], "pwd") == 0)
        {
                char buf[MAX_PATH_LENGTH];
                getcwd(buf, MAX_PATH_LENGTH);
                printf("%s\n", buf);
                continue;       
        }
        else if(strcmp(argv[0], "cd") == 0)
        {
                char *dir;
                if(argc == 1)
                {
                        dir = getenv("HOME");
                }
                else
                {
                        dir = argv[1];
                }
                if(chdir(dir) != 0)
                {
                        printf("Error changing directory\n");
                }
                continue;
        }
 
//.......................IGNORE........................	
//	/* Else, fork off a process */
//      else {
//	    pid = fork();
//          switch(pid)
//    	    {
//	    	case -1:
//		    	perror("Shell Program fork error");
//	            exit(EXIT_FAILURE);
//	   		case 0:
//		    	/* I am child process. I will execute the command, */
//		    	/* and call: execvp */
//		    	ProcessCommand(argc, argv);
//		    	break;
//	   		default:
//		    	/* I am parent process */
//		    	if (wait(&status) == -1)
//		    		perror("Parent Process error");
//		    	else
//		   		printf("Child returned status: %d\n\n",status);
//		    	break;
//	    } 	/* end of the switch */
//	}		/* end of the if-else-if */
//...end of the IGNORE above.........................
    }		/* end of the while */
} 			/* end of main */

/* ----------------------------------------------------------------- */
/*                  CommandParse                                        */
/* ----------------------------------------------------------------- */
/* Parse input line into argc/argv format */

int CommandParse(char *cmdline, char **argv)
{
    int argc = 0;
    char *separator = " \n\t"; /* Includes space, Enter, Tab */
 
    /* strtok searches for the characters listed in separator */
    argv[argc] = strtok(cmdline, separator);

    while ((argv[argc] != NULL) && (argc+1 < MAXARGS)){ 
    	argv[++argc] = strtok((char *) 0, separator);
    } 		
    return argc;  
}
/* ----------------------------------------------------------------- */
/*                  ProcessCommand                                    */
/* ----------------------------------------------------------------- */
/*void ProcessCommand(int argc, char **argv) {                        */

    /* Step 1: Call CheckRedirection to deal with operators:             */
    /* < , or  >, or both                                            */


    /* Step 2: perform system call execvp to execute command         */
    /* Hint: Please be sure to review execvp.c sample program        */
    /* if (........ == -1) {                                         */
    /*    fprintf(stderr, "Error on the exec call\n");               */
    /*    _exit(EXIT_FAILURE);                                       */
    /* }                                                             */
 
// }
/* ----------------------------------------------------------------- */
//void CheckRedirection(int argc, char *argv[])
/* ----------------------------------------------------------------- */


/* ----------------------------------------------------------------- */
