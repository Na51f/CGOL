#include <stdio.h>

int printGrid (char *grid, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows+2; i++) {
    for (j = 0; j < cols+2; j++) {
      printf("%c", grid[i][j]);
    }
    if (i != rows+1) {
      printf("\n");
    }
  }
  return 0;
}
