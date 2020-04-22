#include <stdio.h>
	int main(){
		int i;
		double d, j;
		scanf("%lf %lf", &d, &j);
		j=j+1.0;
		printf("Mes 0: R$%lf\n", d);
		for (i=1; i<13; i++){
			d=d*j;
			printf("Mes %d: R$%lf\n", i, d);}
		return(0);}
			
		
