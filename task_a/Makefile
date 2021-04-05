#!/bin/sh
export LD_LIBRARY_PATH=.

all: main1_1 main1_2 main1_3

# Subtask 1:
main1_1: main1_1.o hello_ariel.o
	gcc -Wall -g -o main1_1 main1_1.o hello_ariel.o

main1_1.o: main1_1.c hello_ariel.h
	gcc -c -Wall -g main1_1.c 

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc -c -g -Wall hello_ariel.c 


#Subtask 2:
# main1_2: main1_2.o
# 	gcc -Wall -g -o main1_2 main1_2.o hello_ariel.so

# main1_2.o: main1_2.c lib
# 	gcc -c -Wall -g main1_2.c 

# lib: hello_ariel.c hello_ariel.h
# 	gcc -o hello_ariel.so -shared -fPIC hello_ariel.h hello_ariel.c
main1_2: lib hello_ariel.h
	gcc -Wall -g main1_2.c -L. -l Hello -o main1_2

lib: hello_ariel.c 
	gcc -o libHello.so -shared -fPIC hello_ariel.c 


# hello_ariel.o: hello_ariel.c hello_ariel.h
# 	gcc -c -g -Wall hello_ariel.c 



# Subtask 3:
main1_3: main1_3.o lib
	gcc main1_3.c -L. -ldl libHello.so -o main1_3

# hello_ariel.so: hello_ariel.c	# hello_ariel.c/.h are needed to compile the lib
# 	gcc -o lib_hello_ariel.so -shared -fPIC hello_ariel.c

clean:
	rm -f main1_1 main1_2 main1_3 *.o *.so
