#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function definitions */
int lineToRow(char *line, int rows, int cols);
int printGrid(char *grid, int rows, int cols);
int checkNeighbor (char *grid, char *grid2, int rows, int cols);
int cmpGrid (char *grid, char *grid2, int rows, int cols);

/*
* Program Name: cgol.c
* Author(s): Nasif Mauthoor
* Purpose: Plays the "Conway's Game of Life" simulation but within a grid
*          (Look at https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
*/

int main(int argc, char const *argv[]) {
  FILE *fp; /* Pointer to file */

  /* Vars */
  int rows;
  int cols;
  char input[100]; /* User input */
  char seed[100]; /* Pointer to the given seed file name */
  char line[100];

  int curTick = 0; /* Current tick */
  int maxTick = 50;
  int i, j, k; /* loops */
  int isWrong = 0; /* bools */

  /* Checking if the given arguments are correct */
  if (argc == 4) {
    strcpy(seed, argv[1]);
    for (i = 0; i < strlen(argv[2]); i++) { /* Checks if each character are integers */
      if (!(47 < argv[2][i] && argv[2][i] < 58)) {
        printf("Invalid Arguments\n");
        return -1;
      }
    }
    for (i = 0; i < strlen(argv[3]); i++) { /* Checks if each character are integers */
      if (!(47 < argv[3][i] && argv[3][i] < 58)) {
        printf("Invalid Arguments\n");
        return -1;
      }
    }
    if (atoi(argv[2]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    if (atoi(argv[3]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    rows = atoi(argv[2]);
    cols = atoi(argv[3]);
  }
  else if (argc == 5) {
    for (i = 0; i < strlen(argv[2]); i++) { /* Checks if each character are integers */
      if (!(47 < argv[2][i] && argv[2][i] < 58)) {
        printf("Invalid Arguments\n");
        return -1;
      }
    }
    for (i = 0; i < strlen(argv[3]); i++) { /* Checks if each character are integers */
      if (!(47 < argv[3][i] && argv[3][i] < 58)) {
        printf("Invalid Arguments\n");
        return -1;
      }
    }
    for (i = 0; i < strlen(argv[4]); i++) { /* Checks if each character are integers */
      if (!(47 < argv[4][i] && argv[4][i] < 58)) {
        printf("Invalid Arguments\n");
        return -1;
      }
    }
    if (atoi(argv[2]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    if (atoi(argv[3]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    if (atoi(argv[4]) < 1) { /* Checks if the second parameter is an int */
      printf("Invalid Arguments\n");
      return -1;
    }
    strcpy(seed, argv[1]);
    rows = atoi(argv[2]);
    cols = atoi(argv[3]);
    maxTick = atoi(argv[4]);

  }
  else {
    printf("Invalid Arguments\n");
    return -1;
  }

  char grid[rows+2][cols+2], grid2[rows+2][cols+2]; /* Initialization of the grids */

  system("clear"); /* Clears the terminal */

  /* Adds borders to grid */
  grid[0][0] = ' ';
  grid[0][cols+1] = ' ';
  grid[rows+1][0] = ' ';
  grid[rows+1][cols+1] = ' ';
  for (i = 1; i < cols+1; i++) {
    grid[0][i] = '-';
    grid[rows+1][i] = '-';
  }
  for (i = 1; i < rows+1; i++) {
    grid[i][0] = '|';
    grid[i][cols+1] = '|';
  }

  /* File read */
  if ((fp = fopen(seed, "r")) == NULL) { /* Opens the file and fp points to it while checking if it's actually there */
    printf("File not found\n");
    return -2;
  }
  for (i = 1; fgets (line, 100, fp) != NULL; i++) {
    if (lineToRow(line, rows, cols) != 0) {
      printf("Invalid seed file\n");
      return -3;
    }
    for (j = 1; j < cols+1; j++) {
      grid[i][j] = line[j-1];
    }
    if (i > rows) {
      printf("Invalid seed file\n");
      return -3;
    }
  }
  fclose(fp);

  /* Print the initial grid */
  printGrid(&grid[0][0], rows, cols);
  printf("%d\n", curTick++);

  do {
    printf("Start? (y or n): ");
    if (fgets(input, 100, stdin) != NULL) {
      if (strcmp(input, "n\n") == 0) {
        printf("Thank you for using dynCGOL.\n");
        return 0;
      }
      else if (strcmp(input, "y\n") == 0) {
        isWrong = 0;
      }
      else {
        printf("Invalid input\n");
        isWrong = 1;
      }
    }
  } while (isWrong);

  do {
    for (i = 0; i < maxTick; i++) {
      system("sleep 0.1");
      system("clear");

      checkNeighbor(&grid[0][0], &grid2[0][0], rows, cols);
      if (cmpGrid(&grid[0][0], &grid2[0][0], rows, cols) == 0) {
        printGrid(&grid[0][0], rows, cols);
        printf("%d\n", curTick++);
        printf("Thank you for using dynCGOL.\n");
        return 0;
      }

      for (j = 1; j < rows+1; j++) {
        for (k = 1; k < cols+1; k++) {
          grid[j][k] = grid2[j][k];
        }
      }
      printGrid(&grid[0][0], rows, cols);
      printf("%d\n", curTick++);
    }

    do {
      printf("Continue? (y or n): ");
      if (fgets(input, 100, stdin) != NULL) {
        if (strcmp(input, "n\n") == 0) {
          printf("Thank you for using dynCGOL.\n");
          return 0;
        }
        else if (strcmp(input, "y\n") == 0) {
          isWrong = 0;
        }
        else {
          printf("Invalid input\n");
          isWrong = 1;
        }
      }
    } while (isWrong);

  } while (1); /* Never ends unless the user chooses 'n' */

  return 0;
}
