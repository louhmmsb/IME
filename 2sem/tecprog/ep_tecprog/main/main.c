#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "entrada.h"
#include "simulacao.h"
#include "fisica.h"
#include "util.h"
#include <time.h>
#ifndef XWC
#define XWC
#include "xwc.h"
#endif

#define MAX_CORPOS 1000


int main(int argc, char* argv[]) {
	FILE* f;
	double intervalo = 1;
	int duracao_simulacao = 100000000;
	corpo *nave1, *nave2, *planeta;
	corpo *iniCorpos, *fimCorpos, *p, *q, *r; /* "Fila" de corpos e manipulacao*/
	TipoProjetil tipo_proj;

	if (argc < 2 || argc > 3) {
		mostre_uso (argv);
		return EXIT_FAILURE;
	}

	if (argc != 3)
		argv[2] = NULL;

	// lista ligada com os corpos
	iniCorpos = malloc_safe (sizeof (*iniCorpos));
	fimCorpos = malloc_safe (sizeof (*fimCorpos));

	// naves
	nave1 = cria_corpo (NAVE);
	nave2 = cria_corpo (NAVE);

	// planeta feliz
	planeta = cria_corpo (PLANETA);

	// O comeco da fila contera (nessa ordem) nave1, nave2, planeta
	planeta->prox = nave1;
	nave1->prox = nave2;
	iniCorpos->prox = planeta;
	fimCorpos->prox = nave2;

	// Atributos dos objetos
	planeta->obj.planet->R = 1000000;
	planeta->massa = 1e17;
	planeta->rcolisao = planeta->obj.planet->R;
	planeta->rotacao = 0;
	planeta->pos.x = 0;
	planeta->pos.y = 0;

	nave1->massa = nave2->massa = 1000;
	nave1->rcolisao = 1000000;
	nave1->pos.x = 10000;
	nave1->pos.y = 0;
	nave1->vel.x = 0;
	nave1->vel.y = 25.0;
	nave1->direcao.x = 0;
	nave1->direcao.y = -1;

	nave2->rcolisao = 1000000;
	nave2->pos.x = -10000;    
	nave2->pos.y = 0;
	nave2->vel.x = 0;
	nave2->vel.y = -25.0;
	nave2->direcao.x = 0;
	nave2->direcao.y = -1;

	tipo_proj.tipo = 1;
	tipo_proj.massa = 10;
	tipo_proj.vida = 1000000;
	tipo_proj.dano = 1;
	tipo_proj.vel = 50;

	TELA = InitGraph(WIDTH, HEIGHT, "spacewars");
	WINDOW *fundo = ReadPic (TELA, "fotos/imagens/background.xpm", NULL);
	seta_imagens(planeta, 1, 100);
	seta_imagens(nave1, 24, 200);
	seta_imagens(nave2, 24, 201);
	
	InitKBD (TELA);
	while(duracao_simulacao > 0) {
	    //WClear(TELA);		
		UnSetMask (TELA);
		PutPic (TELA, fundo, 0, 0, 500, 500, 0, 0);
		for (p = iniCorpos->prox; p != NULL; p = p->prox ) {
			desenha_corpo (p);
		}

		le_entradas(nave1, nave2, &tipo_proj, fimCorpos);

		for (p = iniCorpos->prox; p != NULL; p = p->prox) {
			atualiza_posicao (p, iniCorpos, intervalo);
		}
		if(nave1->obj.nav->cooldown > 0) nave1->obj.nav->cooldown -= 1;
		if(nave2->obj.nav->cooldown > 0) nave2->obj.nav->cooldown -= 1;

		fimCorpos->prox = mata_projeteis(iniCorpos, 10000);

		usleep(10000);

		duracao_simulacao -= intervalo;

		for(q = iniCorpos->prox; q != NULL; q = q->prox) {
			for(r = q->prox; r != NULL; r = r->prox) {
				if(detecta_colisao(q, r)){
					if(q->ID == NAVE && r->ID == NAVE){
						explode(q);
						explode(r);
					}
					else if(q->ID == NAVE && r->ID == PROJETIL){
						q->obj.nav->vida -= r->obj.proj->dano;
						explode(r);
						if(q->obj.nav->vida <= 0) explode(q);
					}
					else if(q->ID == PROJETIL && r->ID == NAVE){
						r->obj.nav->vida -= q->obj.proj->dano;
						explode(q);
						if(r->obj.nav->vida <= 0) explode(r);
					}
					else if((q->ID == PROJETIL || q->ID == NAVE)
							&& r->ID == PLANETA){
						explode(q);
					}
					else if(q->ID == PLANETA &&
							(r->ID == PROJETIL || r->ID == NAVE)){
						explode(r);
					}
				}
			}
		}
	}
	CloseGraph();

	return 0;
}
