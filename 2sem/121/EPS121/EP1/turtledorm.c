/*\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: Lourenco Henrique Moinheiro Martins Sborz Bogo
  NUSP:11208005

  ep1.c

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:

  - função randomInteger() de: 

  http://www.ime.usp.br/~pf/algoritmos/aulas/random.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

/*
 *  Sobre os nomes da variaveis:
 *
 *  Adotamos a especificacao das variaveis em (lower) "camel case":
 * 
 *       http://en.wikipedia.org/wiki/Camel_case
 *
 *  Sobre as especificações das funções:
 *
 *  Nos protótipos das funções, os nomes dos parametros
 *  seguem o padrao camel case. No entanto, nas especificações,
 *  esses nomes aparecem vertidos para maiúsculas para destacar 
 *  o papel de cada parâmetro. Isso corresponde a recomendacao do 
 *  GNU Coding Standards:
 *
 *       http://www.gnu.org/prep/standards/standards.html#Comments
 */

#include <stdio.h>  /* scanf(), printf(), ... */
#include <stdlib.h> /* srand(), rand(), atoi(), exit(), ...  */
#include <string.h> /* strlen(), strcmp(), ... */  

/*---------------------------------------------------------------*/
/* 
 * 0. C O N S T A N T E S 
 */

/* tamanho máximo de um turtledorm */
#define MAX      128

/* estado da turtle */
#define ACORDADO   '#'
#define DORMINDO   ' '
#define TAPINHA    'T'

#define TRUE       1
#define FALSE      0

#define ENTER      '\n'
#define FIM        '\0'
#define ESPACO     ' '

/*---------------------------------------------------------------*/
/*
 * 1. P R O T Ó T I P O S
 */

/* PARTE I */
void
leiaTurtledorm(int *nLin, int *nCol, int tDorm[][MAX]);

void
printaMoldura(int nCol);

void 
mostreTurtledorm(int nLin, int nCol, int tDorm[][MAX], char c);

void
tapinhaTurtle(int nLin, int nCol, int tDorm[][MAX], int lin, int col);

int 
todosDormindo(int nLin, int nCol, int tDorm[][MAX]);

int
graveTurtledorm(int nLin, int nCol, int tDorm[][MAX]);

/* PARTE II */
void
sorteieTurtledorm(int *nLin, int *nCol, int tDorm[][MAX]);

/* PARTE III */

void
resolvaTurtledorm(int nLin, int nCol, int tDorm[][MAX]);

/* FUNÇõES AUXILIARES */
int 
randomInteger(int low, int high);

void 
pause();

int
pot(int base, int expo);

void copiaMatriz(int M1[MAX][MAX], int M2[MAX][MAX]);

void incremente(int bin[]);


/*---------------------------------------------------------------*/
/* 
 *  M A I N 
 */
 
 /* 
 * main()
 *
 * A main pergunta se o player quer um tabuleiro novo ou se quer carregar um de um save e tambem pergunta 
 * o que o player quer fazer em cada jogada. Caso o player digite "d" o jogo fala quantos tapinhas o player deu
 * e encerra o programa. Caso ele digite "g" o turtledorm atual � gravado em um arquivo para poder ser usado depois.
 * Se o jogo n�o conseguir gravar o turtledorm, ele printa uma mansagem de erro. Se o player digitar dois numeros inteiros, lin e col,
 * o jogo da um tapinha na posicao lin x col. Se o player digitar "a" ser� printado na tela onde ele tem q dar tapinhas para resolver o
 * turtle dorm atual. Quando todas as tartarugas estiverem dormindo, o jogo printa uma mensagem de vitoria e encerra o programa.
 */
