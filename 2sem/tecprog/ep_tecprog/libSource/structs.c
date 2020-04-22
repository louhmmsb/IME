#include "structs.h"
#include "util.h"

corpo * cria_corpo (int ID){
    corpo * novo;
    novo = malloc_safe (sizeof (*novo));
    switch (ID){
		case 1:
			novo->obj.planet = malloc_safe (sizeof (planeta));
			break;
		case 2:
			novo->obj.nav = malloc_safe (sizeof (nave));
			break;
		case 3:
			novo->obj.proj = malloc_safe (sizeof (projetil));
			break;
		case 4:
			AVISO(Ainda nao implementado!);
			break;	
	}
    novo->ID = ID;
    return novo;
}
