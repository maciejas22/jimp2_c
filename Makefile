graphAnalizer: main.o graph.o BFS.o generator.o dixtra.o
	$(CC) main.o graph.o BFS.o generator.o dixtra.o -o graphAnalizer		
	$(CC) main.o graph.o BFS.o generator.o dixtra.o -o test/test1/graphAnalizer
	$(CC) main.o graph.o BFS.o generator.o dixtra.o -o test/test2/graphAnalizer
	$(CC) main.o graph.o BFS.o generator.o dixtra.o -o test/test3/graphAnalizer
	
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

test: test1 test2 test3

test1: 
	cd test/test1 && ./graphAnalizer -r < argumenty.txt
test2: 
	cd test/test2 && ./graphAnalizer -r < argumenty.txt
test3: 
	cd test/test3 && ./graphAnalizer -r < argumenty.txt

.PHONY: clean

clean:
	-rm *.o graphAnalizer test/test1/graphAnalizer test/test2/graphAnalizer test/test3/graphAnalizer
