#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Defines */
#define ROWS 20
#define COLS 40

/* Function definitions */
int lineToRow(char *line, int rows, int cols);
int printGrid(char*);
int checkNeighbor (char grid[ROWS+2][COLS+2], char *grid2);
int cmpGrid (char *grid, char *grid2, int rows, int cols);

/*
* Program Name: cgol.c
* Author(s): Nasif Mauthoor
* Purpose: Plays the "Conway's Game of Life" simulation
*          (Look at https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
*/

int main(int argc, char const *argv[]) {
  FILE *fp; /* Pointer to file */

  /* Vars */
  char input[3]; /* User input */
  char seed[100]; /* Pointer to the given seed file name */
  char line[100];
  char grid[ROWS+2][COLS+2], grid2[ROWS+2][COLS+2];

  int curTick = 0; /* Current tick */
  int maxTick = 50;
  int i, j, k;
  int isRun = 0;

  /* Checking if the given arguments are correct */
  if (argc == 2) {
    strcpy(seed, argv[1]);
  }
  else if (argc == 3) {
    for (i = 0; i < strlen(argv[2]); i++) {
      if (/* condition */) {
        /* code */
      }
    }
    if (atoi(argv[2]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    maxTick = atoi(argv[2]);
  }
  else {
    printf("Invalid Arguments\n");
    return -1;
  }

  system("clear"); /* Clears the terminal */

  /* Adds borders to grid */
  grid[0][0] = ' ';
  grid[0][COLS+1] = ' ';
  grid[ROWS+1][0] = ' ';
  for (i = 1; i < COLS; i++) {
    grid[0][i] = '_';
    grid[ROWS+1][i] = '-';
  }
  for (i = 1; i < ROWS; i++) {
    grid[i][0] = '|';
    grid[i][COLS+1] = '|';
  }
  grid2[0][0] = ' ';
  grid2[0][COLS+1] = ' ';
  grid2[ROWS+1][0] = ' ';
  for (i = 1; i < COLS; i++) {
    grid2[0][i] = '_';
    grid2[ROWS+1][i] = '-';
  }
  for (i = 1; i < ROWS; i++) {
    grid[i][0] = '|';
    grid[i][COLS+1] = '|';
  }

  /* File read */
  if ((fp = fopen(seed, "r")) == NULL) { /* Opens the file and fp points to it while checking if it's actually there */
    printf("File not found\n");
    return -2;
  }
  for (i = 1; fgets (line, 100, fp) != NULL; i++) {
    if (lineToRow(line, ROWS, COLS) != 0) {
      printf("Invalid seed file\n");
      return -3;
    }
    for (j = 1; j < COLS; j++) {
      grid[i][j] = line[j-1];
    }
  }
  fclose(fp);

  /* Print the initial grid */
  printGrid(&grid[0][0], &curTick);

  printf("Start? (y or n): ");
  if (fgets(input, 3, stdin) != NULL) {
    if (strcmp(input, "n\n") == 0) {
      return 0;
    }
    else if (strcmp(input, "y\n") == 0) {
    }
    else {
      printf("Invalid input\n");
      return -4;
    }
  }

  do {
    for (i = 0; i < maxTick; i++) {
      /* code */
    }
  } while (isRun);

  return 0;
}
