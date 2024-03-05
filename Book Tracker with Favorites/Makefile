# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab3.zip lab3

# this target is the .zip file that must be submitted to Carmen
lab3.zip: Makefile lab3.c
	zip lab3 lab3.c lab3.h Makefile

# this target is the bit cipher executable that requires redirected stdin
lab3: lab3.o
	gcc lab3.o -o lab3

# this target is the dependency for bit_encode1
lab3.o: lab3.c
	gcc -std=c99 -pedantic -g -c -o lab3.o lab3.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o lab3 lab3.zip
