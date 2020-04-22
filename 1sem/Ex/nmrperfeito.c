#include <stdio.h>
	int main(){
		int soma=0, n;
		scanf("%d", &n);
		for (int i=1; i<(n/2)+1; i++){
			if (n%i==0)
				soma=soma+i;}
		if (soma==n)
			printf("%d e perfeito\n", n);
		else 
			printf("%d nao e perfeito\n", n);
		return (0);}
