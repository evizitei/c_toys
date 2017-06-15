/*
You are given an array of n integers, a[1] to a[n-1], and a positive integer, k.
Find and print the number of i, j pairs where i < j and a[i] + a[j] is divisible by k.

Input Format

The first line contains 2 space-separated integers, n and k, respectively.
The second line contains n space-separated integers describing the respective
values of a[0] to a[n-1].

Output Format

Print the number of (i,j) pairs where i < j and a[i] + a[j] is evenly divisible
by k.

Sample Input
6 3
1 3 2 6 1 2

Sample Output
5
*/
#include <stdio.h>
#include <stdlib.h>

int countDivisibleSums(int n, int *values, int k){
  int solutionCount = 0;
  for(int i = 0; i < n; i++){
    int iVal = values[i];
    for(int j = (i + 1); j < n; j++){
      int jVal = values[j];
      if((iVal + jVal) % k == 0){
        solutionCount++;
      }
    }
  }
  return solutionCount;
}

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  int *values = malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++){
    scanf("%d", &values[i]);
  }
  int result = countDivisibleSums(n, values, k);
  printf("%d\n", result);
  return 0;
}
