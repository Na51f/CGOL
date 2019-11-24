int checkNeighbor (char *grid, char *grid2, int rows, int cols) {
  int neighbors;
  int i, j;

  /* Scrolls through each cell in the initial grid */
  for (i = 0; i < rows+2; i++) {
    for (j = 0; j < cols+2; j++) {
      neighbors = 0;

      /* Checks for the number of neigbors around a cell */
      if (*(grid+((i-1)*(cols+2)+j-1)) == 'X') {
        neighbors++;
      }
      if (*(grid+((i-1)*(cols+2)+j)) == 'X') {
        neighbors++;
      }
      if (*(grid+((i-1)*(cols+2)+j+1)) == 'X') {
        neighbors++;
      }
      if (*(grid+(i*(cols+2)+j-1)) == 'X') {
        neighbors++;
      }
      if (*(grid+(i*(cols+2)+j+1)) == 'X') {
        neighbors++;
      }
      if (*(grid+((i+1)*(cols+2)+j-1)) == 'X') {
        neighbors++;
      }
      if (*(grid+((i+1)*(cols+2)+j)) == 'X') {
        neighbors++;
      }
      if (*(grid+((i+1)*(cols+2)+j+1)) == 'X') {
        neighbors++;
      }

      if (*(grid+(i*(cols+2)+j)) == 'X') { /* Checks if the cell is alive */
        if (1 < neighbors && neighbors < 4) {
          *(grid2+(i*(cols+2)+j)) = 'X';
        }
        else {
          *(grid2+(i*(cols+2)+j)) = ' ';
        }
      }
      else { /* If the cell is dead */
        if (neighbors == 3) {
          *(grid2+(i*(cols+2)+j)) = 'X';
        }
        else {
          *(grid2+(i*(cols+2)+j)) = ' ';
        }
      }
    }
  }
  return 0;
}
