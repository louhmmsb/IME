/* Declaração das funções e estruas responsáveis por 
 * simular um frame do jogo 
 *
 * Pressupõe que os vetores tem a mesma base ortonormal 
 */

#ifndef SIMULACAO
#define SIMULACAO

#include "structs.h"

#ifndef XWC
#define XWC
#include "xwc.h"
#endif

/* Tamanho de um arquivo .xpm que contem a imagem de um PROJETIL */
#define COL_PROJETIL 12
#define LIN_PROJETIL 12

/* Tamanho de um arquivo .xpm que contem a imagem de uma NAVE */
#define COL_NAVE 32
#define LIN_NAVE 32

/* Tamanho de um arquivo .xpm que contem a imagem de um PLANETA */
#define COL_PLANETA 112
#define LIN_PLANETA 112

/* Tamanho da janela do jogo */
#define WIDTH 500
#define HEIGHT 500

/* Teclas que os jogadores poderao usar */
#define A_KEY 0
#define W_KEY 1
#define D_KEY 2
#define S_KEY 3
#define RIGHT_KEY 4
#define UP_KEY 5
#define LEFT_KEY 6
#define DOWN_KEY 7
static int keyPressed[8] = {0};

//cooldown dos disparos das naves
#define COOLDOWN 50
/* adciona um projetil novo à lista ligada de projeteis */
void atira(corpo *n, TipoProjetil *tipo, corpo *fimcorpos);

/* remove da lista ligada de projeteis, todos os projeteis
 * cujo tempo de vida é menor do que 0 
 */
corpo * mata_projeteis(corpo *listadecorpos, double intervalo);

WINDOW * TELA; /* Janela onde o jogo sera simulado */

void atualiza_posicao (corpo* alvo, corpo* corpo, double intervalo);

void free_corpos (corpo* listadecorpos);

void impulsiona_nave(corpo *n1);

void desenha_corpo (corpo * cp);

void le_entradas(corpo *n1, corpo *n2, TipoProjetil *tipo_proj,
		 corpo *lista_proj);

void explode (corpo *a);
#endif /* SIMULACAO */
