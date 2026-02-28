/**
 * filecopy.c
 * 
 * This program copies files using a pipe.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
	if (argc != 2) { 
		print("Only 2 arguments alllowed. source - destination.");
		return 1;



	return 0; 
}
