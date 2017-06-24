/*
Input Format

The first line contains an integer, t,
denoting the number of trips to the ice cream parlor.

The 3t subsequent lines describe all of Sunny and Johnny's
trips to the parlor; each trip is described as follows:

The first line contains m (dollars).
The second line contains n (flavors).
The third line contains n space-separated integers denoting the cost of each
respective flavor. The  integer corresponding to the cost, c[i], for the ice cream
with ID number i (where 1<=i<=n).

It is guaranteed that there will always be a unique solution.

Output Format
Print two space-separated integers denoting the respective ID numbers
for the flavors they choose to purchase, where the smaller ID is printed first
and the larger ID is printed second. Recall that each ice cream flavor has a unique
ID number in the inclusive range from 1 to n.

Sample Input:
2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output:
1 4
1 2
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *printFlavors(int dollars, int count, int *flavors){
  int *indexes = malloc(2 * sizeof(int));
  for(int i = 0; i < count; i++){
    int fa = flavors[i];
    for(int j = (i+1); j < count; j++){
      int fb = flavors[j];
      if((fa + fb) == dollars){
        indexes[0] = i + 1;
        indexes[1] = j + 1;
        return indexes;
      }
    }
  }
  return indexes;
}

int main() {
  int iterations;
  scanf("%d", &iterations);
  int *allResults = malloc(iterations * 2 * sizeof(int));
  int arIdx = 0;
  for(int i = 0; i < iterations; i++){
    int dollars, flavor_count;
    scanf("%d", &dollars);
    scanf("%d", &flavor_count);
    int *flavors = malloc(sizeof(int) * flavor_count);
    for(int j = 0; j < flavor_count; j++){
      scanf("%d", &flavors[j]);
    }
    int *results = printFlavors(dollars, flavor_count, flavors);
    allResults[arIdx] = results[0];
    allResults[arIdx + 1] = results[1];
    free(flavors);
    free(results);
    arIdx = arIdx + 2;
  }
  for(int i = 0; i < (iterations * 2); i = i + 2){
    printf("%d %d\n", allResults[i], allResults[i + 1]);
  }
  return 0;
}
