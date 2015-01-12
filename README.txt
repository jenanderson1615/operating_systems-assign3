Jen Anderson
anderjen@onid.oregonstate.edu
CS311-400
Homework 3
README.txt

*** Please see Instructions.pdf for full assignment instructions.

This program outputs section of .txt documents depending on command line arguments.
There are 2 .txt files included in the file to practice with.  The command
line argument options are as follows:

-v    		Verbose = show the command line arguments given
-f filename	Filename = .txt document to use
-l len		Length of bytes read: number of bytes to write to console for o
			and O options. 
-o offset1	Offset from beginning of file
-O offset2	Offset from current position in file
-e elen		Number of bytes from the end of the file that will be read and 
			written to the console


Command line arguments can be given in any order.  The following is an example:
./homework3 -f iliad.txt -o 4914 -O -372 -l 372 -e 500 -v
