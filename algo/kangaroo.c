/*
There are two kangaroos on an x-axis ready to jump in the positive direction
(i.e, toward positive infinity).
The first kangaroo starts at location x[1] and moves at a rate of v[1] meters per jump.
The second kangaroo starts at location x[2] and moves at a rate of v[2] meters per jump.
Given the starting locations and movement rates for each kangaroo,
can you determine if they'll ever land at the same location at the same time?


Input Format

A single line of four space-separated integers denoting the respective values of
 x[1], v[1], x[2], and v[2].

Constraints

0 <= x[1] <= x[2] <= 10000
1 <= v[1] <= 100000
1 <= v[2] <= 100000

Output Format
Print YES if they can land on the same location at the same time;
otherwise, print NO.

Sample Input
0 3 4 2

Sample Output
YES

Sample I/0 2:
43 2 70 2
NO
*/
#include <stdio.h>

int main(){
  int x1, v1, x2, v2;
  scanf("%i %i %i %i", &x1, &v1, &x2, &v2);

  if(x1 == x2){
    printf("YES\n");
    return 0;
  }

  if(v1 <= v2){
    printf("NO\n");
    return 0;
  }

  int deltaX = x2 - x1;
  int deltaV = v1 - v2;
  if((deltaX % deltaV) == 0 && ((deltaX / deltaV) >= 0)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }

  return 0;
}
