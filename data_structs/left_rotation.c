/*
Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* i' = i - (l % n) where i' is target index, i is source index, l is rotations,
and n is array size */
int main() {

  int size, rotations;
  scanf("%d %d", &size, &rotations);
  int outArr[size];
  int offset = (rotations % size);
  for(int i = 0; i < size; i++){
    int val;
    scanf("%d", &val);
    int targetI = i - offset;
    if(targetI < 0){
      targetI = size + targetI;
    }
    outArr[targetI] = val;
  }
  for(int i = 0; i  < size; i++){
    printf("%d ", outArr[i]);
  }
  printf("\n");
  return 0;
}
