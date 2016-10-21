#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "array.h"

extern int errno;
static inline int Random(int n)
{
		
	return rand()/ (RAND_MAX/n + 1);
}
static int write_pbm(char **M, int m, int n, char *outfile){
	int errnum;

	FILE *f;
	f = fopen(outfile,"wb");
	if(f == NULL){
		errnum = errno;
		fprintf(stderr,"Value of errno: %d\n",errno);
		perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
		return 0;
	}

	fprintf(f,"%s","P1\n");
	fprintf(f, "%d ", m);
	//fprintf(f, "%s\n","\n");
	fprintf(f, "%d\n", n);
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			fprintf(f,"%d",M[i][j]);
		}
		fprintf(f,"%s","\n");
	}
	//fprintf(f, "%d\n",m);
	//fprintf(f, "%d\n",n );
	fclose(f);
	return 1;

}
static char **make_random_matrix(int m, int n, double f){

	char **M;
	int i, j ,k;
	make_matrix(M, m, n);
	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
			M[i][j] = 0;
	k = 0;
	while(k < f*m*n){

		i = Random(m);
		j = Random(n);
		if(M[i][j] == 0){
			M[i][j] = 1;
			k++;
		}
	}	
	return M;
}
static void show_usage(char *progname){}
int main(int argc, char **argv)
{
	int m, n ,s; 		// array of m by n and the seed number s for generating random number
	double f; 		// the file ratio 
	char **M; 		// pointer to 2d array containing bitmap data 
	char *outfile; 		// output bmp file
	char *endptr; 		// using in strtol for marking the end of string integer(null)
	int status = EXIT_FAILURE;
	if(argc != 6){
		show_usage(argv[0]);
		return EXIT_FAILURE;
	}
	m = strtol(argv[1], &endptr, 10);
	if(*endptr != '\0' || m < 1){
		show_usage(argv[0]);
		return status;
	}
	n = strtol(argv[2], &endptr, 10);
	if(*endptr != '\0' || n < 1){
		show_usage(argv[0]);
		return status;
	}
	s = strtol(argv[3], &endptr, 10);
	if(*endptr != '\0' || s < 1){
		show_usage(argv[0]);
		return status;
	}

	f = strtod(argv[4], &endptr);
	if(*endptr != '\0' || f < 0 || f > 1){
		show_usage(argv[0]);
		return status;
	}
	outfile = argv[5];

	srand(s);
	M = make_random_matrix(m, n, f);
	if(write_pbm(M, m, n, outfile) == 1)
		status = EXIT_SUCCESS;
	free_matrix(M);
	return status;
}
