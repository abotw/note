/**
 * File: BoxGrid.cpp
 * -----------------
 * This program draws a checkerboard and shows the dobule for loop.
 */

#include "gobjects.h"
#include "gwindow.h"

/* The number of rows and columns in the figure. */
const int NUM_ROWS = 8;
const int NUM_COLS = 8;

/* The size of each box. */
const double BOX_SIZE = 50;

/* Main program */
int main() {
  GWindow window(NUM_COLS * BOX_SIZE, NUM_ROWS * BOX_SIZE);

  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      /* Map i/j to x/y coordinates. */
      double x = j * BOX_SIZE;
      double y = i * BOX_SIZE;

      /* Create the square and, if the row plus the column is even, fill it. */
      GRect* box = new GRect(x, y, BOX_SIZE, BOX_SIZE);
      if ((i + j) % 2 == 0) {
        box->setFilled(true);
      }

      window.add(box);
    }
  }

  return 0;
}
