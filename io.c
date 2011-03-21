/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

#include <stdio.h>
#include <stdlib.h>
#include "ed/vertex.h"
#include "ed/digraph.h"
#include "io.h"

Digraph inputInstance(){
  Digraph G;
  int in1, in2;
  int relations, i;

  if(scanf("%d %d", &in1, &in2) == EOF){
    return NULL;
  }

  G = DIGRAPHinit(in1 + 1);
  relations = in2;

  for(i = 0; i < relations; i++){
    scanf("%d %d", &in1, &in2);
    DIGRAPHinsertA(G, in1, in2);
  }

  return G;  
}

void outInstance(int instance, int response){
  printf("Teste %d", instance);
  if(response == 1){
    printf("\nnormal\n\n");
  }else if(response == 0){
    printf("\nfalha\n\n");
  }
}
