# AUTHOR
Name: Nasif Mauthoor
email: mmauthoo@uoguelph.ca

# PROGRAM DESCRIPTION
  cgol: runs the simulation called Conway's game of life from a given grid with 20 rows and 40 columns of '0's and '1's that resides in a .seed file. The only exception is that the grid is finite, so nothing happens outside the borders.

  dynCGOL: runs the exact same thing as cgol but the only difference is that the user is able to set the length of the rows and the columns.

## FUNCTIONS
  lineToRow:
    Takes a string, reads all the 0's and 1's and puts a ' ' or 'X' in the respective grid case.

  checkNeighbor:
    It reads the current grid, looks around each cell and according the the rules of CGOL, puts the according grid into the second grid.

  printGrid:
    It just prints out the grid

  cmpGrid:
    Checks that both grids given are the same.

## ERRORS MESSAGES
  Invalid input: when user does not write "y" "n" "Y" or "N"

  Invalid arguments: For cgol: (./cgol "filename" "ticks") and ticks needs to be an integer and is completely optional. For dynCGOL: (./cgol "filename" "ticks" "rows" "columns"), ticks, rows and columns are mandatory, all of which needs to be an integer.

  Invalid file: File either has too many or too few rows and columns or contains a character that isn't {' ', '0', '1', '\\n' '\\0' }

## USAGE
  cgol:
    In terminal:  make cgol
                  ./cgol <filename> <ticks>

    cgol:
      In terminal:  make dynCGOL
                    ./dynCGOL <filename> <ticks> <rows> <columns>
