/*
We define an hourglass in  to be a subset of values with indices falling in
this pattern in 's graphical representation:

a b c
  d
e f g

An hourglass sum is the sum of an hourglass' values.

Task
Given a 6x6 matrix (which has 16 hourglasses),
calculate the hourglass sum for every hourglass in matrix A,
then print the maximum hourglass sum.
*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sumHourglass(int r, int c, int arr[][6]){
  int sum = 0;
  for(int i = r; i <= r+2; i++){
    for(int j = c; j <= c+2; j++){
      if(i == (r+1)){
        if(j == (c+1)){
          sum = sum + arr[i][j];
        }else{
          //hourglass hole, no-op
        }
      }else{
        sum = sum + arr[i][j];
      }
    }
  }
  return sum;
}

int calculateMaxHourglass(int rows, int cols, int arr[][6]){
  int max = 0;
  bool maxSet = false;
  for(int r = 0; r < rows - 2; r++){
    for(int c = 0; c < cols - 2; c++){
      int sum = sumHourglass(r, c, arr);
      if(!maxSet || sum > max){
        max = sum;
        maxSet = true;
      }
    }
  }
  return max;
}

int main(){
    int arr[6][6];
    int rows = 6;
    int cols = 6;
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    int maxHourglassSum = calculateMaxHourglass(rows, cols, arr);
    printf("%d\n", maxHourglassSum);
    return 0;
}
