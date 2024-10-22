#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "constants.h"
#include "queue.c"

enum arrowDirection {
  DOWN = 258,
  UP = 259,
  LEFT = 260,
  RIGHT = 261,
};

enum screenDetails {
  BLANK = 4,
  SCREEN_SNAKE = 1,
  SCREEN_SNAKE_TAIL = 2,
  FRUIT = 3,
  WALL = 8,
};

struct snake {
  int alive;
  int tailLength;
  screenCoordinates position;
  //snake snakePosition
} typedef snake;


// Defines screen array
char screen[SCREEN_HALF][SCREEN_HALF] = {{}};
snake snakeHead;
tailQueue queue;

//

int atScreenEdge(int y, int x) {
  return (y == 0 || y == (SCREEN_HALF-1) || x == 0 || x == (SCREEN_HALF-1));
}

//


// Brute forces a random location for the fruit!!! ( IF PLAYER REACHES FULL SNAKE, game will crash <3 )
void spawnFruit(char screen[][SCREEN_HALF], int *fruitOnMap) {
  char min = 0;
  char max = SCREEN_HALF-1;

  screenCoordinates fruitCoordinates;

  // While fruit is not spawned, Creates random x and y for fruit position cordinates
  while (1) {
    fruitCoordinates.y = rand() % (max - min+1) + min;
    fruitCoordinates.x = rand() % (max - min+1) + min;
    
    if (screen[fruitCoordinates.y][fruitCoordinates.x] == BLANK) {
      break;   // Break's if fruit has spawned on a blank position
    }

    // MIGHT Add a check if there are any 0's still left on the screen, CHECKs for victory condition OR infinite loop <3

    continue;
  }

  screen[fruitCoordinates.y][fruitCoordinates.x] = FRUIT;
  *fruitOnMap = 1;

}


void drawScreen(char screen[][SCREEN_HALF]) {
  // Prints screen, for debugging
  for (int i = 0; i < SCREEN_HALF; i++) {
    for (int j = 0; j < SCREEN_HALF; j++) {


      // screen[i][j] Have values that coresponds to color_pairs {BLANK, WALL, SNAKE ... etc}
      attron(COLOR_PAIR(screen[i][j]));   

      printw("█");  // BLANK == █ □ " " ■
    
      attroff(COLOR_PAIR(screen[i][j]));

    }; printw("\n");
  };
}

void initializeScreen(char screen[][SCREEN_HALF], int *fruitOnMap) {
  
  // Initializes screen for ncurses
  setlocale(LC_ALL, "");    // Sets locale to unicode

  initscr();                // Initializes screen
  keypad(stdscr, true);     // Makes arrow keys work

  // Setts the colors of the items on screen
  start_color();          // Initializes colors
  use_default_colors();   // Makes color work
    init_pair(BLANK, COLOR_BLACK, COLOR_BLACK);
    init_pair(SCREEN_SNAKE, COLOR_GREEN, COLOR_GREEN);
    init_pair(FRUIT, COLOR_RED, COLOR_RED);
    init_pair(WALL, COLOR_WHITE, COLOR_WHITE);

  // Sets each screen edge pixel to 8 
  for (int y = 0; y < SCREEN_HALF; y++) {
    for (int x = 0; x < SCREEN_HALF; x++) {
      
      // Creates the top and bottom walls
      // Fills the rest in Except SNAKE with BLANk
      if (atScreenEdge(y, x)) {
        screen[y][x] = WALL;
      } else if (screen[y][x] != SCREEN_SNAKE){
        screen[y][x] = BLANK;
      }

    }
  };

  spawnFruit(screen, fruitOnMap);
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
  if (snakeScreenPosition == WALL || snakeScreenPosition == SCREEN_SNAKE) {
    return 0; 
  }

  return 1;
}
 
void handleSnakeTail(char screen[][SCREEN_HALF], snake *snakeHead, tailQueue *queue, int *fruitOnMap) {
  screen[snakeHead->position.y][snakeHead->position.x] = SCREEN_SNAKE; // Add 1 to position of snake in array

  char snakeScreenPosition = screen[snakeHead->position.y][snakeHead->position.x];  // What is on the screen where snake is at


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

// Check if snake is on Fruit, IF so grow snake
void growSnake(char screen[][SCREEN_HALF], snake *snakeHead, tailQueue *queue, int *fruitOnMap) {
  char snakeScreenPosition = screen[snakeHead->position.y][snakeHead->position.x];  // What is on the screen where snake is at

  if (snakeScreenPosition == FRUIT) {
    enqueueTail(queue, snakeHead->position);
    *fruitOnMap = 0;
  }
};


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

  int fruitOnMap = 0;

  initializeSnake(screen, &snakeHead);
  initializeScreen(screen, &fruitOnMap);   // Initializes screen array and places fruit
  InitializeSnakeQueue(&queue, snakeHead.position);
  


  int input;
  int buffer;

  input = getch();
  nodelay(stdscr, TRUE);    // Makes getch() NOT interupt programflow

  while (1) {
    // When new direction is presses store it in input, else do nothing
    if ((buffer = getch()) != ERR) {
      input = buffer;
    };

    clear();  // Clears user input
    
    //
    // Core logic
    //
    
    moveSnake(input, &snakeHead); // Moves snake's position values

    if (!isSnakeAlive(screen, &snakeHead)) { // Checks if snake move is valid or if snake died ;(
      break;
    };


    growSnake(screen, &snakeHead, &queue, &fruitOnMap);

    if (!fruitOnMap) {
      spawnFruit(screen, &fruitOnMap); // Places fruit on screen and places 1 into fruitOnMap
    }


    handleSnakeTail(screen, &snakeHead, &queue, &fruitOnMap);

    //
    // Draws screen array
    //
    drawScreen(screen);
    refresh();

    usleep(TICK_SPEED); // Controls the tick speed
  }

  endwin();


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