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
		printf("Only 2 arguments alllowed. source - destination.\n");
		return 1;
	}

	// File descriptor for pipe
	// fd[0] for reading, fd[1] for writing
	int fd[2]; 

	if (pipe(fd) == -1 ) { 
		printf("Pipe error.\n");
		return 1; 
	}

	// Opening file for reading 
	FILE *fptr; // pointer 
	fptr = fopen(argv[1], "r"); 

	// Check if file is found
	if (fptr == NULL) { 
		printf("Error: Unable to open source file '%s'.\n",argv[1]); 
		return 1; 
	}
	
	int id = fork(); // Creating pipe and assigning int value to id
	char buffer[4096]; // buffer for holding data between pipe 
	size_t bytes_read; // store # of bytes read from source file and read end of pipe

	// if id == 0, run child process
	if (id == 0) { 
		// Child process
		// Read from the read end of the pipe and write to destination file
		close(fd[1]); // close write end of file descriptor
	
		FILE *output_file; 
		output_file = fopen(argv[2],"w"); 
		if (output_file == NULL) { 
			printf("Error creating destination file.");
			return 1; 
		} 
		
		while ((bytes_read = read(fd[0],buffer,sizeof(buffer))) > 0 ) {
			fwrite(buffer,1,bytes_read,output_file);
		}

		// Close destination file and read end of file descriptor 
		fclose(output_file); 
		close(fd[0]);
		printf("File successfully copied from %s to %s.\n",argv[1],argv[2]);
	}
	else { 
		// Parent Process
		// Read from source file and write to write end of the pipe
		close(fd[0]); // close read end of file descriptor
		

		// Continue to read from source files until no bytes are read, and 
		// write onto write end of file descriptor. 
		while ((bytes_read = fread(buffer,1,sizeof(buffer),fptr)) > 0 ) { 
			write(fd[1], buffer , bytes_read);
		}


		// Close source file and write end of file descriptor 
		fclose(fptr); 
		close(fd[1]); 

	
		
	}

	

	return 0; 
}
