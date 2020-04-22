/*
 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome:Lourenço Henrique Moinheiro Martins Sborz Bogo

  stack.c
  Pitao I

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma referência, liste-as abaixo
  para que o seu programa não seja considerado plágio.

  Exemplo:
  - função mallocc retirada de: 
 
    http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/* interface para o uso de uma pilha */
#include "stack.h" 
#include <stdlib.h>
/* 
 * 
 * STACK.c: IMPLEMENTACAO DE UMA PILHA 
 *
 * TAREFA
 *
 * Faca aqui a implementacao de uma pilha atraves de uma 
 * __lista encadeada com cabeca__. 
 * 
 * A implementacao deve respeitar a interface que voce declarar em 
 * stack.h. 
 *
 */
    
stackP stackInit(){
    stackP top = (stackP)mallocSafe(sizeof *top);
    top->prox = NULL;
    return top;
}

int stackEmpty(stackP top){
    return top->prox == NULL;
}

void stackPush(Item insere, stackP top){
    stackP new = mallocSafe(sizeof *new);
    new->info = insere;
    new->prox = top->prox;
    top->prox = new;
}

stackP stackPop(stackP top){
    stackP retorno = top->prox;
    top->prox = top->prox->prox;
    return retorno;
}
    
stackP stackTop(stackP top){
    return top->prox;
}

void stackFree(stackP top){
    stackP kill;
    while (top != NULL){
	kill = top;
	top = top->prox;
	free(kill);
    }
}

void stackDump(stackP top){
    stackP print = top->prox;
    fprintf(stdout, "Pilha : ");
    if(print == NULL) fprintf(stdout, "Vazia");
    while (print != NULL){
	fprintf(stdout, "%f ", print->info->valor.vFloat);
	print = print->prox;
    }
    fprintf(stdout, "\n");
}


