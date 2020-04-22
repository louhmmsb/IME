#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
struct celula{
    int info;
    int chave;
    Celula *esq;
    Celula *dir;
};
typedef Celula No;
typedef No *Arvore;

