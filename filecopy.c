/**
 * filecopy.c
 * 
 * This program copies files using a pipe.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
	if (argc != 3) { 
		printf("Only 2 arguments alllowed. source - destination.");
		return 1;
	}

	FILE* fptr; // pointer 


	fptr = fopen(argv[1], "r"); 

	if (fptr == NULL) { 
		printf("File not found."); 
		return 1; 
	}



	


	return 0; 
}
