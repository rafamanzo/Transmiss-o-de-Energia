/**********************************/
/* MAC0328 - Algoritmos em grafos */
/*                                */
/* rafamz                         */
/* macacada                       */
/* Rafael Reggiani Manzo          */
/* 6797150                        */
/**********************************/

/***********************************************/
/* Compilado com:                              */
/* gcc main.c -o Energia -ansi -Wall -pedantic */
/***********************************************/

#include<stdlib.h>
#include<stdio.h>

/*vertex.h*/
#define Vertex int

/*digraph.h*/
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

/*graph.h*/
#define GRAPHinit DIGRAPHinit
#define GRAPHdestroy DIGRAPHdestroy
#define GRAPHshow DIGRAPHshow
#define GRAPHpath DIGRAPHpath
#define Graph Digraph

void GRAPHinsertE(Graph G, Vertex v, Vertex w);
void GRAPHremoveE(Graph G, Vertex v, Vertex w);

/*io.h*/
Graph inputInstance();
void outInstance(int instance, int response);

/*energia.h*/
int processInstance(Graph G);
void solver();

/*digraph.c*/
int *lbl;

void lblInit(){
  lbl = malloc(MAXVERTEX*sizeof(int));

  lblReset();
}

void lblReset(){
  int i;

  for(i = 0; i < MAXVERTEX; i++){
    lbl[i] = -1;
  }  
}

void lblDestroy(){
  free(lbl);
}

Digraph DIGRAPHinit(int vertexCount){
  Digraph G;

  G = malloc(sizeof(struct digraph));
  G->V = vertexCount;
  G->A = 0;
  G->adj = MATRIXint(vertexCount, vertexCount, 0);

  return G;
}

void DIGRAPHdestroy(Digraph G){
  int i;

  for(i = 0; i < G->V; i++){
    free(G->adj[i]);
  }

  free(G->adj);
  free(G);
}

int ** MATRIXint(int r, int c, int val){
  int **m;
  int i, j;

  m = malloc(r*sizeof(int *));

  for(i = 0; i < r; i++){
    m[i] = malloc(c*sizeof(int));
    for(j = 0; j < c; j++){
      m[i][j] = val;
    }
  }
  
  return m; 
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w){
  if(G->adj[v][w] == 0 && v != w){
    G->adj[v][w] = 1;
    G->A++;
  }
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w){
  if(G->adj[v][w] == 1 && v != w){
    G->adj[v][w] = 0;
    G->A--;
  }
}

void DIGRAPHshow(Digraph G){
  int i,j;

  for(i = 0; i < G->V; i++){
    printf("\n%d:",i);
    for(j = 0; j < G->V; j++){
      if(G->adj[i][j] == 1){
        printf(" %d", j);
      }
    }
  }
}

int DIGRAPHpath(Digraph G, Vertex s, Vertex t){
  lblReset();

  pathR(G,s);

  if(lbl[t] == -1){
    return 0;
  }else{
    return 1;
  }
}

void pathR(Digraph G, Vertex v){
  int i;

  lbl[v] = 1;
  
  for(i = 0; i < G->V; i++){
    if(G->adj[v][i] == 1 && lbl[i] == -1){
      pathR(G, i);
    }
  }
}

/*graph.c*/
void GRAPHinsertE(Graph G, Vertex v, Vertex w){
  DIGRAPHinsertA(G, v, w);
  DIGRAPHinsertA(G, w, v);
}

void GRAPHremoveE(Graph G, Vertex v, Vertex w){
  DIGRAPHremoveA(G, v, w);
  DIGRAPHremoveA(G, w, v);
}

/*io.c*/
Graph inputInstance(){
  Graph G;
  int in1, in2;
  int relations, i;

  if(scanf("%d %d", &in1, &in2) == EOF){
    return NULL;
  }

  if(in1 <= 0 || in2 <= 0){
    return NULL;
  }

  G = GRAPHinit(in1 + 1);
  relations = in2;

  for(i = 0; i < relations; i++){
    scanf("%d %d", &in1, &in2);
    GRAPHinsertE(G, in1, in2);
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

/*energia.c*/
void solver(){
  int instance;
  Graph G;

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

/*main.c*/
int main(int argc, const char* argv[]){
  solver();
  return 0;
}

