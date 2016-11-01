all: project

project: wc.o 
	gcc wc.o -o project

wc.o: wc.c functions.h
	gcc -c wc.c

clean:
	rm -rf *o project
