#include <errno.h>
#include <stdio.h>

/* wc file */
/* no. of lines in a file */
int wc_lines(char *file){
	FILE *fp;
	int c, count;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file: ");
		return errno;
	}

	c = fgetc(fp);
	while(c != EOF){
		if(c == '\n')
			count = count + 1;
		c = fgetc(fp);
	}
	fclose(fp);
	printf("%d ", count);
}

/* wc file */
/* no. of words in a file */
int wc_words(char *file){
	FILE *fp;
	int c, count = 0;
	fp = fopen(file, "r");
	if(fp == NULL){	
		perror("Can't open file: ");
		return errno;
	}

	while((c = (fgetc(fp))) != EOF){
		if(c == ' ')
			count++;
		if(c == '\t')
			count++;
	}
	printf("%d ", count + 1);
	fclose(fp);
}

/* wc file */
/* no. of bytes in a file */
int wc_bytes(char *file){
	FILE *fp;
	int len;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file: ");
		return errno;
	}

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	printf("%d ", len);
	fclose(fp);
}

/* wc -m file */
/* no. of characters in a file */
int wc_chars(char *file){
	FILE *fp;
	int c, cnt = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file: ");
		return errno;	
	}

	while((c = fgetc(fp)) != EOF)
		++cnt;
	printf("%d ", cnt);
	fclose(fp);
}

/* wc -L file */
/* no. of characters in longest line of file */
int wc_maxline(char *file){
	FILE *fp;
	int c, n = 1, count = 0, i = 0, j, nl = 0, max, tab;
	int store[1024];

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file: ");
		return errno;
	}

	while((c = fgetc(fp)) != EOF){
		if(c != '\n')
			++count;
		else if(c == '\n'){
			++nl;
			store[i++] = count;
			count = 0;
		}
		if(c == '\t')
			count = count + 7;
	}

	max = store[0];
	for(j = 0; j < nl; j++){
		if(max < store[j])
			max = store[j];

		//printf("%d\n", store[j]);
	}
	printf("%d ", max);
	fclose(fp);
}

/* With no file, or when file is -, read standard input */
void wc_stdinput(){
	char ip[128];

	while(1)
		scanf("%s", ip);
}

int help(){
	FILE *fp;
	int c;

	fp = fopen("wc_help", "r");
	if(fp == NULL){
		perror("can't open wc_help file: ");
		return errno;
	}
	
	while((c = fgetc(fp)) != EOF)
		printf("%c", c);
	
	fclose(fp);

}
