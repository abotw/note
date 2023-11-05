#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Constant: SENTINEL */
const int SENTINEL = 0;

int main() {
  cout << "This program adds a list of numbers." << endl;
  cout << "Use " << SENTINEL << " to signal the end." << endl;
  int total = 0;
  while (true) {
    int value = getInteger(" ? ");
    if (value == SENTINEL)
      break;
    total += value;
  }
  cout << "The total is " << total << endl;
  return 0;
}
