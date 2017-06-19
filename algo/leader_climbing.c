#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    int *scores = malloc(sizeof(int) * n);
    for(int scores_i = 0; scores_i < n; scores_i++){
       scanf("%d",&scores[scores_i]);
    }
    int m;
    scanf("%d",&m);
    int *alice = malloc(sizeof(int) * m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       scanf("%d",&alice[alice_i]);
    }
    /* populate the stack of scores */
    int *scoreStack = malloc(sizeof(int) * 200000);
    int posIndex = 1;
    int curScore = scores[0];
    scoreStack[0] = curScore;
    for(int rank_i = 1; rank_i < n; rank_i++){
      int leaderScore = scores[rank_i];
      if(leaderScore < curScore){
        curScore = leaderScore;
        scoreStack[posIndex] = curScore;
        posIndex++;
      }
    }
    /* step index back to now represent last score */
    posIndex--;

    /*walk back off the stack to find ranks*/
    for(int pos_i = 0; pos_i < m; pos_i++){
      int a_score = alice[pos_i];
      while(a_score > curScore && posIndex >= 0){
        posIndex--;
        curScore = scoreStack[posIndex];
      }
      if(a_score > curScore){
        printf("%d\n", 1);
      }else if(a_score < curScore){
        printf("%d\n", posIndex + 2);
      }else if(a_score == curScore){
        printf("%d\n", posIndex+1);
      }else{
        printf("ERROR!!!\n");
      }
    }
    return 0;
}
