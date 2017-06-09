/*
Given a square matrix of size N, calculate the absolute difference
between the sums of its diagonals.

*Input Format*
The first line contains a single integer, N. The next N lines denote the
matrix's rows, with each line containing
space-separated integers describing the columns.


*Output Format*
Print the absolute difference between the two sums of the
matrix's diagonals as a single integer.

Sample Input

3   // <- size of side of square matrix
11 2 4
4 5 6
10 8 -12


Sample Output

15

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int computeDiagonalDiff(int sideSize, int *matrix){
  int diff = 0;
  for(int i = 0; i < sideSize; i++){ // row index
    int colAindex = i;
    int colBindex = sideSize - (i + 1);
    int diagA_val = *(matrix + (sideSize * i) + colAindex);
    int diagB_val = *(matrix + (sideSize * i) + colBindex);
    diff = (diff + diagA_val - diagB_val);
  }
  if(diff < 0){
    diff = diff * -1;
  }
  return diff;
}

int main(){
  int N;
  scanf("%i", &N);
  int matrixSize = N * N;
  int *matrix = malloc(sizeof(int) * matrixSize);
  for(int i = 0; i < matrixSize; i++){
    scanf("%i", &matrix[i]);
  }
  int output = computeDiagonalDiff(N, matrix);
  printf("%d\n", output);
  return 0;
}
