#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

int main(){

 int n, i, j;
 FILE *fptr;
 char fname[100], vname[100];
 char *mname = malloc(sizeof(char)*100);
 int num_vec = 4;
 double eig;  

 fptr = fopen("input.in", "r");
 if(fptr == NULL)
  printf("Error opening file.\n");

 fscanf(fptr, "%d", &n);
 fclose(fptr);
 double **A = (double **)malloc(sizeof(double*)*n);

 for(i=0; i<n; i++){
  A[i] = (double *)malloc(sizeof(double)*n);
 }
 
 sprintf(mname, "mat_%06d.in", n);
 // printf("%s\n", mname); 
 read_sq_matrix(mname, A, n); 
 
 for(i=0; i<num_vec; i++){
  double *vec = (double*)malloc(sizeof(double)*n);
  sprintf(vname, "vec_%06d_%06d.in", n, (i+1));
  read_vector(vname, vec, n);
  eig = check_eigen(A, vec, n);
  
  if(eig==0)
   printf("%s : Not an eigenvector.\n", vname);
  else
   printf("%s : Yes : %.6lf \n", vname, eig); 
 free(vec);
 }
 
 for(i=0; i<n; i++){
  free(A[i]);
 }
 free(A);
 return 0;
}
