#ifndef _UTIL_H
#define _UTIL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define AVISO(msg) fprintf (stdout, "AVISO: %s\n", #msg)
#define ERROR(msg) fprintf (sterr, "ERRO: %s\n", #msg)

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void *
malloc_safe (size_t);

char *
concat (char * s, char * v);

char *
int_strc (int x);

void 
mostre_uso (char **);

#endif /* _UTIL_H */
