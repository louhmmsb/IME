#include "abbusca.h"


No *busca(Arvore r, int k){
    if (r == NULL || r->chave == k) return r;
    if (r->chave > k) return busca(r->esq, k);
    else return busca(r->dir, k);
}

No *new(int chave, int info, No *esq, No *dir){
    No *novo = mallocSafe(sizeof *novo);
    novo->chave = chave;
    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

Arvore insere (Arvore r, No *novo){
    No *f, *p;
    if(r == NULL) return novo;
    f = r;
    while (f != NULL){
	p = f;
	if(f->chave > novo->chave) f = f->esq;
	else f = f->dir;
    }
    if(p->chave > novo->chave) p->esq = novo;
    else p->dir = novo;
    return r;
}

Arvore removeRaiz(Arvore r){
    No *p, *q;
    if(r->esq == NULL){
	q = r->dir;
	free(r);
	return q;
    }
    p = r;
    q = r->esq;
    while(q->dir != NULL){
	p = q;
	q = q->dir;
    }
    if(p != r){
	p->dir = q->esq;
	q->esq = r->esq;
    }
    q->dir = r->dir;
    free(r);
    return q;
}

Avore rotacaoDir(Arvore r){
    No *q = r->esq;
    r->esq = q->dir;
    q->dir = r;
    return q;
}

Arvore rotacaoEsq(Arvore r){
    No *q = r->dir;
    r->dir = q->esq;
    q->esq = r;
    return q;
}
