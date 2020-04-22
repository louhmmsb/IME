#include <stdio.h>
	int main(){
		float soma1=0.0, soma2=0.0, soma3=0.0, soma4=0.0, soma3n=0.0, soma3p=0.0, soma4n=0.0, soma4p=0.0;
		for (int n1=1; n1<=10000; n1++){
			if (n1%2==0){
				soma1=soma1-1.0/n1;
				soma3n=soma3n-1.0/n1;}
			else{
				soma1=soma1+1.0/n1;
				soma3p=soma3p+1.0/n1;}}
		for (int n2=10000; n2>0; n2--){
			if (n2%2==0){
				soma2=soma2-1.0/n2;
				soma4n=soma4n-1.0/n2;}
			else{
				soma2=soma2+1.0/n2;
				soma4p=soma4p+1.0/n2;}}
		soma3=soma3p+soma3n;
		soma4=soma4p+soma4n;
		printf("%lf\n %lf\n %lf\n %lf\n", soma1, soma2, soma3, soma4);
		return(0);}
			
 
