#include <stdio.h>
#include <stdlib.h>
#include <fila.h>

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

static queuep ini, fim;

static queuep new(Item item, queuep next){
  queuep new = mallocSafe(sizeof(queueNode));
  new->conteudo = item;
  new->prox = next;
  return new;
}

void queueInit(){
  ini = NULL;
}

int queueEmpty(){
  return ini == NULL;
}

void queuePut (Item item){
  if (ini == NULL){
    ini = fim = new(item, NULL);
    return;
  }
  fim->prox = new(item, NULL);
  fim = fim->prox;
}


Item queueGet(){
  queuep kill;
  Item item;
  kill = ini;
  ini = ini->prox;
  item = kill->conteudo;
  free(kill);
  return item;
}

void freeQueue(){
  queuep kill;
  while (ini != NULL){
    kill = ini;
    ini = ini->prox;
    free(kill);
  }
}
