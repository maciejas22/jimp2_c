#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"

bool isDouble(char *string) {
    char *endPointer;
    strtod(string, &endPointer);
    return string != endPointer;
}

bool isInt(char *string) {
    for(int i = 0; string[i] != '\0'; i++) {
        if(isdigit(string[i]) == 0)
            return 0;
    }
    if(atol(string) > 2147483648 || atol(string) < -2147483648)
        return 0;
    return 1;
}

void inputErrorHandling(int argc, char *argv[]){
    if(argc > 1 && argv[1] != "-r") {
        printf("Nieprawidlowa flaga");
        exit(-1);
    }
    if(argc > 2 && isInt(argv[2]) == 0) { 
        printf("Bledna ilosc wierszy");
        exit(-1);
    }
    if(argc > 3 && isInt(argv[3]) == 0) { 
        printf("Bledna ilosc kolumn");
        exit(-1);
    }
    if(argc > 4 && isDouble(argv[4]) == 0) { 
        printf("Bledny zakres wag krawedzi grafu");
        exit(-1);
    }
    if(argc > 5 && isDouble(argv[5]) == 0) { 
        printf("Bledny zakres wag krawedzi grafu");
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
    
    // struct graph *grid = initGraph(rows*columns);
    // addEdge(grid, 0, 3 ,1.33213212);
    // addEdge(grid, 1, 3 ,1.32321);
    // addEdge(grid, 2, 3 ,1.32132);
    // addEdge(grid, 2, 3, 1.3);
    // writeGraphToFile(grid, file_name, 7, 3);
    // freeGraph(grid);
    readGraphFromFile(file_name);
    return 0;
}
