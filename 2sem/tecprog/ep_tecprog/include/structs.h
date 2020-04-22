#ifndef STRUCTS
#define STRUCTS

#ifndef VETORES
#include "vetores.h"
#endif

#ifndef XWC
#define XWC
#include "xwc.h"
#endif


#define MAX_PICS 24
#define PLANETA 1
#define NAVE 2
#define PROJETIL 3

typedef struct Planeta {
    double R;
} planeta;


typedef struct Nave {
    char nome[20];
    int tipo;
	double cooldown;
	double vida;
} nave;


typedef struct Projetil {
    int tipo;
    double tempo_de_vida;
    double dano;
} projetil;


typedef struct {
	int tipo;
	double massa;
	double vida;
	double dano;
	double vel;
} TipoProjetil;


union Objeto
{
    projetil *proj;
    nave *nav;
    planeta *planet;
};

typedef union Objeto Obj;


typedef struct Corpo {
    double massa;
    double rcolisao;
    double rotacao;
    vetor pos;
    vetor vel;
    vetor direcao;
    WINDOW *imagem [MAX_PICS];
    WINDOW *mascara [MAX_PICS];
    int ID; /* identifica se é nave, planeta, projetil, etc */
    struct Corpo *prox; /* Para criarmos uma lista ligada de corpos */
    Obj obj;
} corpo;


corpo * cria_corpo (int ID);

#endif /* Fim  STRUCTS */
