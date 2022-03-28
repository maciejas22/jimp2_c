#ifndef __dixtra_H__
#define __dixtra_H__

#include <stdlib.h>
#include <stdbool.h>

struct prioNode {
    int vertex;
    double weight;
    int previous;
    struct prioNode *next;
};


struct prioNode *initPrioNode(int v, double w, int p);

void addSon(struct prioNode *prio ,int v, double w, int p);
void dixtra (struct graph *grid, int s);
#endif