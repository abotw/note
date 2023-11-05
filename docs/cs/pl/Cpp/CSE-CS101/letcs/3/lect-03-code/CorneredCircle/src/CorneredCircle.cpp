/**
 * File: CorneredCircle.cpp
 * ------------------------
 * This program draws a checkerboard and shows the dobule for loop.
 */

#include "gobjects.h"
#include "gwindow.h"

int main() {
  GWindow window;

  // The coordinates of the upper-left corner of the cornered circle.
  // TODO: Magic Number
  double x = window.getWidth() - 50;
  double y = window.getHeight() - 50;

  /* Create the circle and place at the corner. */
  // TODO: Fill the circle
  GOval* circle = new GOval(x, y, 50, 50);
  window.add(circle);

  return 0;
}