int 
main(int argc, char *argv[]){
	int nLin, nCol, tDorm[MAX][MAX], i, j, linha, coluna, nTapinhas=0, save;
	char soul, cjogL[3], cjogC[3];

	for(i=0; i<128; i++){
		for(j=0; j<128; j++){
			tDorm[i][j]=0;
		}
	}
	printf("Voce quer (s)ortear ou (l)er o turtledorm de arquivo: ");
	scanf("%c", &soul);
	if (soul=='s'){
		sorteieTurtledorm(&nLin, &nCol, tDorm);
	}
	if(soul=='l'){
		leiaTurtledorm(&nLin, &nCol, tDorm);
	}
	printf("Um tapinha e definido por dois numeros inteiros\n");
	while(todosDormindo(nLin, nCol, tDorm)==FALSE){
		mostreTurtledorm(nLin, nCol, tDorm, ACORDADO);
		printf("Digite 'd' para (d)esistir,\n'a' para receber (a)juda para encontrar uma solucao,\n'g' para (g)ravar o turtledorm atual,\n ou'lin col' para dar um tapinha na posicao [lin][col].\n O que voce quer fazer: ");
		scanf("%s", cjogL);
		if(cjogL[0]=='d'){
			printf("Desta vez nao deu\nVoce deu %d tapinhas", nTapinhas);	
			return (0);
		}
		else if(cjogL[0]=='a'){
			resolvaTurtledorm(nLin,nCol,tDorm);
		}
		else if(cjogL[0]=='g'){
			save=graveTurtledorm(nLin, nCol, tDorm);
			if(save==EXIT_FAILURE) printf("ERRO, NAO SALVOU. TENTE DENOVO");
		}
		else{
			linha=atoi(cjogL)-1;
			scanf(" %s", cjogC);
			coluna=atoi(cjogC)-1;
			nTapinhas++;
			tapinhaTurtle(nLin, nCol, tDorm, linha, coluna);
		}
	}
	if(todosDormindo(nLin, nCol, tDorm)==TRUE){
		mostreTurtledorm(nLin, nCol, tDorm, ACORDADO);
		printf("Parabens voce ganhou!\nVoce deu %d tapinhas", nTapinhas);
	} 
    return EXIT_SUCCESS;
}

/*---------------------------------------------------------------*/
/* 
 *  I M P L E M E N T A Ç Ã O   D A S   F U N Ç Õ E S   DA  
 *                        P A R T E   I 
 */

/*
 *leiaTurtledorm()
 *
 * Le uma matriz de tamanho nLin x nCol e coloca ela em tDorm 
 */ 
void
leiaTurtledorm(int *nLin, int *nCol, int tDorm[MAX][MAX]){
	int i, j;
	char file_name[MAX];
	FILE *arquivo;
	
	printf("Qual o nome do arquivo:");
	scanf("%s", file_name);
	arquivo=fopen(file_name, "r");
	fscanf(arquivo, "%d %d", nLin, nCol);
	for(i=0; i<*nLin; i++){
		for(j=0; j<*nCol; j++){
			fscanf(arquivo, "%d", &tDorm[i][j]);
		}
	}
}
 
 /* 
 * mostreTurtledorm()
 *
 * Printa o turtledorm nLin x nCol. Caso o char c seja ACORDADO, o programa printa o tabuleiro com "#" onde 
 * tem turtles acordadas. Caso ele seja TAPINHA o programa printa T onde tem turtles acordadas.
 *  
 */
void 
mostreTurtledorm(int nLin, int nCol, int tDorm[][MAX], char c){
	int i, j;
	printf("      ");
	for(j=0; j<nCol; j++){
		printf("%3d", j+1);
		printf("   ");
	}
	printf("\n");
	printaMoldura(nCol);
	printf("\n");
	for(i=0; i<nLin; i++){
		printf("%3d |", i+1);
		for(j=0; j<nCol; j++){
			if (tDorm[i][j]==1) printf("  %c  |", c);
			else printf("     |");
		}
		printf("\n");
		printaMoldura(nCol);
		printf("\n");
	}
}

/* 
 * tapinhaTurtle()
 *
 * Da um tapinha na posicao lin x col.
 */
void
tapinhaTurtle(int nLin, int nCol, int tDorm[][MAX], int lin, int col){
	tDorm[lin][col]=(tDorm[lin][col]+1)%2;
	if(lin+1<=nLin) tDorm[lin+1][col]=(tDorm[lin+1][col]+1)%2;
	if(lin-1>=0) tDorm[lin-1][col]=(tDorm[lin-1][col]+1)%2;
	if(col+1<=nCol) tDorm[lin][col+1]=(tDorm[lin][col+1]+1)%2;
	if(col-1>=0) tDorm[lin][col-1]=(tDorm[lin][col-1]+1)%2;
}

/* 
 * todosDormindo()
 *
 * Retorna true se todas as turtles estiverem dormindo e false caso contr�rio.
 */
