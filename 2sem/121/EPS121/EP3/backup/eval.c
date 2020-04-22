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

  eval.c
  Pitao I

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma referência, liste-as abaixo
  para que o seu programa não seja considerado plágio.
  Exemplo:
  - função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO
*/

/*------------------------------------------------------------*/
/* interface para as funcoes deste modulo */
#include "eval.h" 

/*------------------------------------------------------------*/
#include <stdlib.h>  /* atoi(), atof() */
#include <string.h>  /* strncmp(), strlen(), strncpy(), strcpy(), strcmp() */
#include <math.h>    /* pow() */

/*------------------------------------------------------------*/
#include "categorias.h" /* Categoria, MAX_OPERADORES */
#include "util.h"       /* ERRO(), AVISO(), mallocSafe() */
#include "objetos.h"    /* CelObjeto, mostreObjeto(), freeObjeto()
                           mostreListaObjetos(), 
                           freeListaObjetos() */

#include "stack.h"      /* funcoes que manipulam uma pilha */ 
                        /* essa pilha sera usada para implementar 
                           a pilha de execucao */


/*------------------------------------------------------------*/
/* Protipos de funcoes auxiliares */

/*------------------------------------------------------------*/
/* Tabela com uma representacao da precedencia dos operadores
 * atraves de valores inteiros. 
 * Quanto maior o valor, maior a precedencia.
 *
 *  http://www.ime.usp.br/~pf/algoritmos/apend/precedence.html
 */
static const int precedencia[MAX_OPERADORES] =
{
    /* 4 operadores relacionais com 2 simbolos  */
     4   /* "==" */ /* da esquerda para a direita */
    ,4   /* "!=" */ /* da esquerda para a direita */
    ,5   /* ">=" */ /* da esquerda para a direita */
    ,5   /* "<=" */ /* da esquerda para a direita */
    
    /* 2 operadores aritmeticos com 2 simbolos */
    ,8 /* ,"**" */ /* da direita para a esquerda */
    ,7 /* ,"//" */ /* da esquerda para a direita */
 
    /* 2 operadores relacionais com 1 simbolo */
    ,5  /* ">"  */ /* da esquerda para a direita */
    ,5  /* "<"  */ /* da esquerda para a direita */ 
    
    /* 6 operadores aritmeticos */
    ,7  /* "%" */ /* da esquerda para a direita */
    ,7  /* "*" */ /* da esquerda para a direita */
    ,7  /* "/" */ /* da esquerda para a direita */
    ,6  /* "+" */ /* da esquerda para a direita */
    ,6  /* "-" */ /* da esquerda para a direita */
    ,8  /* "_" */ /* da direita para a esquerda */
    
    /* 3 operadores logicos  */
    ,3  /* "and" */ /* da esquerda para a direita */ 
    ,2  /* "or" */ /* da esquerda para a direita */
    ,8  /* "not"  */ /* da direita para a esquerda */
    
    /* operador de indexacao */
    ,9  /* "$"  */ /* da esquerda para a direita (IGNORAR)*/

    /* atribuicao */ 
    ,1  /* "=" */ /* da direita para a esquerda EP4 */ 
}; 

/*-------------------------------------------------------------
 *  itensParaValores
 *  
 *  RECEBE uma lista ligada com cabeca INIFILAITENS representando uma
 *  fila de itens lexicos. Inicialmente, o campo VALOR de cada celula
 *  contem um string com o item lexico.
 *
 *  A funcao CONVERTE o campo VALOR de cada celula para um inteiro 
 *  ou double, como descrito a seguir. 
 *
 *  IMPLEMENTACAO
 *
 *  O campo VALOR de uma CelObjeto tem 3 subcampos:
 *
 *      - valor.vInt   (int)
 *      - valor.vFloat (float)
 *      - valor.pStr   (string)
 *
 *  Nessa conversao, o campo VALOR de cada celula recebe um valor 
 *  da seguinte maneira.
 *
 *     - Se o campo CATEGORIA da celula indica que o item e' um
 *       string representando um int (INT_STR) entao o campo 
 *       valor.vFloat deve receber esse numero inteiro. 
 *
 *       Nesse caso a CATEGORIA do item deve ser alterada para 
 *       FLOAT.
 *
 *     - se o campo CATEGORIA da celula indica que o item e' um
 *       string representando um float (FLOAT_STR) entao o campo 
 *       valor.vFloat deve receber esse float;
 *
 *       Nesse caso a CATEGORIA do item deve ser alterada para 
 *       FLOAT.
 *
 *     - se o campo CATEGORIA da celula indica que o item e' um
 *       string representando um Bool (BOOL_STR) entao o campo 
 *       valor.vFloat deve receber o inteiro correspondente 
 *       (False = 0, True = 1);
 *
 *       Nesse caso a CATEGORIA do item deve ser alterada para 
 *       FLOAT.
 *
 *     - se o campo CATEGORIA da celula indica que o item e' um
 *       string representando um operador (OPER_*) entao o campo 
 *       valor.vInt deve receber o inteiro correspondente 
 *       a precedencia desse operador. 
 *       
 *       Para isto utilize o vetor PRECEDENCIA declarado antes 
 *       desta funcao. 
 *
 * Nesta funcao (e nas outras) voce pode utilizar qualquer funcao da
 * biblioteca string do C, como, por exemplo, atoi(), atof().
 *
 * Esta funcao (e todas as outras) devem 'dar' free nas estruturas que
 * deixarem de ser necessarias.
 *
 * Esse e o caso dos strings dos itens das categorias FLOAT_STR e INT_STR.  
 *
 * Os campos strings de objetos OPER_* e BOOL_STR apontam para
 * strings em tabelas definidas no modulo lexer.h.  Nesse
 * caso, tentar liberar essa memoria e' um erro.
 *
 */

