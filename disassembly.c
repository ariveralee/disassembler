#include <stdlib.h> 
#include <stdio.h>
#include "DisFunctions.h"

#define FILE_NOT_FOUND 	 1
#define FILE_ERROR 		-1
#define EXIT_SUCCESS 	 0

int main(int argc, char **argv) {
	//Take command line arguments for file to be read from user
	if (argc < 2) {
		printf("You must provide a machine code file to read. \n");
		return 1;
	}
	// if we made it here, we have a file. Let's try to open it
	char *filename = argv[1];
	FILE *fp = fopen (filename, "r");

	if (fp == NULL) {
		printf("Could not open the file provided, check the format. \n");
		return -1;
	}

	// let's get the line count.
	int lineCount = 0;
	int cur;

	while ((cur = fgetc(fp)) != EOF) {
		if (cur == '\n') {
			lineCount++;
		}
	}

	// now that we have the linecount, we know how much we need to store.
	int addr[lineCount];
	char *addrString[lineCount];
	int opCode[lineCount];
	char *opCodeStr[lineCount];

	// rewind the the file pointer and lets read in dat info.
	rewind(fp);
	int i;
	for (i = 0; i < lineCount; i++) {
		fscanf (fp, "%d %d", &addr[i], &opCode[i]);
	}

	// we have the ints, let's get the strings.
	rewind(fp);
	int j;
	for (j = 0; j < lineCount; j++) {
		addrString[j] = malloc (sizeof(char) * 3);
		opCodeStr[j] = malloc (sizeof(char) * 4);
		fscanf (fp, "%s %s", addrString[j], opCodeStr[j]);
	}
	//close the file stream
	fclose(fp);

	// char and int array for addresses and instructions to be done.
	int *instrAddress[lineCount];
	char *inst[lineCount];


	assembly(addr, opCode, inst, instrAddress, lineCount);

	printAssem(addrString, opCodeStr, inst, instrAddress, lineCount);
	
	return 0;
}
