/*
 * Adrian Pardo
 * I affirm that I wrote this program myself without any help form any
 * other people or sources from the internet.
 * This program is a command line absed mini calculator
 * Usage: minicalc [-a value] [-m value] [-x] value 
*/

#include <stdio.h>
#include <stdlib.h>

int debug = 0;

int main(int argc, char **argv)
{
	// Variables needed to keep track of flags and argument values
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int aflag=0, mflag=0, xflag=0;
	int aname = 0;
	int mname = 0;
	int arg;
	int result = 0;
	static char usage[] = "usage: %s [-a value] [-m value] [-x] value\n";

	// "a:dm:x" are the arguments that could be expected. Going through each, marking appropriate flags and assigning to variables.
	while ((c = getopt(argc, argv, "a:dm:x")) != -1)
		switch (c) {
		case 'd':
			debug = 1;
			break;
		case 'a':
			aflag = 1;
			aname = atoi(optarg);
			break;
		case 'm':
			mflag = 1;
			mname = atoi(optarg);
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
		}
	// If no value argument was entered 
	if (optind > argc - 1) {	
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	// If to many value arguments were entered
	else if (optind < argc - 1) {
		printf("To many arguments\n");
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} 
	else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	/* If -d is flagged. Let's see what we have */
	if (debug == 1) {
		printf("debug = %d\n", debug);
	        printf("aflag = %d\n", aflag);
	        printf("mflag = %d\n", mflag);
	        printf("xflag = %d\n", xflag);
	        printf("aname = %d\n", aname);
	        printf("mname = %d\n", mname);
		printf("value = %d\n", arg);
	}
	
	// Casting argument value into int
	arg =  atoi(argv[optind]);

	// Checks that all values are in the proper ranges. If not, spits out error with usage. 
	if (arg < 1 || arg > 100) {
		printf("Value must be between 1 and 100\n");
                fprintf(stderr, usage, argv[0]);
                exit(1);

	}
	if (aflag == 1 && (aname < 1 || aname > 500)) { 
		printf("aflag value must be between 1 and 500\n");
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	if (mflag == 1 && (mname < 1 || mname > 10)) {
		printf("mflag value must be between 1 and 10\n");
                fprintf(stderr, usage, argv[0]);
                exit(1);

	}
	// Doing calcualtions depending on flags. Order: Square, Multiplication, addition.
	if (xflag == 1) {
		arg *= arg;
	}
	if (mflag == 1) {
		arg *= mname; 
	}
	if (aflag ==1) {
		arg += aname;
	}
	// Print results from calculations.	
	printf("Result: %d\n", arg);
	exit(0);
}
