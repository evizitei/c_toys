/*
John's clothing store has a pile of  loose socks where each sock  is labeled with
an integer, , denoting its color. He wants to sell as many socks as possible,
but his customers will only buy them in matching pairs. Two socks,  and ,
are a single matching pair if .

Given  and the color of each sock, how many pairs of socks can John sell?

Sample Input
9
10 20 20 10 10 30 50 10 20

Sample Output
3
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sockMerchant(int n, int* ar) {
  bool singles[102] = {false};
  int matchCount = 0;
  for(int i = 0; i < n; i++){
    int color = ar[i];
    if(singles[color]){
      matchCount++;
      singles[color] = false;
    }else{
      singles[color] = true;
    }
  }
  return matchCount;
}

int main() {
    int n;
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = sockMerchant(n, ar);
    printf("%d\n", result);
    return 0;
}
