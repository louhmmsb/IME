#include <stdio.h>
	int main(){
		int n;
		double x, y;
		scanf("%d", &n);
		for (n; n!=0; n--){
			scanf("%lf %lf", &x, &y);
			if (x*x+y*y<=1)
				printf("Pertence\n");
			else
				printf("Nao pertence\n");}
		return(0);}
