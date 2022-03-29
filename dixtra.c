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

// void remove(struct prioNode *prio, int h) {
//     printf("dupa");
// }

void dix(struct graph *grid, int s, int p) {
    struct prioNode *prio = initPrioNode(s,0,0);
    struct prioNode *move =prio;
    struct vertex *ver = grid->adjacency_list[s].vertexes;


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
        //printf("%d\t",move->vertex);
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

    while(prio!=NULL) {
            if (prio->weight<road[prio->vertex]) {
                road[prio->vertex]=prio->weight;
                pre[prio->vertex]=prio->previous;
            }
            //printf("%d\t%lf\t%d\n",prio->vertex,prio->weight,prio->previous);
            prio=prio->next;
    }

    for (int j=0;j<g;j++) {

        printf ("%d\t%lf\t%d\n", j,road[j], pre[j]);
    }
    int current=p;
    char * trasa;
    char baffer[20];
    while (current!=s) {
        trasa = strcat(trasa,itoa(current,baffer,10));
        current=pre[current];
    }
    printf("%s",trasa);
}