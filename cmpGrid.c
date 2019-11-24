#include <stdio.h>

int cmpGrid (char *grid, char *grid2, int rows, int cols) {
  int i,j;
  int same = 0;
  for (i = 1; i < rows+1; i++) {
    for (j = 1; j < cols+1; j++) {
      if (*(grid+(i*(rows+2)+j)) != *(grid2+(i*(cols+2)+j))) {
        same = 1;
      }
    }
  }
  return same;
}
