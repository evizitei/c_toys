#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int divCount(int n){
  int orderOfMagnitude = (n / 10) + 1;
  char *digits = calloc(orderOfMagnitude, sizeof(char));
  sprintf(digits, "%d", n);
  int count = 0;
  for(int i = 0; i < orderOfMagnitude; i++){
    char digit = digits[i];
    if(digit == '\0'){
      break;
    }else{
      int digitValue = digit - '0';
      if(digitValue != 0 && n % digitValue == 0){
        count++;
      }
    }
  }
  return count;
}

int main(){
    int t;
    scanf("%d",&t);
    int *inputs = malloc(sizeof(int) * t);
    for(int a0 = 0; a0 < t; a0++){
        int n;
        scanf("%d",&inputs[a0]);
    }

    for(int a0 = 0; a0 < t; a0++){
        int count = divCount(inputs[a0]);
        printf("%d\n", count);
    }
    return 0;
}
