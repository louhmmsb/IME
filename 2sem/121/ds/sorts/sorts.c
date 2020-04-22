#include <stdio.h>
#include <stdlib.h>
/* BLOCO DO MERGESORT */
void intercala(int p, int q, int r, int v[]){
    int *w, k, j;
    w = malloc((r-p)sizeof(int));
    for(k=0; k+p<q; k++)
        w[k]=v[p+k];
    for(j=r-p-1; k<r; k++, j--)
        w[j]=v[k];
    i=0; j=r-p-1;
    for(k=p;k<r; k++){
        if(w[i]<w[j]){
            v[k]=w[i];
            i++;
        }
        else{
            v[k]=w[j];
            j--;
        }
    }
    free(w);
}

/* organiza um vetor que começa em p e termina em r-1 */
void mergeSort(int p, int r, int v[]){
    int q=(p+r)/2;
    if(p<r-1){
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
    }
}
/* FIM DO BLOCO DO MERGESORT */

/* BLOCO DO QUICKSORT */
/* rearranja v de modo que p<=q<r e v[p..q-1]<=v[q]<v[q+1..r-1] e devolve q */
int separa(int p, int r, int v[]){
    int i=p-1, j, x=v[r-1], t;
    for(j=p, j<r; j++){
	if(v[j]<=x){
	    t=v[++i];
	    v[i]=v[j];
	    v[j]=t;
	}
    }
    return i;
}

void quickSort(int p, int r, int v[]){
    if(p<r-1){
	int q=separa(p, r, v);
	quickSort(p, q, v);
	quickSort(q+1, r, v);
    }
}
/* FIM DO BLOCO DO QUICKSORT */

/* BLOCO DO HEAPSORT */
void peneira(int i, int m, int v[]){
    int f = 2*i, ;
    while(f <= m){
	if (f < m && v[f] < v[f+1]) f++;
	if (v[i] >= v[f]) break;
	x = v[i];
	v[i] = v[f];
	v[f] = x;
	i = f;
	f = 2*i;
    }
}

void heapsort(int v[], int n){
    int i, x;
    for(i = n/2; i >= 1; i--) peneira(i, n, v);
    for(i = n; i>1; i--){
	x = v[i];
	v[i] = v[1];
	v[1] = x;
	peneira(1, i-1, v);
    }
}
/* FIM DO BLOCO DO HEAPSORT */
