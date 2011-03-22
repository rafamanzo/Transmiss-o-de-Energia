/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

#define MAXVERTEX 101

struct digraph{
  int V;
  int A;
  int **adj;
};

typedef struct digraph *Digraph;

void lblInit();
void lblReset();
void lblDestroy();
Digraph DIGRAPHinit(int vertexCount);
void DIGRAPHdestroy(Digraph G);
int** MATRIXint(int r, int c, int val);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
int DIGRAPHpath(Digraph G, Vertex s, Vertex t);
void pathR(Digraph G, Vertex v);
