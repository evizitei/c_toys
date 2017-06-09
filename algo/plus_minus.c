/*
Given an array of integers, calculate which fraction of its elements are positive,
which fraction of its elements are negative,
and which fraction of its elements are zeroes, respectively.
Print the decimal value of each fraction on a new line.

Input Format

The first line contains an integer, N, denoting the size of the array.
The second line contains N space-separated integers describing an array of numbers.

Output Format

You must print the following  lines:

A decimal representing of the fraction of positive numbers in the array compared to its size.
A decimal representing of the fraction of negative numbers in the array compared to its size.
A decimal representing of the fraction of zeroes in the array compared to its size.

Sample Input
6
-4 3 -9 0 4 1

Sample Output
0.500000
0.333333
0.166667
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double *signFractions(int size, int *elements){
  double posCount = 0;
  double negCount = 0;
  double zerCount = 0;
  for(int i = 0; i < size; i++){
    int value = *(elements + i);
    if(value > 0){
      posCount += 1.0;
    }else if(value < 0){
      negCount += 1.0;
    }else{
      zerCount += 1.0;
    }
  }
  double *fractions = malloc(sizeof(double) * 3);
  *(fractions) = (posCount / size);
  *(fractions + 1) = (negCount / size);
  *(fractions + 2) = (zerCount / size);
  return fractions;
}

int main(){
  int size;
  scanf("%i", &size);
  int *input = malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++){
    scanf("%i", &input[i]);
  }
  double *output = signFractions(size, input);
  for(int i = 0; i < 3; i++){
    printf("%f\n", *(output + i));
  }
  return 0;
}
