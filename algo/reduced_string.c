/*
Remove all double letters until there are no more double letters to remove:

If the final string is empty,
print Empty String; otherwise,
print the final non-reducible string.

Sample Input
aaabccddd

Sample Output
abd
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* super_reduced_string(char* source){
  char *reduced = (char *)malloc(101 * sizeof(char));
  int rIdx = 0;
  int sIdx = 0;
  reduced[0] = '\0';
  char curChar = source[sIdx];
  while(curChar != '\0'){
    if(curChar == source[sIdx + 1]){ // this is a double, skip past it
      sIdx = sIdx + 2;
    }else{
      if(rIdx > 0 && reduced[rIdx - 1] == curChar){ // about to create a double, backup
        reduced[rIdx] = '\0';
        rIdx--;
      }else{
        reduced[rIdx] = curChar;
        reduced[rIdx+1] = '\0';
        rIdx++;
      }
      sIdx++;
    }
    curChar = source[sIdx];
  }
  if(rIdx == 0){
    return "Empty String";
  }
  return reduced;
}

int main() {
    char* s = (char *)malloc(101 * sizeof(char));
    scanf("%s", s);
    int result_size;
    char* result = super_reduced_string(s);
    printf("%s\n", result);
    return 0;
}
