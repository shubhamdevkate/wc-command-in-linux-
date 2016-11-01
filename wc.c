#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	if(argc == 1){
		wc_stdinput();
	}
	else if(argc == 2){
		/* wc --help */
		if(strcmp(argv[1], "--help") == 0)
			help();
		else{
			printf(" ");
			wc_lines(argv[1]);
			wc_words(argv[1]);
			wc_bytes(argv[1]); 
			puts(argv[1]);
		}
	}
	else if(argc == 3){
		/* wc -l file */
		if(strcmp(argv[1], "-l") == 0){			// counts total number of lines
			wc_lines(argv[2]);
			puts(argv[2]);
		}
		/* wc -w file */
		else if(strcmp(argv[1], "-w") == 0){		// counts total number of words
			wc_words(argv[2]);
			puts(argv[2]);	
		}
		/* wc -c file */
		else if(strcmp(argv[1], "-c") == 0){
			wc_bytes(argv[2]);			// counts total number of bytes
			puts(argv[2]);			
		}
		/* wc -m file */
		else if(strcmp(argv[1], "-m") == 0){
			wc_chars(argv[2]);
			puts(argv[2]);
		}
		/* wc -L file */
		else if(strcmp(argv[1], "-L") == 0){		// counts characters in longest line
			wc_maxline(argv[2]);
			puts(argv[2]);
		}
	}

	return 0;
}
