/*Biblioteca para ler a entrada de dados do EP e organizar os dados*/

#ifndef LEITURA
#define LEITURA

#include "structs.h"
#include "simulacao.h"
/*
  Seta o ponteiro file para o arquivo que sera lido, le os dados e coloca os
  corpos no vetor corpo; 
*/
void seta_variaveis (char *entrada, corpo *iniCorpos, int * t_total);

/*
  Obtem os arquivos xpm correspondentes para desenhar os objetos na tela 
  e tambem cria a mascara para cada imagem
*/
void seta_imagens (corpo * Corpo, int nImagens, int codigo); 

#endif /* LEITURA */