int 
todosDormindo(int nLin, int nCol, int tDorm[MAX][MAX]){
	int i, j, cont=TRUE;
	for(i=0; i<nLin && cont==TRUE; i++){
		for(j=0; j<nCol && cont==TRUE; j++){
			if(tDorm[i][j]==1) cont=FALSE;
		}
	}
	return(cont);
}

/* 
 * graveTurtledorm()
 *
 * Grava o tabuleiro em um arquivo cujo nome e dado pelo player.
 */
int
graveTurtledorm(int nLin, int nCol, int tDorm[][MAX]){
	int i, j;
	char nomedosave[MAX];
	FILE *save;	

	printf("Nome do arquivo do save: ");
	scanf("%s", nomedosave);
	save=fopen(nomedosave, "w");
	if(save==NULL) return EXIT_FAILURE;
	fprintf(save, "%d %d\n", nLin, nCol);
	for(i=0; i<nLin; i++){
		for(j=0; j<nCol; j++){
			fprintf(save, "%d ", tDorm[i][j]);
		}
		fprintf(save, "\n");
	}
	return EXIT_SUCCESS;
}

/*---------------------------------------------------------------*/
/* 
 *  I M P L E M E N T A Ç Ã O   D A S   F U N Ç Õ E S   DA  
 *                       P A R T E   II 
 */
 
 /* 
 * sorteieTurtledorm()
 *
 * Sorteia uma matriz de tamanho nLin x nCol. A fun�ao ppega um tabuleiro zerado e da um numero de tapinhas nele
 * proporcional a dificuldade. Apos isso ele printa o numero de tapinhas dados e o numero de tartarugas que estao acordadas. 
 */
void
sorteieTurtledorm(int *nLin, int *nCol, int tDorm[MAX][MAX]){
	int semente, nTapinhas, i, j, lin, col, acordadas=0, min, max;
	char dificuldade;
	printf("Qual a dimensao do turtledorm?(Dois numeros inteiros)");
	scanf("%d %d", nLin, nCol);
	printf("Qual a semente para o sorteio?(Outro numero inteiro)");
	scanf("%d", &semente);
	srand(semente);
	printf("Qual o nivel de dificuldade?(f/m/d)");
	scanf(" %c", &dificuldade);
	if (dificuldade=='f'){
		min=(int)(5*(*nLin)*(*nCol)/100);
		max=(int)(20*(*nLin)*(*nCol)/100);
		nTapinhas=randomInteger(min, max);
	}
	if (dificuldade=='m'){
		min=(int)(25*(*nLin)*(*nCol)/100);
		max=(int)(50*(*nLin)*(*nCol)/100);
		nTapinhas=randomInteger(min, max);
	}
	if (dificuldade=='d'){
		min=(int)(55*(*nLin)*(*nCol)/100);
		max=(int)(85*(*nLin)*(*nCol)/100);
		nTapinhas=randomInteger(min, max);
	}
	for (i=0; i<nTapinhas; i++){
		lin=randomInteger(0, *nLin-1);
		col=randomInteger(0, *nCol-1);
		tapinhaTurtle(*nLin, *nCol, tDorm, lin, col);
	}
	printf("O numero de tapinhas dados foi: %d \n", nTapinhas);
	for(i=0; i<*nLin; i++){
		for(j=0; j<*nCol; j++){
			if(tDorm[i][j]==1) acordadas++;
		}
	}
	printf("%d tartarugas estao acordadas\n", acordadas);
}

/*---------------------------------------------------------------*/
/* 
 *  I M P L E M E N T A Ç Ã O   D A S   F U N Ç Õ E S   DA  
 *                       P A R T E   III 
 */

/* 
 * resolvaTurtledorm()
 *
 * Essa funcao resolve o turtledorm usando o algoritmo "Chase the lights". Esse algoritmo diz que 
 * se voce der tapinhas nas pocicoes i x j do tabuleiro, onde (i-1) x j e uma posicao com um turtle desperto,
 * quando voce chegar no final desse processo dependendo do jeito que a ultima linha ficar, existe ou nao uma
 * combinacao de tapinhas na primeira linha tal que o tabuleiro ira estar resolvido caso se aplique o algortimo do comeco novamente.
 * A funcao, a partir dessa ideia, chuta todas as combinacoes possiveis de tapinhas na primeira linha e depois aplica o algortimo.
 * Caso o tabuleiro se reolva a solucao e comparada com a atual melhor solucao (que foi achada do mesmo jeito) e caso ela seja melhor
 * ela e guardada em uma matriz para ser printada para o player.
 */
