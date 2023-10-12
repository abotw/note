/**
 * File: RowOfBoxes.cpp
 * --------------------
 * This program draws a row of box.
 */

#include "gobjects.h"
#include "gwindow.h"

/* The number of rows and columns in the figure. */
const int NUM_ROWS = 8;

/* The size of each box. */
const double BOX_SIZE = 50;

/* Main program */
int main() {
  // TODO: adjusting the window according to the num of boxes
  GWindow window();

  for (int i = 0; i < NUM_ROWS; i++) {
      /* Map i/j to x/y coordinates. */
      double x = i * BOX_SIZE;

      /* Create the square and, if the row plus the column is even, fill it. */
      GRect* box = new GRect(x, 0, BOX_SIZE, BOX_SIZE);

      window.add(box);
  }

  return 0;
}
