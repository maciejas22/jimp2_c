#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "generator.h"

double rnd(double min, double max) {
    double div = (double)rand() / RAND_MAX;
    return min + (max - min) * div;
}

generateGraph(struct graph *grid, int rows, int columns, double min_weight, double max_weight) {
    initGraph(rows, columns);
    printf("dsa");
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        printf("%lf ", rnd(-1, 1));
    }

    return grid;
}