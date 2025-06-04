#include <stdio.h>
#include <ncurses.h>

// Returns 2D array as screen
int **initializeScreen() {
  // Initializes ncurses
  initscr();                // Initializes ncurses screen window 
  keypad(stdscr, true);     // Makes arrow keys work
  nodelay(stdscr, TRUE);    // Makes getch() NOT interupt programflow


}

void drawScreen(int **screen) {

}

int main() {

  int **screen = initializeScreen();

  // Main game loop
  int input;
  int input_buffer;

  while (1) {
    // Event listener, stored user input in "input" IF anything is pressed, else input = NULL
    input = getch();
    clear();
    
    if (input == 32) { // SPACE
      printw("Input: %d\n", input);
    }


  }

  endwin();
}