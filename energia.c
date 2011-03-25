/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

#include<stdlib.h>
#include "ed/vertex.h"
#include "ed/digraph.h"
#include "ed/graph.h"
#include "io.h"
#include "energia.h"

void solver(){
  int instance;
  Digraph G;

  lblInit();
  instance = 1;
  G = inputInstance();
  while(G != NULL){
    outInstance(instance, processInstance(G));
    instance++;
    GRAPHdestroy(G);
    G = inputInstance();
  }
  lblDestroy();
}

int processInstance(Digraph G){
  int i, j;

  for(i = 1; i < G->V; i++){
    if(i + 1 < G->V){
      GRAPHpath(G, i, i + 1);
      for(j = 1; j < G->V; j++)
        if(lbl[j] == -1)
          return 0;
    }
  }
  return 1;

}
