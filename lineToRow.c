int lineToRow(char *line, int rows, int cols) {
  int i, j=0;

  for (i = 0; line[i] != '\n'; i++) {
    if (line[i] == '0') {
      line[j++] = ' ';
    }
    else if (line[i] == '1') {
      line[j++] = 'X';
    }
    else if (line[i] == ' ') { /* Ignores spaces */
    }
    else {
      return -1;
    }
  }

  if (j != cols) {
    return -1;
  }
  return 0;
}
