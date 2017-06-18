#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* solve(int year){
  char *yearString = malloc(sizeof(char) * 5);
  char *dateString;
  sprintf(yearString, "%d", year);
  if(year == 1918){
    dateString = "26.09.";
  }else if(year <= 1917){
    if(year % 4 == 0){
      dateString = "12.09.";
    }else{
      dateString = "13.09.";
    }
  }else if(year >= 1919){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
      dateString = "12.09.";
    }else{
      dateString = "13.09.";
    }
  }

  char *outString = malloc(sizeof(char) * 11);
  strcpy(outString, dateString);
  strcat(outString, yearString);
  return outString;
}

int main() {
    int year;
    scanf("%d", &year);
    int result_size;
    char* result = solve(year);
    printf("%s\n", result);
    return 0;
}
