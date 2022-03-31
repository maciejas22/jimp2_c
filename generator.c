#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "generator.h"

double rnd(double min, double max) {
    double div = (double)rand() / RAND_MAX;
    return (double)min + ((double)max - (double)min) * div;
}

struct graph *generateGraph(struct graph *grid, int rows, int columns, double min_weight, double max_weight) {
    grid = initGraph(rows, columns);
    srand(time(NULL));

    // generowanie krawedzi poziomych
    if(columns > 1){
        for(int level = 1; level <= rows; level++) {
        for(int i = level*columns-columns; i < level*columns-1; i++) {
            addEdge(grid, i, i+1, rnd(min_weight, max_weight));
            addEdge(grid, i+1, i, rnd(min_weight, max_weight));
        }
    }
    }

    // generowanie krawedzi pionowych
    if(rows > 1) {
    for(int level = 0; level < columns; level++) {
        for(int i = 0; i < rows-1; i++) {
            addEdge(grid, level + columns*i, level +columns*(i+1), rnd(min_weight, max_weight));
            addEdge(grid, level +columns*(i+1), level + columns*i, rnd(min_weight, max_weight));
        }
    }
    }

    return grid;
}