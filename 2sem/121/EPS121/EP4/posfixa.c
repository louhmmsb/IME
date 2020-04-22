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

  posfixa.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:

  - função mallocc retirada de: 

  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO
*/

/*------------------------------------------------------------*/
/* iterface para o uso da funcao deste módulo */
#include "posfixa.h"

/*------------------------------------------------------------*/
#include "categorias.h" /* Categoria, MAX_OPERADORES, INDEFINIDA, 
                           ABRE_PARENTESES, ... */
#include "objetos.h" /* tipo CelObjeto, freeObjeto(), freeListaObjetos() */
#include "stack.h"   /* stackInit(), stackFree(), stackPop() 
                        stackPush(), stackTop() */

/*-------------------------------------------------------------
 *  infixaParaPosfixa
 * 
 *  Recebe uma lista ligada com cabeca INIINFIXA representando uma
 *  fila de itens de uma expressao infixa e RETORNA uma lista ligada
 *  com cabeca contendo a fila com a representacao da correspondente
 *  expressao em notacao posfixa.
 */
 /*  As celulas da notacao infixa que nao forem utilizadas na notacao 
  *  posfixa (abre e fecha parenteses) devem ser liberadas 
  *  (freeObjeto()).
  */
CelObjeto *
infixaParaPosfixa(CelObjeto *iniInfixa)
{
    /* O objetivo do return a seguir e evitar que 
       ocorra erro de sintaxe durante a fase de desenvolvimento 
       do EP. Esse return devera ser removido depois que
       a funcao estiver pronta.
    */
    CelObjeto *kill, *percorre = iniInfixa->prox, *iniPosfixa = mallocSafe(sizeof(CelObjeto)), *percorrePos;
    stackP stack = stackInit();
    iniPosfixa->prox = NULL;
    percorrePos = iniPosfixa;
    while (percorre != NULL){
	if (percorre->categoria == 4 || percorre->categoria == 13 || percorre->categoria == 16){
	    while (!(stackEmpty(stack)) && percorre->prec <= (stackTop(stack))->prec){
		percorrePos->prox = stackPop(stack);
		percorrePos = percorrePos->prox;
	    }
	    kill = percorre;
	    percorre = percorre->prox;
	    stackPush(kill, stack);
	}
	else if (percorre->categoria>=0 && percorre->categoria<=18){
	    while (!(stackEmpty(stack)) && percorre->prec < (stackTop(stack))->prec){
		percorrePos->prox = stackPop(stack);
		percorrePos = percorrePos->prox;
	    }
	    kill = percorre;
	    percorre = percorre->prox;
	    stackPush(kill, stack);
	}
	else if(percorre->categoria == 19){
	    kill = percorre;
	    percorre = percorre->prox;
	    stackPush(kill, stack);
	}
	else if(percorre->categoria == 20){
	    kill = percorre;
	    percorre = percorre->prox;
	    freeObjeto(kill);
	    while(!(stackEmpty(stack)) && (stackTop(stack))->categoria != 19){
		percorrePos->prox = stackPop(stack);
		percorrePos = percorrePos->prox;
	    }
	    if(!stackEmpty(stack)) freeObjeto(stackPop(stack));
	}
	else {
	    kill = percorre;
	    percorre = percorre->prox;
	    percorrePos->prox = kill;
	    percorrePos = percorrePos->prox;
	}
    }
    while (!stackEmpty(stack)){
	percorrePos->prox = stackPop(stack);
	percorrePos = percorrePos->prox;
    }
    percorrePos->prox = NULL;
    freeObjeto(iniInfixa);
    return(iniPosfixa);
}
