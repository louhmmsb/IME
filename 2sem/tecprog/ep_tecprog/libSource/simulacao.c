#include "simulacao.h"
#include "fisica.h"
#include "vetores.h"
#include "structs.h"
#include "entrada.h"
#include "util.h"
#include <stdlib.h>
#include <X11/keysymdef.h>

#ifndef XWC
#define XWC
#include "xwc.h"
#endif

#define BOOST 1 /* boost das naves */

void atira(corpo *n, TipoProjetil *tipo, corpo *fimcorpos){
    corpo *p;
	double offset = 100.;

	n->obj.nav->cooldown = COOLDOWN;

	p = cria_corpo(PROJETIL);

	p->obj.proj->tipo = tipo->tipo;
	p->obj.proj->tempo_de_vida = tipo->vida;
	p->obj.proj->dano = tipo->dano;

	p->massa = tipo->massa;
	p->direcao = n->direcao;
	p->pos = soma_vetor(n->pos, real_vetor(offset, p->direcao));
	p->vel = real_vetor(tipo->vel, p->direcao);
	p->prox = NULL;
	seta_imagens(p, 24, 300);

	fimcorpos->prox->prox = p;
	fimcorpos->prox = p;
}

corpo *  mata_projeteis(corpo * listadecorpos, double intervalo){
	corpo *percorre, *atras, *kill;

	percorre = listadecorpos->prox;
	atras = listadecorpos;
	while(percorre != NULL){
		if(percorre->ID == PROJETIL){
			if(percorre->obj.proj->tempo_de_vida < 0){
				atras->prox = percorre->prox;
				free((percorre->obj.proj));
				free(percorre);
				percorre = atras->prox;
			}
			else {
				percorre->obj.proj->tempo_de_vida -= intervalo;
				percorre = percorre->prox;
				atras = atras->prox;
			}
		}
		else {
			atras = percorre;
			percorre = percorre->prox;
		}
	}
	return atras;
}

void atualiza_posicao(corpo* alvo, corpo* Corpo, double intervalo) {
	vetor forca;
	forca.x = 0;
	forca.y = 0;

	for(corpo *c = Corpo; c != NULL; c = c->prox) {
		forca = soma_vetor(forca, calcula_gravidade(alvo, c));
	}

	vetor aceleracao = calcula_aceleracao(forca, alvo->massa);
	vetor velocidade = calcula_velocidade(aceleracao, intervalo);

	alvo->vel = soma_vetor(alvo->vel, velocidade);

	alvo->pos = soma_vetor(alvo->pos,
			calcula_deslocamento(alvo->vel, aceleracao,	intervalo));

	if(alvo->pos.x >= WIDTH * 50.)
		alvo->pos.x = WIDTH * -50.;
	else if(alvo->pos.x <= HEIGHT * -50.)
		alvo->pos.x = HEIGHT * 50.;

	if(alvo->pos.y >= WIDTH * 50.)
		alvo->pos.y = WIDTH * -50.;
	else if(alvo->pos.y <= HEIGHT * -50.)
		alvo->pos.y = HEIGHT * 50.;
}

void free_corpos(corpo* listadecorpos) {
	corpo * p = listadecorpos;
	while(p != NULL){
		listadecorpos = listadecorpos->prox;
		switch(p->ID){
			case PROJETIL:
				free(p->obj.proj);
				break;
			case NAVE:
				free(p->obj.nav);
				break;
			case PLANETA:
				free(p->obj.planet);
				break;
		}
		free(p);
		p = p->prox;
	}
}

