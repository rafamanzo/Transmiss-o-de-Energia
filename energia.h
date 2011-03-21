/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

/*
  red vertex are the ones that i visited
*/

#define BLUE 0
#define RED 1

int recursiveCheck(Digraph G, Vertex actual, int *flag);
int processInstance(Digraph G);
void solver();
