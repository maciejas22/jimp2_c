#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph *initGraph(size_t n) {
    struct graph *grid = (struct graph*) malloc(sizeof(struct graph));
    grid->vertex_number = n;
    
    grid->adjacency_list = (struct vertex_list*) malloc(n * sizeof(struct vertex_list));
    for(int i = 0; i < n; i++) {
        grid->adjacency_list[i].vertexes = NULL;
    }

    return grid;
}

struct vertex *initVertex(int destination, double weight) {
    struct vertex *newVertex = (struct vertex *) malloc(sizeof(struct vertex));
    newVertex->destination = destination;
    newVertex->weight = weight;
    newVertex->next = NULL;
    return newVertex;
}

void addEdge(struct graph *grid, int soruce, int destination, double weight) {
    struct vertex *newVertex = initVertex(destination, weight);
    newVertex->next = grid->adjacency_list[soruce].vertexes;
    grid->adjacency_list[soruce].vertexes = newVertex;

    newVertex = initVertex(soruce, weight);
    newVertex->next = grid->adjacency_list[destination].vertexes;
    grid->adjacency_list[destination].vertexes = newVertex;
}

void writeGraphToFile(struct graph *grid, char *file_name, int rows, int columns) {
    FILE *out = fopen(file_name, "w");
    if(out == NULL) {
        printf("Nie mozna stworzyc pliku\n");
        exit(-1);
    }

    fprintf(out, "%d %d\n", rows, columns);
    for(int i = 0; i < grid->vertex_number; i++) {
        fprintf(out, "\t");
        while(grid->adjacency_list[i].vertexes != NULL) {
            fprintf(out, " %d :%lf ", grid->adjacency_list[i].vertexes->destination, grid->adjacency_list[i].vertexes->weight);
            grid->adjacency_list[i].vertexes = grid->adjacency_list[i].vertexes->next;
        }
        fprintf(out, "\n");
    }
    fclose(out);
}

void freeGraph(struct graph *grid) {
    struct vertex *tmp;
    for(int i = 0; i < grid->vertex_number; i++) {
        while(grid->adjacency_list[i].vertexes != NULL) {
            tmp = grid->adjacency_list[i].vertexes;
            grid->adjacency_list[i].vertexes = grid->adjacency_list[i].vertexes->next;
            free(tmp);
        }
    }
    free(grid);
}


