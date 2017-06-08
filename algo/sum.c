#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sum(int x, int y){
  return x + y;
}

int main(){
  int stdin1, stdin2;
  scanf("%d %d", &stdin1, &stdin2);
  int outTarget;
  outTarget = sum(stdin1, stdin2);
  printf("%d", outTarget);
  return 0;
}
