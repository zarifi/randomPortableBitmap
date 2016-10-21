/* The function defined here malloc_or_exit tries to allocate nbyte of memory to x. If it's succesful it returns
the address of the allocated memory but if the result of the malloc is NULL this function prints a detailed error message 
and exit the program.

Modified : Mohammad Hossein Zarifi
resourse used: Programming Projects in C for Students of Engineering, Science, and Mathematics by Rouben Rostamian

*/
#include <stdio.h>
#include "xmalloc.h"

void *malloc_or_exit(size_t nbytes, const char *file, int line)
{
	void *x;
	if((x = malloc(nbytes)) == NULL || nbytes == 0){
		fprintf(stderr, "%s:line %d: malloc() of %zu bytes failed\n", file, line, nbytes);
		exit (EXIT_FAILURE);
	} else
		return x;

}
