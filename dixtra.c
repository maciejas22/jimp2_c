#include <stdio.h>
#include <stdlib.h>
#include "dixtra.h"
#include "graph.h"
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
//     struct prioNode *tmp = prio;

//     while (tmp!=h) {
//         while(h->next!=NULL) {
//             if (tmp->vertex == h->vertex) {
//                 h=h->next;
//             }
//             h=h->next;
//         }
//         tmp=tmp->next;
//     }

// }

void dixtra (struct graph *grid, int s) {
    struct prioNode *prio = initPrioNode(s,0,0);
    struct prioNode *move =prio;
    struct prioNode *tmp =prio;
    
    for (int i=0;i<grid->rows*grid->columns;i++) {
        if (i!=s) addSon (prio,i,INF,i);
    }

    //dodanie synów po znaczniuku move
    struct prioNode *h =move;
    //usuwanie powrórek z mniejszą wagą
    while (tmp!=h) {
        while(h->next!=NULL) {
            if (tmp->vertex == h->vertex) {
                h=h->next;
            }
            h=h->next;
        }
        tmp=tmp->next;
    }

    while(prio!=NULL) {
            printf("%d\t%lf\n",prio->vertex,prio->weight);
            prio=prio->next;
    }
}