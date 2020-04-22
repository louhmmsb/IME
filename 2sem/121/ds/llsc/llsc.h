struct celula {
  int conteudo;
  struct celula * prox;
};

typedef struct celula Celula;

void *mallocSafe (int);

void imprime (Celula *);

Celula *busca (int , Celula * );

void insere (int , Celula ** );

void removeCel (Celula *);

void buscaInsere (Celula ** , int , int );

void buscaRemove (int , Celula **);


