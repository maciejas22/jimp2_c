#ifndef __DIXTRA_H__
#define __DIXTRA_H__

#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include <string.h>

struct prioNode {
    int vertex;
    double weight;
    int previous;
    struct prioNode *next;
};

struct prioNode *initPrioNode(int v, double w, int p);

void addSon(struct prioNode *prio ,int v, double w, int p);
void dix(struct graph *grid, int s, int p);
int intLen(int a);

#endif