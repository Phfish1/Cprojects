#include <stdio.h>

// Defines the structure for each block
struct tetromino {
  char type;
  int postition[2];
  int rotation;
};typedef struct tetromino tetromino;

// Defines all types of TetrominoTypes as letters
char tetrominoTypes[7] = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

void drawTetromino(tetromino block, int **grid) {
  int y = block.postition[0];
  int x = block.postition[1];

  switch (block.type) {
    case 'I':
      char core = grid[y][x]; // This is where the tetromino will be rotated around (I think, might change in future to some value based on position)
      char hat = grid[y+1][x];
      char weist = grid[y-1][x];
      char bottom = grid[y-2][x];
    case 'J':
      char core = grid[y][x];
      char hat = grid[y+1][x];
      char weist = grid[y-1][x];
      char bottom = grid[y-1][x-1];
    case 'L':
      char core = grid[y][x];
      char hat = grid[y+1][x];
      char weist = grid[y-1][x];
      char bottom = grid[y-1][x+1];
    case 'O':
      char core = grid[y][x]; 
      char hat = grid[y][x+1];      // Hat should always be at the TOPMOST "pixel", (This is usefull when spawnin blocks)
      char weist = grid[y-1][x];
      char bottom = grid[y-1][x+1];
  };




};

int main() {

}