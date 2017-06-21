/*
A queen is standing on an  chessboard. The chessboard's rows are numbered from 1 to n,
going from bottom to top;
its columns are numbered from 1 to n, going from left to right.
Each square on the board is denoted by a tuple, (r, c),
describing the row, r, and column, c, where the square is located.

The queen is standing at position (rq, cq) and, in a single move,
she can attack any square in any of the eight directions (left, right, up, down,
or the four diagonals).

There are k obstacles on the chessboard preventing the queen from attacking any
square that has an obstacle blocking the the queen's path to it.

Given the queen's position and the locations of all the obstacles,
find and print the number of squares the queen can attack from her position at (rq, cq).

Sample Input 0
4 0
4 4

Sample Output 0
9
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int min(a, b){
  if(a < b){
    return a;
  }
  return b;
}

int *distancesToEdge(int initRow, int initCol, int boardSize){
  // one in each direction, starting with [0] (which is up), and proceeding clockwise
  // (up-left is last)
  int *distances = malloc(8*sizeof(int));
  distances[0] = boardSize - initRow; // up
  distances[1] = min(boardSize - initRow, boardSize - initCol);
  distances[2] = boardSize - initCol; // right
  distances[3] = min(boardSize - initCol, initRow - 1);
  distances[4] = initRow - 1; // down
  distances[5] = min(initRow - 1, initCol - 1);
  distances[6] = initCol - 1; // left
  distances[7] = min(boardSize - initRow, initCol - 1);
  return distances;
}

void updateMinDistances(int *dists, int rQueen, int cQueen, int rObstacle, int cObstacle){
  bool sameCol = (cQueen == cObstacle);
  bool sameRow = (rQueen == rObstacle);
  bool sameRDiag = (rQueen - rObstacle) == (cQueen - cObstacle);
  bool sameLDiag = (rQueen - rObstacle) == -1 * (cQueen - cObstacle);
  int distance;
  if(sameCol){
    /* check up down */
    if(rQueen > rObstacle){ // obstacle is down
      distance = (rQueen - rObstacle) - 1;
      if(distance < dists[4]){
        dists[4] = distance;
      }
    }else if (rQueen < rObstacle){ // obstacle is up
      distance = (rObstacle - rQueen) - 1;
      if(distance < dists[0]){
        dists[0] = distance;
      }
    }
  }else if(sameRow){
    /* check left right */
    if(cQueen > cObstacle){ //obstacle is left
      distance = (cQueen - cObstacle) - 1;
      if(distance < dists[6]){
        dists[6] = distance;
      }
    }else if(cQueen < cObstacle){ //obstacle is right
      distance = (cObstacle - cQueen) - 1;
      if(distance < dists[2]){
        dists[2] = distance;
      }
    }
  }else if(sameRDiag){
    /* check upright, down left */
    if(rQueen < rObstacle && cQueen < cObstacle){ // obstacle is up right
      distance = (rObstacle - rQueen) - 1;
      if(distance < dists[1]){
        dists[1] = distance;
      }
    }else if(rQueen > rObstacle && cQueen > cObstacle){ //obstacle is down left
      distance = (rQueen - rObstacle) - 1;
      if(distance < dists[5]){
        dists[5] = distance;
      }
    }
  }else if(sameLDiag){
    /* check upleft, down right */
    if(rQueen < rObstacle && cQueen > cObstacle){ // obstacle is up left
      distance = (rObstacle - rQueen) - 1;
      if(distance < dists[7]){
        dists[7] = distance;
      }
    }else if(rQueen > rObstacle && cQueen < cObstacle){ // obstacle is down right
      distance = (rQueen - rObstacle) - 1;
      if(distance < dists[3]){
        dists[3] = distance;
      }
    }
  }
}

int main(){
    long n;
    int k;
    scanf("%ld %d",&n,&k);
    int rQueen;
    int cQueen;
    scanf("%d %d",&rQueen,&cQueen);
    int *dir_dists = distancesToEdge(rQueen, cQueen, n);
    int attackCount = 0;

    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        scanf("%d %d",&rObstacle,&cObstacle);
        updateMinDistances(dir_dists, rQueen, cQueen, rObstacle, cObstacle);
    }

    for(int i = 0; i < 8; i++){
      attackCount = attackCount + dir_dists[i];
    }
    printf("%d\n", attackCount);
    return 0;
}
