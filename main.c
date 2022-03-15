#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"
#include "BFS.h"

bool isDouble(char *string) {
    if(atof(string) <= 0) {
	    return 0;
    }
    return 1;
}

bool isInt(char *string) {
    if(atoi(string) <= 0) {
	    return 0;
    }
    return 1;
}

void inputErrorCheck(int argc, char *argv[]){
    if(argc > 2 && isInt(argv[2]) == 0) { 
        fprintf(stderr, "Bledna ilosc wierszy");
        exit(-1);
    }
    if(argc > 3 && isInt(argv[3]) == 0) { 
        fprintf(stderr, "Bledna ilosc kolumn");
        exit(-1);
    }
    if(argc > 4 && isDouble(argv[4]) == 0) { 
        fprintf(stderr, "Bledny zakres dolnej wagi krawedzi grafu");
        exit(-1);
    }
    if(argc > 5 && isDouble(argv[5]) == 0) { 
        fprintf(stderr, "Bledny zakres gornej wagi krawedzi grafu");
        exit(-1);
    }
    
}

int main(int argc, char *argv[]) {
    char *file_name = "mojGraf.txt";
    char *mode = argc > 1 ? argv[1] : "-g";
    int rows = argc > 2 ? atoi(argv[2]) : 5;     
    int columns = argc > 3 ? atoi(argv[3]) : 5;
    double min_weight_range = argc > 4 ? atof(argv[4]) : 0;
    double max_weight_range = argc > 5 ? atof(argv[5]) : 1; 
    inputErrorCheck(argc, argv);
    
    struct graph *grid = NULL;
    if(!strcmp(mode, "-r")) {
        printf("Jeszcze niezaimplementowane");
    }   
    else if(!strcmp(mode, "-g")) {
        grid = readGraphFromFile(grid, "mojGraf.txt");
        writeGraphToFile(grid, "wynik.txt");
        switch(BFS(grid))
        {
            case 1:
                printf("Graf jest spojny\n");
                break;
            case 0:
                printf("Graf nie jest spojny\n");
                break;
        }
    }
    else {
        fprintf(stderr, "Nie poprawna flaga");
        exit(-1);
    }
    freeGraph(grid);
    return 0;
}
