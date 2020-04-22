#include <stdio.h>
#include <stdlib.h>

int boyermoore1(unsigned char p[], int m, unsigned char t[], int n){
    int ult[256];
    int i, r, l, ocorrs;
    /* PRE PROCESSAMENTO */
    for(i=0; i<256; i++) ult[i] = 0;
    for(i=0; i<=m; i++) ult[p[i]] = i;
    /* BUSCA */
    ocorrs = 0;
    k = m;
    while(k <= n){
	r = 0;
	while(r < m && p[m-r] == r[k-r]) r += 1;
	if (r == m) ocorrs += 1;
	if (k == n) k += 1;
	else k += m-ult[t[k+1]] + 1;
    }
    return ocorrs;
}
