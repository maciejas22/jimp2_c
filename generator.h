#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <stdlib.h>
#include <stdbool.h>

double rnd(double min, double max);
struct graph *generateGraph(struct graph *grid, int rows, int columns, double min_weight, double max_weight);

#endif
