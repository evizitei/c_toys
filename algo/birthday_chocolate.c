/*

Lily has a chocolate bar consisting of a row of n squares where each square
has an integer written on it. She wants to share it with Ron for his birthday,
which falls on month m and day d. Lily wants to give Ron a piece of chocolate
only if it contains m consecutive squares whose integers sum to d.

Given m, d, and the sequence of integers written on each square of Lily's
chocolate bar, how many different ways can Lily break off a piece of chocolate
to give to Ron?


Input Format

The first line contains an integer denoting n (the number of squares in the chocolate bar).
The second line contains n space-separated integers describing the respective values of s[i] (the numbers written on each consecutive square of chocolate).
The third line contains two space-separated integers describing the respective values of d (Ron's birth day) and m (Ron's birth month).


Print an integer denoting the total number of ways that Lily can give a piece of chocolate to Ron.

Sample Input
5
1 2 1 3 2
3 2

Sample Output
2


Sample Input 1
6
1 1 1 1 1 1
3 2

Sample Output 1
0

Sample Input 2
1
4
4 1

Sample Output 2
1
*/
#include <stdio.h>
#include <stdlib.h>

int chocoCombos(int n, int *chocVals, int target, int bracket_size){
  int count = 0;
  int current_sum = 0;
  for(int i = 0; i < bracket_size; i++){
    current_sum = current_sum + chocVals[i];
  }

  if(current_sum == target){
    count++;
  }

  for(int i = 1; i <= (n - bracket_size); i++){
    current_sum = ((current_sum - chocVals[i-1]) + chocVals[(i-1) + bracket_size]);
    if(current_sum == target){
      count++;
    }
  }
  return count;
}

int main(){
  int chocSize;
  scanf("%d", &chocSize);
  int *chocVals = malloc(sizeof(int) * chocSize);
  for(int i = 0; i < chocSize; i++){
    scanf("%d", &chocVals[i]);
  }
  int month, day;
  scanf("%d %d", &day, &month);
  int solutionCount = chocoCombos(chocSize, chocVals, day, month);
  printf("%d\n", solutionCount);
  return 0;
}
