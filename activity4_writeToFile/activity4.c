/*
 * Adrian Pardo
 * I affirm that I wrote this program myself without any help form any
 * other people or sources from the internet.
 * This program is a command line absed mini calculator
 * Usage: minicalc [-a value] [-m value] [-x] value 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debug = 0;

int main(int argc, char **argv) {
	// Variables needed to keep track of flags and argument values
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int lflag=0, uflag=0, fflag=0;
	char *sname = "default_sname", *fname;
	static char usage[] = "usage: %s [-lu] [-f filename]\n";

	// "a:dm:x" are the arguments that could be expected. Going through each, marking appropriate flags and assigning to variables.
	while ((c = getopt(argc, argv, "luf:d")) != -1)
		switch (c) {
		case 'd':
			debug = 1;
			break;
		case 'l':
			lflag = 1;;
			break;
		case 'u':
			uflag = 1;
			break;
		case 'f':
			fflag = 1;
			fname = optarg;
			break;
		case '?':
			err = 1;
			break;
		}
	
	// If no value argument was entered 
	/*if (optind >= argc - 1) {	
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}*/
	// If to many value arguments were entered
	if (optind <= argc - 3) {
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
	        printf("lflag = %d\n", lflag);
	        printf("uflag = %d\n", uflag);
	        printf("fflag = %d\n", fflag);
	        printf("fname = %s\n", fname);
	}
	

	// Doing calcualtions depending on flags. Order: Square, Multiplication, addition.
	char name[] = "Adrian Pardo";
        if (uflag ==1) {
                int i =0;
                while( name[i] ) {
                        name[i] = toupper(name[i]);
                        i++;
                }
        }
	if (lflag == 1) {
		int i =0;
		while( name[i] ) {
     			name[i] = tolower(name[i]);
     		 	i++;
  	 	}
	}
	if (fflag == 1) {
		FILE *f;
		f = fopen(fname, "w");
		if (f == NULL)	{
    			printf("Error opening file!\n");
    			exit(1);
		}
		fprintf(f, "%s\n", name);
		fclose(f);
	}
	else {
		printf("%s\n", name);
	}
	exit(0);
}
