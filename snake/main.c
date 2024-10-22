#include <ncurses.h>
#include <unistd.h>

#include "constants.h"
#include "queue.c"

enum arrowDirection {
  DOWN = 258,
  UP = 259,
  LEFT = 260,
  RIGHT = 261,
};

enum screenDetails {
  BLANK = 0,
  SCREEN_SNAKE = 1,
  SCREEN_SNAKE_TAIL = 2,
  FOOD = 3,
  WALL = 8,
};

struct snake {
  int alive;
  int tailLength;
  screenCoordinates position;
  //snake snakePosition
} typedef snake;


// Defines screen array
char screen[SCREEN_HALF][SCREEN_HALF];
snake snakeHead;
tailQueue queue;


void drawScreen(char screen[][SCREEN_HALF]) {
  // Prints screen, for debugging
  for (int i = 0; i < SCREEN_HALF; i++) {
    for (int j = 0; j < SCREEN_HALF; j++) {
      printw("%d, ", screen[i][j]);
    }; printw("\n");
  };
}

void initializeScreen(char screen[][SCREEN_HALF]) {
  
  // Initializes screen for ncurses
  initscr();
  keypad(stdscr, true);


  // Sets each screen edge pixel to 8 
  for (int y = 0; y < SCREEN_HALF; y++) {
    for (int x = 0; x < SCREEN_HALF; x++) {
      if ((x == 0 || x == SCREEN_HALF - 1) || (y == 0 || y == SCREEN_HALF - 1)) screen[y][x] = 8;
    }
  };

  drawScreen(screen);
}

void moveSnake(int input, snake *snakeHead) {

  // Moves the position of the snakeHead struct based on the direction arrow input
  switch (input) {
    case UP:
      snakeHead->position.y--;
      break;
    case DOWN:
      snakeHead->position.y++;
      break;
    case LEFT:
      snakeHead->position.x--;
      break;
    case RIGHT:
      snakeHead->position.x++;
      break;
    default:
      break;
  }
}

// Checks if snake position is valid to the screen and returns 1 if valid, else 0
int isSnakeAlive(char screen[][SCREEN_HALF], snake *snakeHead) {
  char snakeScreenPosition = screen[snakeHead->position.y][snakeHead->position.x];

  // Check if snake is at wall 
  if (snakeScreenPosition == WALL) {
    return 0; 
  }

  return 1;
}
 
void handleSnakeTail(char screen[][SCREEN_HALF], snake *snakeHead, tailQueue *queue) {
  screen[snakeHead->position.y][snakeHead->position.x] = SCREEN_SNAKE; // Add 1 to position of snake in array

  char snakeScreenPosition = screen[snakeHead->position.y][snakeHead->position.x];  // What is on the screen where snake is at
  int rearQueue;

  // Add snake position to tailQueue
  enqueueTail(queue, snakeHead->position);


  // Do something like FOR each snake length draw queue->rear+i to draw SNAKE_TAIL

  // Makes last index snake was on BLANK / 0
  screen[queue->tailCoordinates[queue->rear].y][queue->tailCoordinates[queue->rear].x] = BLANK;


  //printw("last snake cords: (y) %d, (x) %d \n", queue->tailCoordinates[queue->rear].y, queue->tailCoordinates[queue->rear].x);

  // Remove snakeTail from queue
  dequeueTail(queue);


  // Loops trought each tail pixel on the snake
  // for (int i = 0; i < queue.front+1; i++) {
    
  // }

  // Removes last bit of tail from screen

}

snake initializeSnake(char screen[][SCREEN_HALF], snake *snakeHead) {
  snakeHead->alive = 1;
  snakeHead->tailLength = 0;
  snakeHead->position.y = (SCREEN_HALF/2);
  snakeHead->position.x = (SCREEN_HALF/2);

  // Adds the snake to the screen array
  //  We have walls so no need to check if snake is outside bounds
  screen[snakeHead->position.y][snakeHead->position.x] = SCREEN_SNAKE; // Add 1 to position of snake in array
}


// CORE LOGIC
int main(int argc, char ** argv) {

  initializeSnake(screen, &snakeHead);
  initializeScreen(screen);   // Initializes screen array with edges
  InitializeSnakeQueue(&queue, snakeHead.position);

  int input;
  while (1) {
    // Takes input and clears it from the screen
    input = getch();
    clear();

    
    //
    // Core logic
    //
    
    //generateFood();

    moveSnake(input, &snakeHead); // Moves snake's position values

    if (!isSnakeAlive(screen, &snakeHead)) { // Checks if snake move is valid or if snake died ;(
      break;
    };

    handleSnakeTail(screen, &snakeHead, &queue);


    //
    // Draws screen array
    //
    drawScreen(screen);
    refresh();

    sleep(0.2); // Controls the tick speed
  }



  // Initializes screen, setup memory and clears screen

}




  // initscr();
  // int y, x;


  // // Ask user to initialize game sequence:
  // printw("Write something: ");

  // // While input is not == "q", Continue the game loop
  // int gameOn = 1;
  // int input;
  // while((input=getch()) != 113 && gameOn) {
  //   // CORE GAME LOGIC
  //   clear();

  //   getmaxyx(stdscr, y, x);

  //   // Write section
  //   move(y/2, x/2);
  //   printw("Keycode: %d, and character: %c", input, input);
  //   move(0, 0);
  //   printw("Write something: ");
  // }

  // // Stops and wait's for character input
  // clear();
  // endwin();

  // printf("You have exited the game");