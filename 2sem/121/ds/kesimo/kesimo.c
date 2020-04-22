#include <stdio.h>
#include <stdlib.h>

void kEsimo(int k, int n, int v[]){
    int i, j, min, x;
    for (i=0; i<k; i++){
	min = i;
	for(j=1+i; n; j++){
	    if(v[j]<v[min]) min = j;
	    x = v[i];
	    v[i]=v[min];
	    v[min]=x;
	}
    }
}
