#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "BFS.h"

struct node *initNode(int index) {
    struct node *tmp = (struct node *) malloc (sizeof(struct node));
    tmp->index = index;
    tmp->next = NULL;
    return tmp;
}

struct nodePtr *initQueue() {
    struct nodePtr *queue = (struct nodePtr *) malloc (sizeof(struct nodePtr));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void insertToQueue(struct nodePtr *queue, int index) {
    struct node *tmp = initNode(index);
    if(queue->rear == NULL) {
        queue->front = tmp;
        queue->rear = tmp;
        return;
    }
    queue->rear->next = tmp;
    queue->rear = queue->rear->next;
}

int removeFromQueue(struct nodePtr *queue) {
    if(queue->front == NULL) {
        return -1;
    }
    struct node *tmp = queue->front;
    int res = queue->front->index;
    queue->front = queue->front->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    free(tmp);
    return res;
}

int BFS(struct graph *grid) {
    struct nodePtr *queue = initQueue();
    grid->adjacency_list[0].is_visited = 1;
    insertToQueue(queue, 0);

    while(queue->front != NULL) {
        int n = removeFromQueue(queue);
        struct vertex *tmp = grid->adjacency_list[n].vertexes;
        
        while(tmp != NULL) {
            if(grid->adjacency_list[tmp->destination].is_visited == 0) {
                grid->adjacency_list[tmp->destination].is_visited = 1;
                insertToQueue(queue, tmp->destination);
            }
            tmp = tmp->next;
        }
    }
    free(queue);
    
    int n = grid->columns * grid->rows - 1;
    bool is_connected = 1;
    for(n; n>=0; n--) {
        if(grid->adjacency_list[n].is_visited == 0) {
            is_connected = 0;
        }
    }
    return is_connected;
}