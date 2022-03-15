#ifndef __BFS_H__
#define __BFS_H__

#include <stdlib.h>
#include <stdbool.h>

struct node {
    int index;
    struct node *next;
};

struct nodePtr {
    struct node *front, *rear;
};

struct node *initNode(int index);
struct nodePtr *initQueue();
void insertToQueue(struct nodePtr *queue, int index);
int removeFromQueue(struct nodePtr *queue);
void printQueue(struct nodePtr *queue);
int BFS(struct graph *grid);

#endif