#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"
#include "BFS.h"
#include "generator.h"
#include "dixtra.h"

bool isDouble(char *string) {
    if(atof(string) <= 0) {
	    return 0;
    }
    return 1;
}

bool isInt(char *string) {
    if(atoi(string) < 1) {
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
    double min_weight_range = argc > 4 ? atof(argv[4]) : 0.0;
    double max_weight_range = argc > 5 ? atof(argv[5]) : 1.0; 
    inputErrorCheck(argc, argv);
    
    struct graph *grid = NULL;
    if(!strcmp(mode, "-r")) {
        grid = readGraphFromFile(grid, "mojGraf.txt");
        switch(BFS(grid))
        {
            case 1:
                printf("Graf jest spojny\n");

                printf("Miedzy ktorymi wierzholkami chcesz znalezc najkrotsza sciezke?\n");
                int input1, input2;
                scanf("%d %d",&input1, &input2);
                int n = grid->rows*grid->columns;
                if(input1 > n || input2 > n || input1 < 0 || input2 < 0) {
                    printf("\nNiepoprawna wartosc!\n");
                    exit(-1);
                }
                for(int i = 0; i < grid->rows*grid->columns; i++) {
                grid->adjacency_list[i].is_visited = 0;
                }

                dix (grid, input1, input2);

                break;
            case 0:
                printf("Graf nie jest spojny\n");
                break;
        }

        writeGraphToFile(grid, "wynik.txt");
    }   
    else if(!strcmp(mode, "-g")) {
        grid = generateGraph(grid, rows, columns, min_weight_range, max_weight_range);
        writeGraphToFile(grid, "wynik.txt");
        // nie wywolujemy funcji BFS poniewaz wygenerowany graf jest zawsze spojny (zgodnie z tresnia zadania)
        printf("Miedzy ktorymi wierzholkami chcesz znalezc najkrotsza sciezke?\n");
        int input1, input2;
        scanf("%d %d",&input1, &input2);
        int n = grid->rows*grid->columns;
        if(input1 > n || input2 > n || input1 < 0 || input2 < 0) {
            printf("\nNiepoprawna wartosc!\n");
            exit(-1);
        }
        dix(grid, input1, input2);

    }
    else if(!strcmp(mode, "-h"))
    {
        printf("Help:\n -h help\n -r wczytaj graf z pliku tekstowego o nazwie mojGraf.txt\n");
        printf(" -g generoj graf: podaj ilosc wierczy i kolumn oraz podaj przedzial wag krawedzi grafu\n");
        printf("Wiersze oraz kolumny musza byc liczbami naturalnymi a wagi zmiennoprzevinkowymi liczbami nieujemnymi.\n");
        printf("\tFromat danych:\n\tW pierwszej linijce pliku powinny znalezc sie dwie liczby naturalne(liczba wierszy i kolumn).\n");
        printf("\tNastepnie w formacie listy powinny znalezc sie wierzcholki docelowe oraz waga krawedzi,\n\tgdzie wierzcholkiem zrodlem jest index linii -2.\n");
        printf("\n\tPrzykladowy plik:\n2 3");
	    printf("\n\t1 :0.2  3 :0.3");
	    printf("\n\t0 :0.1  2 :0.8  4 :0.5");
	    printf("\n\t1 :0.7  5 :0.9");
	    printf("\n\t0 :0.6  4 :0.4");
        printf("\n\t3 :0.3  1 :0.9  5 :0.7");
        printf("\n\t2 :0.8  4 :0.9\n");
        printf("\nW tym przypadku powstanie graf 2x3, gdzie wierzcholek 0 zostanie polaczony z\nwierzcholkiem 1 waga 0,2, oraz z wierzcholkiem 3 waga 0,3 itd.");
        printf("\nPrzykladowe wywolanie: ./GraphAnalizer -g 3 8 4.2 7.3");
        printf("\nWygenerowany zostanie graf o wielkosci 3x8 z krawedziami w zakresie <4,2 ; 7.3>\n");

    }
    else {
        fprintf(stderr, "Nie poprawna flaga");
        exit(-1);
    }

    freeGraph(grid);
    return 0;
}
