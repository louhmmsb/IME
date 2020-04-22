#include "util.h"


void *
malloc_safe (size_t valor) {
    void *p = malloc (valor);
    if (p == NULL) {
	AVISO(Vixe! Faltou RAM!);
	exit (EXIT_FAILURE);
    }
    return p;
}


/* 
 * concat ()
 * Adiciona (r) ao final de (s) e retorna o resultado em strCat
 */
char *
concat (char * s, char * r) {
    int sizeS = strlen (s);
    int sizeR = strlen (r);
    int i, j;
    char *strCat = malloc_safe ((sizeS + sizeR -1 )* sizeof (char));

    i = j = 0;
    while (s[i] != '\0') {
	strCat[i] = s[i];
	i++;
    }
    while (r[j] != '\0') {
	strCat[i+j] = r[j];
	j++;
    }

    strCat[i+j] = '\0';
    return strCat;
}

/*
 * int_strc()
 * Converte o inteiro nao nulo (x) para uma string (sInt)
 */
char *
int_strc (int x) {
    int i, digitos, r;
    char *sInt;
    if (x < 10) {
	sInt = malloc_safe (2 * sizeof (char));
	sInt[0] = '0' + x;
	sInt[1] = '\0';
	return sInt;
    }
    for (r = x, digitos = 0; r != 0; r /= 10, digitos++);
    sInt = malloc_safe ((digitos + 1) * (sizeof (char)));

    i = digitos - 1;
    while (x != 0) {
	r = x % 10;
	sInt[i] = r + '0';
	x /= 10;
	i--;
    }
    sInt [digitos] = '\0';
    return sInt;
}

/*
 * mostre_uso()
 * Mostra como o programa deve ser utilizado
 */
void
mostre_uso (char ** v) {
    printf ("Uso:\n");
    printf (">>>%s [intervalo] [arquivo.txt]\n", v[0]);
    printf ("\nDica: intervalo == 1 e' um bom valor\n\n");
}