void
resolvaTurtledorm(int nLin, int nCol, int tDorm[][MAX]){
	int tDormtest[MAX][MAX], tapinhas[MAX][MAX], melhor[MAX][MAX], tap, tapMax=10000, *bits, i, j, cont, existe=0;
	bits=(int*)malloc((nCol+1)*(sizeof(int)));
	for(i=0; i<nCol+1; i++){
		bits[i]=0;
	}
	for(cont=0; cont<pot(2, nCol); cont++){
		copiaMatriz(tDorm, tDormtest);
		tap=0;
		for(i=0; i<nCol; i++){
			if(bits[i]==1){
				tapinhaTurtle(nLin, nCol, tDormtest, 0, i);
				tapinhas[0][i]=1;
				tap++;
			} 
		}
		for(i=1; i<nLin; i++){
			for(j=0; j<nCol; j++){
				if(tDormtest[i-1][j]==1){
					tapinhaTurtle(nLin, nCol, tDormtest, i, j);
					tap++;
					tapinhas[i][j]=1;
				} 
			}
		}
		if(todosDormindo(nLin, nCol, tDormtest)==TRUE && tap<tapMax){
			tapMax=tap;
			copiaMatriz(tapinhas, melhor);
			existe=1;
		}
		for(i=0; i<MAX; i++){
			for(j=0; j<MAX; j++){
				tapinhas[i][j]=0;
			}
		}
		incremente(bits);
	}	
	free(bits);
	if(existe==1){
		printf("A solucao perfeita e:\n");
		mostreTurtledorm(nLin, nCol, melhor, TAPINHA);
		printf("Foram dados %d tapinhas na solucao.\n", tapMax);
	}
	else printf("Esse tabuleiro nao tem solucao.\n");
}
 
/*---------------------------------------------------------------*/
/* 
 *  I M P L E M E N T A Ç Ã O   D A S   F U N Ç Õ E S   DA  
 *                     A U X I L I A R E S 
 */

/* 
 * randomInteger()
 *
 * A função recebe dois inteiros LOW e HIGH e retorna um 
 * inteiro aleatório entre LOW e HIGH inclusive, ou seja, 
 * no intervalo fechado LOW..HIGH.
 *
 * Pré-condição: a função supõe que 0 <= LOW <= HIGH < INT_MAX.
 *     O codigo foi copiado da página de projeto de algoritmos 
 *     de Paulo Feofiloff, que por sua vez diz ter copiado o 
 *     código da biblioteca random de Eric Roberts.
 */
int 
randomInteger(int low, int high)
{
    int k;
    double d;
    d = (double) rand( ) / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

/* 
 * pause()
 *
 * Para a execucao do programa ate que um ENTER seja digitado.
 */
void 
pause()
{
    char ch;
    printf("Digite ENTER para continuar. ");
    do 
    {
        scanf("%c", &ch);
    }
    while (ch != ENTER);
}

/*
 * pot()
 *
 * Eleva a base ao expo
 */ 
int
pot(int base, int expo){
	int i, baseI=base;
	for(i=1; i<expo; i++){
		base=base*baseI;
	}
	return(base);
}

/*
 * copiaMatriz()
 *
 * Copia a matriz M1 em M2
 */ 
void 
copiaMatriz(int M1[MAX][MAX], int M2[MAX][MAX]){
	int i, j;
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			M2[i][j]=M1[i][j];
		}
	}
}

/*
 * incremente()
 *
 * Funcao pega do codigo tapinhas.c da prof. Cristina Gomes Fernandes do BCC-IME-USP
 */ 
void
incremente(int bin[])
{
    int i;
    for (i = 0; bin[i] != 0; i++)
        bin[i] = 0;
    bin[i] = 1;
}

/*
 * printaMoldura()
 *
 * Printa a moldura do tabuleiro 
 */ 
void
printaMoldura(int nCol){
	int j;
	printf("    +");
	for(j=0; j<nCol; j++){
		printf("-----+");
	}
}



