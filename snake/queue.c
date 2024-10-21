#include "constants.h"

// Defines coordinates of where tail is, to be placed in queue
struct screenCoordinates {
  char x;
  char y;
} typedef screenCoordinates;

// queue that holds current and previouses coordinates for snakeTail,
// Should -1 and +1 for each tick the snake moves forward
struct tailQueue {
  struct screenCoordinates tailCoordinates[1000];
  char front;   // newest / Last item to be added
  char rear;    // Index describing where in screenCoordinates array our last placed item is, eg(5), our queue has 6 items 0-5
} typedef tailQueue;


// Adds screenCoordinates to queue and adds 1 to index
void enqueueTail(tailQueue *queue, screenCoordinates coordinates) {
  queue->front++;
  queue->tailCoordinates[queue->front] = coordinates;
};

// Deecrements front index
int dequeueTail(tailQueue *queue) {
  queue->rear++;
};

// Initializes tailQueue as empty 
void InitializeSnakeQueue(tailQueue *queue, screenCoordinates startCordinates) {
  queue->front = 0;
  queue->rear = 0;

  queue->tailCoordinates[0] = startCordinates;
};