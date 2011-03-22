####################################
## MAC0328 - Algoritmos em grafos ##
##                                ##
## rafamz                         ##
## macacada                       ##
## Rafael Reggiani Manzo          ##
## 6797150                        ##
####################################

#argumentos de compilacao
CFLAGS = -ansi -pedantic -Wall -g

#headers
ED = ed/arc.h ed/digraph.h ed/vertex.h

Energia: digraph.o graph.o main.o io.o energia.o
	gcc arc.o graph.o digraph.o main.o io.o energia.o -o Energia

energia.o: energia.c energia.h graph.o
	gcc -c energia.c $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

arc.o: ed/vertex.h ed/arc.h ed/arc.c
	gcc -c ed/arc.c $(CFLAGS)

digraph.o: ed/vertex.h arc.o ed/digraph.h ed/digraph.c
	gcc -c ed/digraph.c $(CFLAGS)

graph.o: ed/vertex.h digraph.o ed/graph.h ed/graph.c 
	gcc -c ed/graph.c $(CFLAGS)

io.o: ed/vertex.h ed/digraph.h io.h io.c
	gcc -c io.c $(CFLAGS)

clean:
	rm *.o
	rm Energia
