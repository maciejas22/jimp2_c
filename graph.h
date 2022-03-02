#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdlib.h>
#include <stdbool.h>

#define INF -1

struct vertex {
    int destination;
    double weight;
    struct vertex *next;
};

struct vertex_list {
    struct vertex *vertexes;
};

struct graph {
    int vertex_number;
    struct vertex_list *adjacency_list;
};

struct graph *initGraph(size_t n);
struct vertex *initVertex(int destination, double weight);
void addEdge(struct graph *grid, int soruce, int destination, double weight);
void readGraphFromFile(char *file_name);
void writeGraphToFile(struct graph *grid, char *file_name, int rows, int columns);
void freeGraph(struct graph *grid);

#endif