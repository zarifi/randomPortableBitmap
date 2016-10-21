/* 
This the header for that contains macro functions responsible for creating and freeing generic-type vector and matrix.

Modified by: Mohammad Hossein Zarifi
Source: the book Programming Projects in C for students of Engineering, Science, and Mathematics by Rouben Rostamian
*/

/* this function creates a 2d array of any type, m: pointer to a pointer to store the address of the array, m and n are its dimensions*/
/* this function frees the allocated memory for created array*/
/* this function print a vector of generic type, 'fmt' is the format specifier and 'v' the address of the vector and 'n' is its size*/
/* prints the array 'a' with m by n dimensions */

#ifndef H_ARRAY_H
#define H_ARRAY_H
#include "xmalloc.h"
#define make_vector(v,n) ((v) = xmalloc((n) * sizeof *(v))) 
#define free_vector(v) do {free(v); v = NULL;} while(0)  
#define make_matrix(a, m, n) do{\
	size_t make_matrix_loop_counter;\
	make_vector(a,(m) + 1);\
	for(make_matrix_loop_counter = 0; make_matrix_loop_counter < (m); make_matrix_loop_counter++)\
		make_vector((a) [make_matrix_loop_counter], (n));\
	(a)[m] = NULL;\
} while(0)
#define free_matrix(a) do{  \
	if(a != NULL){\
		size_t make_matrix_loop_counter;\
		for(make_matrix_loop_counter = 0; (a) [make_matrix_loop_counter] != NULL; make_matrix_loop_counter++)\
			free_vector((a) [make_matrix_loop_counter]);\
		free_vector(a);\
		a = NULL;\
	}\
} while(0)

#define print_vector(fmt, v, n) do{\
	size_t print_vector_loop_counter;\
	for(print_vector_loop_counter = 0;print_vector_loop_counter < (n);print_vector_loop_counter++)\
		printf(fmt,(v)[print_vector_loop_counter]);\
	putchar('\n');\
} while(0)

#define print_matrix(a, m, n) do{\
	char format[] = "%f ";\
	size_t print_matrix_loop_counter;\
	for(print_matrix_loop_counter = 0;print_matrix_loop_counter < (m); print_matrix_loop_counter++)\
		print_vector(format,(a)[print_matrix_loop_counter],(n));\
}while(0)

#endif /* H_ARRAY_H */
