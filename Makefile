graph: main.o graph.o BFS.o generator.o dixtra.o
	$(CC) main.o graph.o BFS.o generator.o dixtra.o -o graph
	
main.o: main.c
	$(CC) -c main.c
	
graph.o: graph.c graph.h
	$(CC) -c graph.c

BFS.o: BFS.c BFS.h graph.c graph.h
	$(CC) -c BFS.c graph.c

generator.o: generator.c generator.h graph.c graph.h
	$(CC) -c generator.c graph.c
dixtra.o: graph.c graph.h dixtra.c dixtra.h
	$(CC) -c dixtra.c graph.c
.PHONY: clean

clean:
	-rm *.o graph
