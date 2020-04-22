#include <stdio.h>
#include <stdlib.h>
#include "llsc.h"

void *mallocSafe (int nbytes)
{
  void *ptr;
  ptr = malloc(nbytes);
  if (ptr == NULL){
    printf("Faltou memoria, nao aloquei nada");
    exit(EXIT_FAILURE);
  }
  return(ptr);
}

void imprime (Celula *ini)
{
  Celula *corre;
  for (corre = ini; corre != NULL; corre = corre->prox)
    printf("%d ", corre->conteudo);
}

Celula *busca (int x, Celula * ini)
{
  Celula *corre = ini;
  while (corre != NULL && corre->conteudo != x)
    corre = corre->prox;
  return corre;
}

void insere (int x, Celula ** ini)
{
  Celula *nova;
  nova = (Celula *) mallocSafe(sizeof(Celula));
  nova->prox = *ini;
  *ini = nova;
  nova->conteudo = x;
}

void removeCel (Celula *p)
{
  Celula *kill;
  kill = p->prox;
  p->prox = kill->prox;
  free(kill);
  kill = NULL;
}

void buscaInsere (Celula ** ini, int x, int y)
{
  Celula *correnaf, *correat, *nova;
  nova = (Celula *) mallocSafe(sizeof(Celula));
  nova->conteudo = x;
  if (*ini == NULL || (*ini)->conteudo == y){
    nova->prox = (*ini);
    (*ini) = nova;
  }
  else{
    correat = (*ini);
    correnaf = correat->prox;
    while (correnaf != NULL && correnaf->conteudo != y){
      correat = correnaf;
      correnaf = correnaf->prox;
    }
    correat->prox = nova;
    nova->prox = correnaf;
  }
}

void buscaRemove (int x, Celula **ini)
{
  Celula *correnaf = (*ini), *correat;
  if ((*ini) == NULL) return;
  if (correnaf->conteudo == x){
    (*ini) = (*ini)->prox;
    free (correnaf);
    correnaf = NULL;
    return;
  }
  correat = (*ini);
  correnaf = correat->prox;
  while (correnaf != NULL && correnaf->conteudo != x){
    correat = correnaf;
    correnaf = correnaf->prox;
  }
  if (correnaf != NULL){
    correat->prox = correnaf->prox;
    free (correnaf);
    correnaf = NULL;
  }
}




    
    
  
  
