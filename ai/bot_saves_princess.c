/*
Princess Peach is trapped in one of the four corners of a square grid.
You are in the center of the grid and can move one step at a time in any of the
four directions. Can you rescue the princess?

Input format

The first line contains an odd integer N (3 <= N < 100) denoting the size of the grid.
This is followed by an NxN grid. Each cell is denoted by '-' (ascii value: 45).
The bot position is denoted by 'm' and the princess position is denoted by 'p'.

Grid is indexed using Matrix Convention

Output format

Print out the moves you will take to rescue the princess in one go. The moves must be separated by '\n', a newline. The valid moves are LEFT or RIGHT or UP or DOWN.

Sample input

3
---
-m-
p--
Sample output

DOWN
LEFT

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct position {
  int row;
  int col;
};

bool rowDiffSmaller(rowD, colD){
  int r = rowD;
  int c = colD;
  if(r < 0){
    r = r * -1;
  }
  if(c < 0){
    c = c * -1;
  }
  return (r < c);
}

void displayPathtoPrincess(struct position bot, struct position princess){
  int rowDiff = 0;
  int colDiff = 0;
  while(bot.col != princess.col || bot.row != princess.row){
    rowDiff = princess.row - bot.row;
    colDiff = princess.col - bot.col;
    if(rowDiffSmaller(rowDiff, colDiff)){
      if(colDiff < 0){
        printf("LEFT\n");
        bot.col--;
      }else{
        printf("RIGHT\n");
        bot.col++;
      }
    }else{
      if(rowDiff < 0){
        printf("UP\n");
        bot.row--;
      }else{
        printf("DOWN\n");
        bot.row++;
      }
    }
  }
}

int main(void) {

    int m;
    scanf("%d", &m);
    struct position pPos;
    struct position botPos;
    char line[m + 1];

    for(int i=0; i<m; i++) {
      scanf("%s", line);
      for(int j=0; j<m; j++){
        char cell = line[j];
        if(cell == 'p'){
          pPos.row = i;
          pPos.col = j;
        }else if(cell == 'm'){
          botPos.row = i;
          botPos.col = j;
        }
      }
    }

    displayPathtoPrincess(botPos, pPos);
    return 0;
}
