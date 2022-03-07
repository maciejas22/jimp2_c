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
    bool is_visited;
};

struct graph {
    int rows;
    int columns;
    struct vertex_list *adjacency_list;
};

<<<<<<< HEAD
struct graph *initGraph(int rows, int columns);
struct vertex *initVertex(int destination, double weight);
=======
struct graph *initGraph(size_t n);
>>>>>>> a84cb44409d57baa036693260fe160c79c5e9c40
void addEdge(struct graph *grid, int soruce, int destination, double weight);
void readGraphFromFile(struct graph *grid, char *file_name);
void writeGraphToFile(struct graph *grid, char *file_name);
void freeGraph(struct graph *grid);

#endif
