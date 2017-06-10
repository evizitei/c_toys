/*
Given five positive integers, find the minimum and maximum values that can be
calculated by summing exactly four of the five integers. Then print the
respective minimum and maximum values as a single line of two space-separated long integers.

Input Format

A single line of five space-separated integers.

Output Format

Print two space-separated long integers denoting the respective minimum and
maximum values that can be calculated by summing exactly four of the five
integers. (The output can be greater than 32 bit integer.)

Sample Input

1 2 3 4 5

Sample Output

10 14
*/
#include <stdio.h>
#include <stdlib.h>

long *minMax(long *setOfFive){
  long sum = 0;
  for(int i = 0; i < 5; i++){
    sum = sum + *(setOfFive + i);
  }
  long min = sum;
  long max = 0;
  for(int i = 0; i < 5; i++){
    long candidate = sum - *(setOfFive + i);
    if(candidate > max){
      max = candidate;
    }
    if(candidate < min){
      min = candidate;
    }
  }
  long *output = malloc(sizeof(long) * 2);
  *(output) = min;
  *(output + 1) = max;
  return output;
}

int main(){
  long *numbers = malloc(sizeof(long) * 5);
  for(int i =0; i< 5; i++){
    scanf("%li", &numbers[i]);
  }
  long *result = minMax(numbers);
  printf("%li %li\n", *(result), *(result + 1));
}
