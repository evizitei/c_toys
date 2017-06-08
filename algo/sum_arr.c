#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arraySum(int size, int* p){
  int total = 0;
  for(int i = 0; i < size; i++){
    total = total + *(p + i);
  }
  return total;
}

int main(){
  int size;
  scanf("%i", &size);
  int *values = malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++){
    scanf("%i", &values[i]);
  }
  int output = arraySum(size, values);
  printf("%d\n", output);
  return 0;
}
