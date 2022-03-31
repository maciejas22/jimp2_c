#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

struct graph *initGraph(int rows, int columns) {
    struct graph *grid = (struct graph*) malloc(sizeof(struct graph));
    grid->rows = rows;
    grid->columns = columns;
    int n = rows*columns;
    grid->adjacency_list = (struct vertex_list*) malloc(n * sizeof(struct vertex_list));
    for(int i = 0; i < n; i++) {
        grid->adjacency_list[i].vertexes = NULL;
        grid->adjacency_list[i].is_visited = 0;
    }

    return grid;
}

void addEdge(struct graph *grid, int soruce, int destination, double weight) {
    struct vertex *newVertex = (struct vertex *) malloc(sizeof(struct vertex));
    newVertex->destination = destination;
    newVertex->weight = weight;
    newVertex->next = grid->adjacency_list[soruce].vertexes;
    grid->adjacency_list[soruce].vertexes = newVertex;
}

struct graph *readGraphFromFile(struct graph *grid, char *file_name) {
    FILE *in = fopen(file_name, "r");
    if(in == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku\n");
        exit(-1);
    }

    int r, c;
    fscanf(in, "%d %d",&r, &c);
    grid = initGraph(r, c);

    char tmp1, tmp2, tmp3, tmp4;
    int destination, source = 0;
    double weight;
    
    while(!feof(in)) {
        fscanf(in, "%c%c", &tmp1, &tmp2);
        if(tmp2 == '\n') {
            source++;
            continue;
        }
        fscanf(in, "%d%c%c%lf", &destination, &tmp3, &tmp4, &weight);
        
        addEdge(grid, source, destination, weight);
    }
    fclose(in);

    return grid;
}


void writeGraphToFile(struct graph *grid, char *file_name) {
    FILE *out = fopen(file_name, "w");
    if(out == NULL) {
        fprintf(stderr, "Nie mozna stworzyc pliku\n");
        exit(-1);
    }
    struct vertex *tmp = NULL;

    fprintf(out, "%d %d\n", grid->rows, grid->columns);
    int n = (grid->rows)*(grid->columns);
    for(int i = 0; i < n; i++) {
        fprintf(out, "\t");
        tmp = grid->adjacency_list[i].vertexes;
        while(tmp != NULL) {
            fprintf(out, " %d :%lf ", tmp->destination, tmp->weight);
            tmp = tmp->next;
        }
        fprintf(out, "\n");
    }
    fclose(out);
}

void freeGraph(struct graph *grid) {
    if(grid == NULL) {
        exit(-1);
    }
    struct vertex *tmp = NULL;
    int n = (grid->rows) * (grid->columns);
    for(int i = 0; i < n; i++) {
        tmp = grid->adjacency_list[i].vertexes;
        while(tmp != NULL) {
            grid->adjacency_list[i].vertexes = grid->adjacency_list[i].vertexes->next;
            free(tmp);
            tmp = grid->adjacency_list[i].vertexes;
        }
    }
    free(grid->adjacency_list);
    free(grid);
}