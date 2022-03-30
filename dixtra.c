#include <stdio.h>
#include <stdlib.h>
#include "dixtra.h"
#include "graph.h"
#include <string.h>
#define INF 2147483647

struct prioNode *initPrioNode(int v, double w, int p) {
    struct prioNode *tmp = (struct prioNode *) malloc (sizeof (struct prioNode));
    tmp -> vertex = v;
    tmp->weight = w;
    tmp->previous = p;
    tmp->next = NULL;
    return tmp;
}

void addSon(struct prioNode *prio ,int v, double w, int p) {
    struct prioNode *tmp = prio;
    struct prioNode *tmp2 = initPrioNode(v,w,p);
    while (tmp->next != NULL && tmp->next -> weight <= w) {
        tmp = tmp->next;
    }
    tmp2->next = tmp->next;
    tmp->next =tmp2;
}

void dix(struct graph *grid, int s, int p) {
    struct prioNode *prio = initPrioNode(s,0,0);
    struct prioNode *move =prio;
    struct vertex *ver = grid->adjacency_list[s].vertexes;
    int start = s, finish = p;

    for (int i=0;i<grid->rows*grid->columns;i++) {
        if (i!=s) addSon (prio,i,INF,i);
    }

    int i=0;
    while(move->next!=NULL) {
        //dodanie synów po znaczniuku move 
        struct vertex *ver = grid->adjacency_list[s].vertexes;
        while(ver!=NULL){
            
            if (grid->adjacency_list[ver->destination].is_visited==0) {
                addSon (prio,ver->destination, ver->weight+move->weight,s );
            }
            ver=ver->next;
        }
        grid->adjacency_list[move->vertex].is_visited=1;
        move = move->next;
        s = move->vertex;
    }

    int g=grid->rows*grid->columns;
    double *road = (double *)malloc(g*sizeof(double));
    int *pre = (int *)malloc(g*sizeof(int));
    for(int j=0;j<g;j++) {
        road[j]=INF;
        pre[j]=INF;
    }

    struct prioNode *prio2 =prio;
    while(prio2!=NULL) {
            if (prio2->weight<road[prio2->vertex]) {
                road[prio2->vertex]=prio2->weight;
                pre[prio2->vertex]=prio2->previous;
            }
            prio2=prio2->next;
    }

    int current = finish;
    int len = 0;
    while(current != start) {
        len++;
        current = pre[current];
    }
    int *trasa = (int *)malloc(len*sizeof(int));
    int it = 0;
    current = finish;
    while(current != start) {
        trasa[it] = current;
        current = pre[current];
        it++;
    }
    printf("Najkrotsza sciezka: \n");
    printf("%d ", start);
    for(i = len-1; i>=0; i--) {
        printf("-> %d ",trasa[i]);
    }
    printf("\n");
    printf("Dlugosc sciezki: \n");
    printf("%lf \n", road[finish]);


    while(prio != NULL) {
        struct prioNode *x =prio;
        prio = prio->next;
        free(x);
    }
    free(road);
    free(pre);
    free(trasa);
}