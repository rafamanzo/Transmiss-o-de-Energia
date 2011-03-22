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
    for(j = i + 1; j < G->V; j++){
      if(!GRAPHpath(G, i, j)){
        return 0;
      }
    }
  }
  return 1;

}
