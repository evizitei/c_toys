/*
Sam's house has an apple tree and an orange tree that yield an abundance of fruit.
S is the start point and T is the end point of a region on a 1-d line that represents his house.
The apple tree is to the left of his house, and the orange tree is to its right.
You can assume the trees are located on a single point, where the apple tree is at point
a and the orange tree is at point b.

When a fruit falls from its tree, it lands d units of distance from its tree of
origin along the line. A negative value of d means the fruit fell d units to the tree's left,
and a positive value of means it falls d units to the tree's right.

Given the value of d for m apples and n oranges, can you determine how many apples
and oranges will fall on Sam's house (i.e., in the inclusive range [s,t] )?
Print the number of apples that fall on Sam's house as your first line of output,
then print the number of oranges that fall on Sam's house as your second line of output.

Input Format

The first line contains two space-separated integers denoting the respective values of s and t.
The second line contains two space-separated integers denoting the respective values of a and b.
The third line contains two space-separated integers denoting the respective values of m and n.
The fourth line contains m space-separated integers denoting the respective distances that each apple falls from point a.
The fifth line contains n space-separated integers denoting the respective distances that each orange falls from point b.

Output Format

Print two lines of output:

On the first line, print the number of apples that fall on Sam's house.
On the second line, print the number of oranges that fall on Sam's house.


Sample Input
7 11
5 15
3 2
-2 2 1
5 -6

Sample Output
1
1
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
  int houseLeft, houseRight;
  scanf("%d %d", &houseLeft, &houseRight);
  int aTree, oTree;
  scanf("%d %d", &aTree, &oTree);
  int aCount, oCount;
  scanf("%d %d", &aCount, &oCount);
  int *aDistances = malloc(sizeof(int) * aCount);
  int *oDistances = malloc(sizeof(int) * oCount);

  for(int i = 0; i < aCount; i++){
    scanf("%d", &aDistances[i]);
  }
  for(int i = 0; i < oCount; i++){
    scanf("%d", &oDistances[i]);
  }

  /* calculate strikes */
  int aStrikeCount = 0;
  int oStrikeCount = 0;
  int aThreshold = houseLeft - aTree;
  int oThreshold = houseRight - oTree;

  for(int i = 0; i < aCount; i++){
    if(aDistances[i] >= aThreshold){
      aStrikeCount++;
    }
  }

  for(int i = 0; i < oCount; i++){
    if(oDistances[i] <= oThreshold){
      oStrikeCount++;
    }
  }

  /* output results */

  printf("%i\n", aStrikeCount);
  printf("%i\n", oStrikeCount);
  return 0;
}
