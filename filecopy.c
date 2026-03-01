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
#include <string.h> 
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
	// Check for only 3 arguments: name of program, source , destination 
	if (argc != 3) { 
		printf("Only 2 arguments alllowed. source - destination.");
		return 1;
	}


	// File descriptor for pipe
	// fd[0] for reading, fd[1] for writing
	int fd[2]; 

	if (pipe(fd) == -1 ) { 
		printf("Pipe error. ");
		return 1; 
	}
	
	// Creating pipe and assigning int value to id
	int id = fork(); 

	// Opening file for reading 
	FILE *fptr; // pointer 
	fptr = fopen(argv[1], "r"); 

	// Check if file is found
	if (fptr == NULL) { 
		printf("File not found."); 
		return 1; 
	}



	char str[] = "test string";

	// if id == 0, run child process
	if (id == 0) { 
		// Child process
		// Read from the read end of the pipe and write to destination file
		printf("Child Process started.\n"); 
		close(fd[1]); // close write end of file descriptor
		char buffer[100]; 
		read(fd[0], buffer, sizeof(buffer)); 
		printf("Got from parent pipe: %s\n",buffer); 
		close(fd[0]);

	}
	else { 
		// Parent Process
		// Read from source file and write to write end of the pipe
		printf("Parent Process started.\n");
		close(fd[0]); // close read end of file descriptor
		write(fd[1], str , strlen(str) + 1);
		close(fd[1]); 
		
	}

	


	return 0; 
}
