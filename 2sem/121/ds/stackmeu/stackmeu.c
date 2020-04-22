#include <stdio.h>
#include <stdlib.h>
#include "stackmeu.h"

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

stackp stackInit(){
  stackp s = mallocSafe(sizeof(stackNode));
  s->prox = NULL;
  return s;
}

  
int stackEmpty(stackp stack){
  int a=0;
  if (stack->prox==NULL) a=1;
  return a;
}


  
void stackPush(stackp stack, Item a){
  stackp novo = mallocSafe(sizeof(stackNode));
  novo->conteudo = a;
  novo->prox = stack->prox;
  stack->prox = novo;
}

  
Item stackPop(stackp stack){
  stackp kill;
  Item a;
  a = stack->conteudo;
  kill = stack->prox;
  stack = kill->prox;
  free (kill);
  return a;
}


  
Item stackTop(stackp stack){
  Item a;
  a = stack->conteudo;
  return a;
}



  
void stackFree(stackp stack){
  stackp kill = stack->prox;
  while (stack != NULL){
    free (stack);
    stack = kill;
    kill = stack->prox;
  }
}


  
void stackDump(stackp stack){
  stackp corre = stack;
  fprintf (stdout, "pilha: ");
  if (stack == NULL) fprintf (stdout, "vazia");
  while (corre !=NULL){
    fprintf(stdout, "%c ", corre->conteudo);
    corre = corre->prox;
  }
  fprintf (stdout, "\n");
}

