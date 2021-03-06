/*Consider a staircase of size 4:

   #
  ##
 ###
####

Observe that its base and height are both equal to , and the image is drawn using
# symbols

and spaces. The last line is not preceded by any spaces.

Write a program that prints a staircase of size .

Input Format

A single integer, , denoting the size of the staircase.

Output Format

Print a staircase of size  using # symbols and spaces.

Note: The last line must have  spaces in it.

Sample Input

6
Sample Output

     #
    ##
   ###
  ####
 #####
######

*/

#include <stdio.h>

int main(){
  int stairSize;
  scanf("%i", &stairSize);
  for(int i = 1; i <= stairSize; i++){
    for(int j = 1; j <= (stairSize - i); j++){
      printf(" ");
    }
    for(int k = 1; k <= i; k++){
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