void
itensParaValores(CelObjeto *iniFilaItens)
{
    CelObjeto *percorre = iniFilaItens->prox;
    double save;
    while(percorre != NULL){
	if(percorre->categoria == INT_STR || percorre->categoria == FLOAT_STR){
	    save = atof(percorre->valor.pStr);
	    free(percorre->valor.pStr);
	    percorre->valor.vFloat = save;
	    percorre->categoria = FLOAT;
	}
	else if(percorre->categoria == BOOL_STR){
	    if(strcmp(percorre->valor.pStr, "False") == 0)
		percorre->valor.vFloat = 0;
	    else
		percorre->valor.vFloat = 1;
	    percorre->categoria = FLOAT;
	}
	else if(percorre->categoria>=0 && percorre->categoria<=18)
	    percorre->valor.vInt = precedencia[percorre->categoria];
	percorre = percorre->prox;
    }
}

/*-------------------------------------------------------------
 * eval
 * 
 * RECEBE uma lista ligada como cabeca INIPOSFIXA que representa
 * uma expressao em notacao posfixa. 
 *
 * RETORNA o endereco de uma celula com o valor da expressao.
 *
 * PRE-CONDICAO: a funcao supoe que a expressao esta' sintaticamente
 *               correta.
 *
 * IMPLEMENTACAO
 *
 * Para o calculo do valor da expressao, deve ser usada uma pilha. 
 * O endereco retornado sera' o da celula no topo no topo dessa  
 * "pilha de execucao".
 * 
 * A funcao percorre a expressao calculando os valores resultantes.
 * Para isto e' utilizada uma pilha de execucao. 
 * 
 * A implementacao das funcoes que manipulam a pilha devem ser
 * escritas no modulo stack.c.
 * 
 * O arquivo stack.h contem a interface para essas funcoes. 
 * A pilha de execucao so deve ser acessada atraves dessa interface
 * (caso contrario nao chamariamos stack.h de interface).
 * 
 * O parametro mostrePilhaExecucao indica se os valores
 * na pilha de execucao devem ser exibidos depois de qualquer 
 * alteracao.
 * 
 * Esta funcao deve "dar free" nas estruturas que deixarem de ser 
 * necessarias.
 *
 */

CelObjeto *
eval (CelObjeto *iniPosfixa, Bool mostrePilhaExecucao)
{
    CelObjeto *percorre = iniPosfixa->prox, *kill;
    stackP stack = stackInit();
    stackP pop1, pop2;
    while(percorre != NULL){
	kill = NULL;
	pop1 = NULL;
	if(mostrePilhaExecucao == 1) stackDump(stack);
	switch(percorre->categoria){
	case OPER_IGUAL:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop1->info->valor.vFloat == pop2->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_DIFERENTE:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop1->info->valor.vFloat != pop2->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_MAIOR_IGUAL:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat >= pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_MENOR_IGUAL:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat <= pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_EXPONENCIACAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pow(pop2->info->valor.vFloat, pop1->info->valor.vFloat));
	    kill = percorre;
	    break;
	case OPER_DIVISAO_INT:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (((int)pop2->info->valor.vFloat)/((int)pop1->info->valor.vFloat));
	    kill = percorre;
	    break;
	case OPER_MAIOR:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat > pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_MENOR:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat < pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_RESTO_DIVISAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (((int)pop2->info->valor.vFloat) % ((int)pop1->info->valor.vFloat));
	    kill = percorre;
	    break;
	case OPER_MULTIPLICACAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat * pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_DIVISAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat/pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_ADICAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = pop2->info->valor.vFloat + pop1->info->valor.vFloat;
	    kill = percorre;
	    break;
	case OPER_SUBTRACAO:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat - pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_MENOS_UNARIO:
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = -(pop2->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_LOGICO_AND:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat && pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_LOGICO_OR:
	    pop1 = stackPop(stack);
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = (pop2->info->valor.vFloat || pop1->info->valor.vFloat);
	    kill = percorre;
	    break;
	case OPER_LOGICO_NOT:
	    pop2 = stackPop(stack);
	    pop2->info->valor.vFloat = !(pop2->info->valor.vFloat);
	    kill = percorre;
	    break;
	case FLOAT:
	    stackPush(percorre, stack);
	    break;
	default:
	    break;
	}
	if(pop1 != NULL && pop1->info != NULL) freeObjeto(pop1->info);
	percorre = percorre->prox;
	if (kill != NULL){
	    stackPush(pop2->info, stack);
	    freeObjeto(kill);
	}
    }
    iniPosfixa->prox = NULL;
    if(stackEmpty(stack)) return NULL;
    pop1 = stackPop(stack);
    stackFree(stack);
    return pop1->info;
}
