#include "fisica.h"
#include "vetores.h"
#include <math.h>

vetor calcula_gravidade(corpo* c1, corpo* c2){
	double G = 6.674E-11;

	vetor forca;

	vetor dist = subtrai_vetor(c2->pos, c1->pos);

	double d = produto_escalar(dist, dist);

	double c;
		
	if(d < 1){
		forca.x = 0;
		forca.y = 0;
		return forca;
	}

	c = G * c1->massa * c2->massa / produto_escalar(dist, dist);

	forca = real_vetor(c, normaliza(dist));

	return forca;
}

vetor calcula_aceleracao(vetor forca, double massa){
	return real_vetor(1/massa, forca);
}

vetor calcula_velocidade(vetor aceleracao, double tempo){
	return real_vetor(tempo, aceleracao);
}

vetor calcula_deslocamento(vetor velocidade, vetor aceleracao, double tempo){
	return soma_vetor(real_vetor(tempo, velocidade),
	   	real_vetor(tempo*tempo/2, aceleracao));
}

int detecta_colisao(corpo* c1, corpo* c2){
	vetor v = subtrai_vetor(c1->pos, c2->pos);
	double dist = produto_escalar(v, v);
	if(dist <= c1->rcolisao || dist <= c2->rcolisao)
		return 1;
	return 0;
}

void rotaciona(corpo* c, int sentido){
	double angulo = VEL_ANGULAR * M_PI / 180.0; // 1 grau em radianos
	if (sentido == ANTIHORARIO)
		c->rotacao += VEL_ANGULAR;
	else if(sentido == HORARIO){
		c->rotacao -= VEL_ANGULAR;
		angulo *= -1;
	}
	if(c->rotacao > 359.) c->rotacao = 0.;
	if(c->rotacao < 0.) c->rotacao = 359.;
	c->direcao.x = c->direcao.x * cos(angulo) - c->direcao.y * sin(angulo);
	c->direcao.y = c->direcao.x * sin(angulo) + c->direcao.y * cos(angulo);
}
