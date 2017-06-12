/*

Consider two sets of positive integers, A and B. We say that a positive integer, x,
is between sets A and B if the following conditions are satisfied:

1) All elements in A are factors of x.
2) x is a factor of all elements in B.

Given A and B, find and print the number of integers (i.e., possible x's)
that are between the two sets.

Input Format

The first line contains two space-separated integers describing the respective
values of n (the number of elements in set A) and m  (the number of elements in set B).
The second line contains n distinct space-separated integers describing .
The third line contains m distinct space-separated integers describing .

Constraints
1 <= n,m <= 10
1 <= a[i] <= 100
1 <= b[i] <= 100

Output Format

Print the number of integers that are considered to be between A and B.

Sample Input
2 3
2 4
16 32 96

Sample Output
3
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


bool isMultipleOf(int* set, int setSize, int candidate){
  for(int i = 0; i < setSize; i++){
    if(candidate % set[i] != 0){
      return false;
    }
  }
  return true;
}

bool isFactorOf(int* set, int setSize, int candidate){
  for(int i = 0; i < setSize; i++){
    if(set[i] % candidate != 0){
      return false;
    }
  }
  return true;
}

int getTotalX(int a_size, int* a, int b_size, int* b){
    // Complete this function
    int maxA = 0;
    int minB = 10000;
    for(int i = 0; i < a_size; i++){
      if(a[i] > maxA){
        maxA = a[i];
      }
    }
    for(int i = 0; i < b_size; i++){
      if(b[i] < minB){
        minB = b[i];
      }
    }
    int count = 0;
    if(maxA > minB){
      return count;
    }

    int candidate = maxA;
    int threshold = (minB / 2) + 1;
    while(candidate <= minB){
      if(isMultipleOf(a, a_size, candidate) && isFactorOf(b, b_size, candidate)){
        count = count + 1;
      }
      candidate = candidate + maxA;
      if(candidate > threshold && candidate < minB){
        candidate = minB;
      }
    }
    return count;
}

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(int b_i = 0; b_i < m; b_i++){
       scanf("%d",&b[b_i]);
    }
    int total = getTotalX(n, a, m, b);
    printf("%d\n", total);
    return 0;
}
