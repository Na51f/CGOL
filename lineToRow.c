#include <stdio.h>
#include "game.h"

int lineToRow(char *line, int rows, int cols) {
  int i, j=0;

  if (line[79] != '\n') {
    return -1;
  }

  for (i = 0; line[i] != '\n'; i++) {
    if (line[i] == '0') {
      line[j++] = ' ';
    }
    else if (line[i] == '1') {
      line[j++] = 'X';
    }
    else if (line[i] == ' ') {
    }
    else {
      return -1;
    }
  }
  return 0;
}
