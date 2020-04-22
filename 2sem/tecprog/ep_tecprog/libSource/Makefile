CC=gcc

INCLUDEDIR=-I../include/

.PHONY: all 
all: entrada.o fisica.o vetores.o simulacao.o xwc.o util.o structs.o

entrada.o : entrada.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
fisica.o : fisica.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
vetores.o : vetores.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
simulacao.o : simulacao.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
xwc.o : xwc.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
util.o : util.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g
structs.o : structs.c
	$(CC) -c $< $(INCLUDEDIR) -o $@ -g

