#include <stdio.h>
	int main(){
		int n, j, m, c=0, k=0, stop=0;
		scanf("%d %d %d", &n, &j, &m);
		int r = j%m;
			while (stop==0){
				if (c%m==r){
					printf("%d\n", c);
					c++;
					k++;}
				else 
					c++;
				if (k==n)
					stop=1;}
		return (0);}
