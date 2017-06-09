#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long arraySum(int size, long* p){
  long total = 0;
  for(int i = 0; i < size; i++){
    total = total + *(p + i);
  }
  return total;
}

int main(){
  int size;
  scanf("%i", &size);
  long *values = malloc(sizeof(long) * size);
  for(int i = 0; i < size; i++){
    scanf("%li", &values[i]);
  }
  long output = arraySum(size, values);
  printf("%ld\n", output);
  return 0;
}
