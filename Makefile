all: cgol

cgol: cgol.o lineToRow.o printGrid.o checkNeighbor.o cmpGrid.o
	gcc -ansi -o cgol cgol.o lineToRow.o printGrid.o checkNeighbor.o cmpGrid.o

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

lineToRow.o: lineToRow.c
	gcc -ansi -Wall -c lineToRow.c

checkNeighbor.o: checkNeighbor.c
	gcc -ansi -Wall -c checkNeighbor.c

printGrid.o: printGrid.c
	gcc -ansi -Wall -c printGrid.c

cmpGrid.o: cmpGrid.c
	gcc -ansi -Wall -c cmpGrid.c

clean:
	rm *.o cgol
