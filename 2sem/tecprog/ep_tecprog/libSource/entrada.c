/*Biblioteca para ler a entrada de dados do EP e organizar os dados*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "util.h"
#ifndef XWC
#define "xwc.h"
#endif

/* Constantes para "montar o nome do arquivo */
#define DIR "fotos/imagens/"
#define EXTEN ".xpm"


void seta_variaveis (char *entrada, corpo *iniCorpos, int *t_total)
{
    int i;
    char nome[60];
    FILE *arquivo;
    corpo *novo;
    int nprojetil, duraproj;
    
    if (entrada == NULL)
    {
	printf ("Nome do arquivo para ser lido: ");
	scanf ("%s", nome);
	arquivo = fopen (nome, "r");
    }
    else 
	arquivo = fopen (entrada, "r");

    //le dados do planeta
    novo = cria_corpo (PLANETA);	
    fscanf(arquivo, "%lf %lf %lf", &(novo->obj.planet->R), &(novo->massa), t_total);
    novo->prox = iniCorpos->prox;
    iniCorpos->prox = novo;
	
    //le dados da nave 1
    novo = cria_corpo (NAVE);
    fscanf(arquivo, " %s %lf %lf %lf %lf %lf", novo->obj.nav->nome,
	   &(novo->massa), &(novo->pos.x), &(novo->pos.y),
	   &(novo->vel.x), &(novo->vel.y));
    novo->prox = iniCorpos->prox;
    iniCorpos->prox = novo;
    
    //le dados da nave 2
    novo = cria_corpo (NAVE);
    fscanf(arquivo, " %s %lf %lf %lf %lf %lf", novo->obj.nav->nome,
	   &(novo->massa), &(novo->pos.x), &(novo->pos.y),
	   &(novo->vel.x), &(novo->vel.y));    
    novo->prox = iniCorpos->prox;
    iniCorpos->prox = novo;
    
    //le dados dos projeteis iniciais
    fscanf(arquivo, "%d %lf", &nprojetil, &duraproj);
    
    i = 0;
    while (i < (nprojetil))
    {
	novo = cria_corpo (PROJETIL);
	fscanf(arquivo, "%lf %lf %lf %lf %lf", &(novo->massa),
	       &(novo->pos.x), &(novo->pos.y),
	       &(novo->vel.x), &(novo->vel.y));
	novo->prox = iniCorpos->prox;
	iniCorpos->prox = novo;	
	i++;
    }
    fclose (arquivo);
}


/*
  * seta_imagens ()
  *
  * Abastece um vetor PIC imagens[], de tamanho nImagens com as imagens.xpm do 
  * codigo solicitado.
  * Este codigo serve para nos referirmos a uma certa imagem.
  * O codigo possui formato XCCDD, onde:
  * - X define se a figura e de planeta (1), nave (2), ou projetil (3);
  * - CC define qual o conjunto de figuras
  * - DD indica a rotacao da imagem;
  *
*/
void seta_imagens (corpo * Corpo, int nImagens, int codigo)
{
    char dir[] = DIR;
    char exten[] = EXTEN;
    char *sInt;
    char *comeco;
    char *final;
    int col, lin;
    
    switch (codigo / 100)
    {
	case 3:
	    col = COL_PROJETIL;
	    lin = LIN_PROJETIL;
	    break;
	case 2:
	    col = COL_NAVE;
	    lin = LIN_NAVE;
	    break;
	case 1:
	    col = COL_PLANETA;
	    lin = LIN_PLANETA;
	    break;
	default:
	    AVISO (cria_mascara em entrada.c: codigo errado!);
	    return;
	    break;
    }

    for (int i = 0; i < nImagens; i++) 
    {

	sInt = int_strc(codigo*100+i);
	comeco = concat(dir, sInt);
	final = concat (comeco, exten);
	Corpo->mascara[i] = NewMask (TELA, col, lin);
	Corpo->imagem[i] = ReadPic (TELA, final, Corpo->mascara[i]);
	
	free (sInt);
	free(comeco);
	free(final);
    }
}   
