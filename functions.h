#include<math.h>
#include<float.h>
void populate_arr(double **A, int len_x, int len_y){

 int i, j;
 for(i=0; i<len_x; i++){
  for(j=0; j<len_y; j++){
   A[i][j] = 1.0*i + 1.0*j;
  }
 }
}

void print_to_file(double **A, int format_flag, int nx, int ny){
 FILE *fptr;
 char fname[100];
 int i, j;

 if (format_flag == 0){

  sprintf(fname, "array_{%06d}_asc.out", nx);
  fptr = fopen(fname, "w");

  for(i=0; i<nx; i++){
   for(j=0; j<ny; j++){

     if(j==0)
      fprintf(fptr, "%.15e", A[i][j]);
     else
      fprintf(fptr, " %.15e", A[i][j]);
      }
      fprintf(fptr, "/n");
    }
   }

 if (format_flag == 1){

  sprintf(fname, "array_{%06d}_bin.out", nx);
  fptr = fopen(fname, "w");

  for(i=0; i<nx; i++){
    fwrite(A[i], sizeof(double), ny, fptr);
   }
 }
 fclose(fptr);
}

void min_max(double *arr,int len,double *min,double *max){
 *min = DBL_MAX;
 *max = -DBL_MAX;
 int i; 
 
 for(i=0; i<len; i++){
   if(arr[i] == 0){
    continue;
    }
   else if(arr[i] < *min) 
    *min = arr[i];
   if(arr[i] == 0)
    continue;  
   else if(arr[i] > *max)
    *max = arr[i];
 }
}

void matrix_vector_mult(double **A, double *arr, double *prod, int n){
 int i, j;
 
 for(i=0; i<n; i++){
  prod[i] = 0;
  for(j=0; j<n; j++){
   prod[i] = prod[i] + A[i][j]*arr[j];
  }
 // printf("%.6f\n", prod[i]);
 }
}

double check_eigen(double **A, double *arr, int len){
 double *prod = (double *)malloc(sizeof(double)*len);
 double *lamda = (double *)malloc(sizeof(double)*len);
 matrix_vector_mult(A, arr, prod, len);
 int i;
 double  max, min;
 
 for(i=0; i<len; i++){
  if(arr[i] == 0)
   lamda[i] = 0;
  else
   lamda[i] = prod[i]/arr[i];
 }
 
 min_max(lamda, len, &max, &min);
 if(fabs(min-max)<1e-6)
  return max;
 else
  return 0;
}

void read_sq_matrix(char *fname, double **mat, int n){
 FILE *fptr;
 fptr = fopen(fname, "r");
 int i, j;
 if (fptr == NULL)
  printf("Failed to read matrix.\n");
 
 for(i=0; i<n; i++){
  for(j=0; j<n; j++){
   fscanf(fptr, "%lf, ", &mat[i][j]);
  // printf("%.6lf\n", mat[i][j]);
  }
 }
 fclose(fptr);
}

void read_vector(char *fname, double *vec, int n){

 FILE *fptr;
 //printf("%s\n", fname);
 fptr = fopen(fname, "r");
 int i;
 if (fptr == NULL)
  printf("Failed to read vector.\n");
 
 for(i=0; i<n; i++){
    fscanf(fptr, "%lf,", &vec[i]);
    // printf("%.6f\n", vec[i]);
 }
 fclose(fptr);
}


