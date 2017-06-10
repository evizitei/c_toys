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

2082
1960
*/

#include <stdlib.h>
#include <stdio.h>

long strikeCount(long hLeft, long hRight, long treePos, long *distances, long fruitCount){
  long count = 0;
  if(treePos < hLeft){
    long threshold = hLeft - treePos;
    long outerThreshold = hRight - treePos;
    for(int i = 0; i < fruitCount; i++){
      if(distances[i] >= threshold && distances[i] <= outerThreshold){
        count++;
      }
    }
    return count;
  }else if(treePos > hRight){
    long threshold = hRight - treePos;
    long outerThreshold = hLeft - treePos;
    for(int i = 0; i < fruitCount; i++){
      if(distances[i] <= threshold && distances[i] >= outerThreshold){
        count++;
      }
    }
    return count;
  }else{
    printf("invalid input...%ld %ld %ld", hLeft, hRight, treePos);
    return -1;
  }
}

int main(){
  long houseEdgeA, houseEdgeB;
  long houseLeft, houseRight;
  scanf("%ld %ld", &houseEdgeA, &houseEdgeB);
  if(houseEdgeB > houseEdgeA){
    houseLeft = houseEdgeA;
    houseRight = houseEdgeB;
  }else{
    houseLeft = houseEdgeB;
    houseRight = houseEdgeA;
  }
  long aTree, oTree;
  scanf("%ld %ld", &aTree, &oTree);
  long aCount, oCount;
  scanf("%ld %ld", &aCount, &oCount);
  long *aDistances = malloc(sizeof(long) * aCount);
  long *oDistances = malloc(sizeof(long) * oCount);

  for(int i = 0; i < aCount; i++){
    scanf("%ld", &aDistances[i]);
  }
  for(int i = 0; i < oCount; i++){
    scanf("%ld", &oDistances[i]);
  }

  /* calculate strikes */
  long aStrikeCount = strikeCount(houseLeft, houseRight, aTree, aDistances, aCount);
  long oStrikeCount = strikeCount(houseLeft, houseRight, oTree, oDistances, oCount);

  /* output results */

  printf("%li\n", aStrikeCount);
  printf("%li\n", oStrikeCount);
  return 0;
}
