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

long boardIndex(int row, int col, long n){
  return ((row - 1) * n) + (col - 1);
}

int attacksInDirection(int rs, int cs, int *board, long n, int rInc, int cInc){
  int dirAttacks = 0;
  int curRow = rs;
  int curCol = cs;
  for(int i = 0; i < n; i++){
    curRow = curRow + rInc;
    curCol = curCol + cInc;
    if(curRow >= 1 && curRow <= n && curCol >= 1 && curCol <= n){
      long idx = boardIndex(curRow, curCol, n);
      int val = board[idx];
      if(val == 1){
        break; // struck obstacle
      }else{
        dirAttacks = dirAttacks + 1;
      }
    }else{
      break;
    }
  }
  return dirAttacks;
}

int main(){
    long n;
    int k;
    scanf("%ld %d",&n,&k);
    int rQueen;
    int cQueen;
    scanf("%d %d",&rQueen,&cQueen);
    int attackCount = 0;
    long boardSize = n * n;
    int *board = calloc(boardSize, sizeof(int));
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        scanf("%d %d",&rObstacle,&cObstacle);
        long obstacleIndex = boardIndex(rObstacle, cObstacle, n);
        board[obstacleIndex] = 1;
    }

    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, 1, 0); // up
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, 1, 1); // up-right
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, 0, 1); // right
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, -1, 1); // down-right
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, -1, 0); // down
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, -1, -1); // down-left
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, 0, -1); // left
    attackCount = attackCount + attacksInDirection(rQueen, cQueen, board, n, 1, -1); // up-left
    printf("%d\n", attackCount);
    return 0;
}