void desenha_corpo(corpo *cp) {
    int x = cp->pos.x;
    int y = cp->pos.y;
    int rotacao = (int) (cp->rotacao /  15);
    x /= 100;
    y /= 100;

    x += HEIGHT / 2;
    y += WIDTH / 2;
    SetMask (TELA, cp->mascara[rotacao]);

	switch(cp->ID){
		case 1:
			PutPic(TELA, cp->imagem[rotacao], 0, 0, LIN_PLANETA, COL_PLANETA,
					x-LIN_PLANETA, y-COL_PLANETA);
			break;
		case 2:
			PutPic(TELA, cp->imagem[rotacao], 0, 0, LIN_NAVE, COL_NAVE,
					x-LIN_NAVE, y-COL_NAVE);
			break;
		case 3:
			PutPic(TELA, cp->imagem[rotacao], 0, 0, LIN_PROJETIL, COL_PROJETIL,
					x-LIN_PROJETIL, y-COL_PROJETIL);
			break;
		default:
			AVISO("desenha_corpo em simulacao.c: parametro ID pode estar errado");
			break;
	}
}

void impulsiona_nave(corpo *n){
	vetor boost;

	//nao faz nada se a nave estiver muito rapida
	if(produto_escalar(n->vel, n->vel) > 100000) return;

	//direcao do boost deve ser igual a da nave
	boost.x = n->direcao.x;
	boost.y = n->direcao.y;
	boost = normaliza(boost);

	boost = real_vetor(BOOST, boost);

	//soma o boost diretamente na velocidade
	n->vel = soma_vetor(boost, n->vel);
}

/*
 * Le os inputs do teclado e
 * 		ou rotaciona as naves
 * 		ou aumenta a velocidade das naves
 * 		ou atira
 * Recebe:
 * 		uma janela,
 * 		a nave 1
 * 		a nave 2
 */

void le_entradas(corpo *n1, corpo *n2, TipoProjetil *tipo_proj,
		corpo *fimlista){
    XKeyEvent e;
	while(WCheckKBD(TELA)){
		e = WGetKey(TELA);
		if(e.type == KeyPress){
			switch(WLastKeySym()){
				//controle da nave 1
				case XK_Left:
					keyPressed[LEFT_KEY] = 1;
					break;
				case XK_Right:
					keyPressed[RIGHT_KEY] = 1;
					break;
				case XK_Up:
					keyPressed[UP_KEY] = 1;
					break;
				case XK_Down:
					keyPressed[DOWN_KEY] = 1;
					break;

					//controle da nave 2
				case XK_a:
					keyPressed[A_KEY] = 1;
					break;
				case XK_d:
					keyPressed[D_KEY] = 1;
					break;
				case XK_w:
					keyPressed[W_KEY] = 1;
					break;
				case XK_s:
					keyPressed[S_KEY] = 1;
					break;
			}
		}
		else if(e.type == KeyRelease){
			switch(WLastKeySym()){
				//controle da nave 1
				case XK_Left:
					keyPressed[LEFT_KEY] = 0;
					break;
				case XK_Right:
					keyPressed[RIGHT_KEY] = 0;
					break;
				case XK_Up:
					keyPressed[UP_KEY] = 0;
					break;
				case XK_Down:
					keyPressed[DOWN_KEY] = 0;
					break;

					//controle da nave 2
				case XK_a:
					keyPressed[A_KEY] = 0;
					break;
				case XK_d:
					keyPressed[D_KEY] = 0;
					break;
				case XK_w:
					keyPressed[W_KEY] = 0;
					break;
				case XK_s:
					keyPressed[S_KEY] = 0;
					break;
			}
		}
	}
	if(keyPressed[UP_KEY])
		impulsiona_nave(n1);

	if(keyPressed[RIGHT_KEY])
		rotaciona(n1, HORARIO);

	if(keyPressed[LEFT_KEY])
		rotaciona(n1, ANTIHORARIO);

	if(keyPressed[DOWN_KEY] && n1->obj.nav->cooldown <= 0.)
		atira(n1, tipo_proj, fimlista);

	if(keyPressed[W_KEY])
		impulsiona_nave(n2);

	if(keyPressed[D_KEY])
		rotaciona(n2, HORARIO);

	if(keyPressed[A_KEY])
	 	rotaciona(n2, ANTIHORARIO);

	if(keyPressed[S_KEY] && n2->obj.nav->cooldown <= 0.)
		atira(n2, tipo_proj, fimlista);
}

void explode (corpo * a) {
    puts ("BUUUUUUUUUUUUUUUM!");
}
