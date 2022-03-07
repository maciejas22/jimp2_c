#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

struct graph *initGraph(int rows, int columns) {
    struct graph *grid = (struct graph*) malloc(sizeof(struct graph));
<<<<<<< HEAD
    grid->rows = rows;
    grid->columns = columns;
    int n = rows*columns;
=======
    grid->vertex_number = n;
>>>>>>> a84cb44409d57baa036693260fe160c79c5e9c40
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

void readGraphFromFile(struct graph *grid, char *file_name) {
    FILE *in = fopen(file_name, "r");
    if(in == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku\n");
        exit(-1);
    }

    char line[4];
    fgets(line, 4, in);
    grid->rows = line[0] - '0';
    grid->columns = line[2] - '0';
    fgetc(in);

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
        //printf("%d %d %lf\n", source, destination, weight);
        addEdge(grid, source, destination, weight);
    }
    fclose(in);
}


void writeGraphToFile(struct graph *grid, char *file_name) {
    FILE *out = fopen(file_name, "w");
    if(out == NULL) {
        fprintf(stderr, "Nie mozna stworzyc pliku\n");
        exit(-1);
    }

    fprintf(out, "%d %d\n", grid->rows, grid->columns);
    for(int i = 0; i < (grid->rows)*(grid->columns); i++) {
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
    struct vertex *tmp = NULL;
    int n = (grid->rows) * (grid->columns);
    for(int i = 0; i < n; i++) {
        if(grid->adjacency_list[i].vertexes == NULL) {
            break;
        }
        while(grid->adjacency_list[i].vertexes) {
            tmp = grid->adjacency_list[i].vertexes->next;
            free(grid->adjacency_list[i].vertexes);
            grid->adjacency_list[i].vertexes = tmp;
        }
    }
    free(grid->adjacency_list);
    free(grid);

}


