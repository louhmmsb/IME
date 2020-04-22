#include <stdio.h>
	int ehprimo(int x){
		int l=1;
		if (x==0 || x==1)
			return(0);
		for (int c=2; (c*c)+1<x && l==1; c++){
			if (x%c!=0)
				l=1;
			else 
				l=0;}
		if (l==1)
			return(1);
		else	
			return(0);}


	int main(){
		int n, i=2, cont=0;
		scanf("%d", &n);
		while(i<=n){
			cont=0;
			if (ehprimo(i)==1 && n%i==0){
				printf("%d - ", i);
				while (n%i==0){
					n=n/i;
					cont++;}
				printf("Multiplicidade: %d\n", cont);}
			i++;}
		return(0);}
					
					
		
