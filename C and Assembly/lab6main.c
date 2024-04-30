// BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL
// OF THE WORK TO DETERMINE THE ANSWERS FOUND WITHIN THIS FILE MYSELF WITH
// NO ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS
// COURSE
// OR ONE OF OUR UNDERGRADUATE GRADERS. . I UNDERSTAND THAT TO DO
// OTHERWISE
// IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY
#include <stdio.h>

long sum( long a [], int count);  

int main(int argc, char **argv)
{


long a [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

printf("Main ..... call sum\n");
long result = sum(a, 10);
printf("The sum is: %ld\n", result);
printf("\ndone!\n");

  return 0;
}
