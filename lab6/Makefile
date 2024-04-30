#BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL
#OF THE WORK TO DETERMINE THE ANSWERS FOUND WITHIN THIS FILE MYSELF WITH
#NO ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
#OR ONE OF OUR UNDERGRADUATE GRADERS. . I UNDERSTAND THAT TO DO OTHERWISE
#IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY
#comments in makefile must start with 

#all means all targets currently defined in this file
all: lab6.zip lab6

# this target is the .zip file that must be submitted to Carmen
lab6.zip: lab6main.c lab6.s Makefile
	zip lab6 zip Makefile lab6main.c lab6.s

# # this targets the lab6 executable
lab6: lab6.s lab6main.c
	gcc lab6.s lab6main.c -o lab6

# this target deletes all files produced from the Makefile so that a completely new compile of all items is required
clean:
	rm -rf lab6 lab6.zipi
