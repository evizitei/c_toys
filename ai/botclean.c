/*
Input Format

The first line contains two space separated integers which indicate the current position of the bot.
The board is indexed using Matrix Convention
5 lines follow representing the grid. Each cell in the grid is represented by any of the following 3 characters: 'b' (ascii value 98) indicates the bot's current position, 'd' (ascii value 100) indicates a dirty cell and '-' (ascii value 45) indicates a clean cell in the grid.

Note If the bot is on a dirty cell, the cell will still have 'd' on it.

Output Format

The output is the action that is taken by the bot in the current step, and it can be either one of the movements in 4 directions or cleaning up the cell in which it is currently located. The valid output strings are LEFT, RIGHT, UP and DOWN or CLEAN. If the bot ever reaches a dirty cell, output CLEAN to clean the dirty cell. Repeat this process until all the cells on the grid are cleaned.

Sample Input #00

0 0
b---d
-d--d
--dd-
--d--
----d
Sample Output #00
RIGHT

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct position {
  int row;
  int col;
};

int step_distance(struct position a, struct position b){
  int r_dist = a.row - b.row;
  if(r_dist < 0){
    r_dist = r_dist * -1;
  }

  int c_dist = a.col - b.col;
  if(c_dist < 0){
    c_dist = c_dist * -1;
  }
  return c_dist + r_dist;
}

struct position closest_cell(struct position bot_pos, struct position *dirty_cells, int dirty_count) {
  int distance = 1000;
  struct position closest;
  for(int i = 0; i < dirty_count; i++){
    struct position cell = dirty_cells[i];
    int cell_dist = step_distance(bot_pos, cell);
    if(cell_dist < distance){
      distance = cell_dist;
      closest = cell;
    }
  }
  return closest;
}

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

void print_next_move(struct position bot_pos, struct position *dirty_cells, int dirty_count) {
  struct position closest = closest_cell(bot_pos, dirty_cells, dirty_count);
  int closest_dist = step_distance(bot_pos, closest);
  if(closest_dist == 0){
    printf("CLEAN\n");
    return;
  }
  int rowDiff = closest.row - bot_pos.row;
  int colDiff = closest.col - bot_pos.col;

  if(rowDiffSmaller(rowDiff, colDiff)){
    if(colDiff < 0){
      printf("LEFT\n");
    }else{
      printf("RIGHT\n");
    }
  }else{
    if(rowDiff < 0){
      printf("UP\n");
    }else{
      printf("DOWN\n");
    }
  }
  return;
}

int main() {
  int board_side = 5;
  struct position bot_pos;
  struct position *cells = malloc((board_side^2) * sizeof(struct position));
  int dirty_count = 0;
  scanf("%d %d", &bot_pos.row, &bot_pos.col);
  for(int i=0; i<board_side; i++) {
    char line[board_side + 1];
    scanf("%s[^\\n]%*c", line);
    for(int j = 0; j<board_side; j++){
      char cell = line[j];
      if(cell == 'd'){
        struct position dirtPos;
        dirtPos.row = i;
        dirtPos.col = j;
        cells[dirty_count] = dirtPos;
        dirty_count++;
      }
    }
  }
  struct position *dirty_cells = malloc(dirty_count * sizeof(struct position));
  for(int i = 0; i < dirty_count; i++){
    dirty_cells[i] = cells[i];
  }
  print_next_move(bot_pos, dirty_cells, dirty_count);
  return 0;
}
