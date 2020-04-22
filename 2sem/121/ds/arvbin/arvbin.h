#include <stdio.h>
#include <stdlib.h>
typedef int item;

typedef struct no No;
struct no {
    item info;
    No *esq;
    No *dir;
    No *pai;
};
typedef No *Arvore;

void imprime(No *);

void inOrdem(No *);

void posOrdem(No *);
