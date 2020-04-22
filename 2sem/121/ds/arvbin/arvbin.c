#include "arvbin.h"

/* Existem 3 jeitos de imprimir a árvore: preordem, inordem, posordem, a única diferença entre eles é o lugar do print */


void inOrdem(No *r){
    if (r!= NULL){
	printf("%d\n", r->info);
	inOrdem(r->esq);
	inOrdem(r->dir);
    }
}

void inOrdem(No *r){
    if(r!=NULL){
	inOrdem(r->esq);
	printf("%d\n", r->info);
	inOrdem(r->dir);
    }
}

void posOrdem(No *r){
    if(r!=NULL){
	posOrdem(r->esq);
	posOrdem(r->dir);
	printf("%d\n", r->info);
    }
}

No *sucessor(No *p){
    if (p->dir != NULL){
	No *q = p->dir;
	while (q->esq != NULL) q = q->esq;
	return q;
    }
    while (q=p->pai != NULL && q->pai->dir == q) q = q->pai;
    return q;
}
