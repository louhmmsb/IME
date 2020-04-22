#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef celula Celula;
struct celula{
    char info;
    Celula *esq;
    Celula *dir;
};
typedef Celula No;
typedef Celula* Arvore;

int main(){
    Arvore r;
    int n, i;
    char* expressao;
    scanf("%s", expressao);
    n = strlen(expressao);
    vetor = malloc(n*sizeof(Arvore));
}
