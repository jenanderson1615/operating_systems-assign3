/*******************************
Jen Anderson
anderjen@onid.oregonstate.edu
CS311-400
Homework 3
Unix File I/O Homework
*******************************/

#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	char *myFile;
	int length;
	int offset1;
	int offset2;
	int inputFD;
	int numread;
	int opt;
	int verbose = 0;
	int elen;
	char *buf;

	opt = getopt (argc, argv, "vf:l:o:O:e:");
	while (opt != -1)
	{
		switch(opt)
		{
			case 'v':
				verbose = 1;
				break;
			case 'f':
				//Store the file name to be used in sequence later
				myFile = optarg;
				break;	
			case 'l':
				length = atoi(optarg);
				break;
			case 'o':
				offset1 = atoi(optarg);
				break;
			case 'O':
				offset2 = atoi(optarg);
				break;
			case 'e':
				elen = atoi(optarg);
				break;
		}
		opt = getopt (argc, argv, "vf:l:o:O:e:");
	}

	if(verbose == 1)
	{
		printf ("\nFile: %s\n", myFile);
		printf ("Length: %i\n", length);
		printf ("Offset1: %i\n", offset1);
		printf ("Offset2: %i\n", offset2);
	}		

	buf = malloc(length);

	//Open a file in file system
	inputFD = open(myFile, O_RDONLY);
	
	//test
	if(inputFD == -1)
	{
		perror("Can't open input file");
		exit(-1);
	}

	printf("\n--------------------------------------------\n");
	printf("Offset1:\n--------------------------------------------\n\n");
	//read from offset1 from begging of file to len
	if(offset1 < 0)
	{
		printf("The offset1 value must be above 0.\n");
	}
	else		
	{
		lseek(inputFD, offset1, SEEK_SET);
		numread = read(inputFD, buf, length);
		buf[numread] = '\0';
		write(1, buf, length);
		printf("\n");
	}

	printf("\n--------------------------------------------\n");
	printf("Offset2:\n--------------------------------------------\n\n");

	//read from offset2 from current place to len
	lseek(inputFD, offset2, SEEK_CUR);
	numread = read(inputFD, buf, length);
	buf[numread] = '\0';
	write(1, buf, length);
	printf ("\n");

	printf("\n--------------------------------------------\n");
	printf("End Bytes:\n-----------------------------------------\n\n");

	//read from end of file to elen
	lseek(inputFD, -(elen), SEEK_END);
	numread = read(inputFD, buf, elen);
	buf[numread] = '\0';
	write(1, buf, elen);

	printf("\n");
	
	return 0;
}
