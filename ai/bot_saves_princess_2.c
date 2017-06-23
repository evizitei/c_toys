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

void displayNextStep(struct position bot, struct position princess){
  int rowDiff = princess.row - bot.row;
  int colDiff = princess.col - bot.col;


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

int main(void) {

    int m;
    struct position pPos;
    struct position botPos;
    scanf("%d", &m);
    scanf("%d %d", &botPos.row, &botPos.col);
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

    displayNextStep(botPos, pPos);
    return 0;
}
