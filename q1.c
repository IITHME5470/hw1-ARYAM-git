#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

int main(){

 int format_flag; format_flag = 0;
 int n, i, j;
 FILE *fptr;
 fptr = fopen("input.in", "r");
 if(fptr == NULL)
  printf("Error opening file.\n");
 
 fscanf(fptr, "%d", &n);
 
 double **A = (double **)malloc(sizeof(double*)*n);
 
 for(i=0; i<n; i++){
  A[i] = (double *)malloc(sizeof(double)*n);
 }
 
 populate_arr(A, n, n);
 print_to_file(A, format_flag, n, n);

 for(i=0; i<n; i++){
  free(A[i]);
 }
 free(A);
 fclose(fptr); 
return 0;
}

