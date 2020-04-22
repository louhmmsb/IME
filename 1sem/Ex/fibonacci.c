#include <stdio.h>
	int main(){
		int n, a2;		
		scanf("%d", &n);
		if (n==1 || n==2)
			printf("1\n");
		else{
			int a0=1;
			int a1=1;
			for (int c=3; c<=n; c++){
				a2=a1+a0;
				a0=a1;
				a1=a2;}
		printf("%d\n", a2);}
		return(0);}
				
			
