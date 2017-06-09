#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *tripCompare(int *trips){
  int *output = calloc(sizeof(int) * 2, sizeof(int));
  for(int i =0; i < 3; i++){
    int valA = *(trips + i);
    int valB = *(trips + i + 3);
    if(valA > valB){
      *(output) = *(output) + 1;
    }else if(valB > valA){
      *(output + 1) = *(output + 1) + 1;
    }
  }
  return output;
}

int main(){
  int tripsCount = 2;
  int valueCount = 3;
  int elementCount = tripsCount * valueCount;
  int *trips = malloc(sizeof(int) * elementCount);
  for(int i = 0; i < elementCount; i++){
    scanf("%i", &trips[i]);
  }
  int *output = tripCompare(trips);
  printf("%d %d\n", *(output), *(output + 1));
  return 0;
}
