#include <stdio.h>



	double module(double n){
		if (n>=0)
			return(n);
		else
			return(-n);
		}
	
	double frac(double n){
		int nint = n;
		n=(double)n-nint;
		return(n);
		}

	double seno(double n){
		int i=3;
		double termo=n/1.0;
		double soma=termo;
		double termop=termo;
		for (i=3; termo>=0.00000001; i=i+2){
			termop=termop*n*n;
			termo=termop/i;
			soma=soma+termo;
			}
		return(soma);
		}

	double card(double cardgen){
		int carta=13*cardgen+1;
		return(carta);
		}

	double random(double old, double c1, double c2){
		double new=frac(c1*module(seno(old))+c2);
		return(new);
		}




	int main(){
		int carta, a, limite=10000; 
		double array[13], x=0.5, d=limite*0.02, c1, c2;
		for (int i=0; i<13; i++){
			array[i]=0;
		}	
		for (c1=0; c1<1000; c1++){
			for(c2=0; c2<1; c2=c2+0.001){
				for (int l=0; l<limite; l++){
					carta = card(random(x, c1, c2));
					array[carta-1]++;
				}	 	
					for (int n=0; n<13 && a==1; n++){
						if ((array[n]<(limite/13)+d) && (array[n]>(limite/13)-d))
							a=1;
						else
							a=0;
					}
					if (a==1)
						printf("c1 = %lf e c2 = %lf\n", c1, c2);
					a=1;
					for (int i=0; i<13; i++){
					array[i]=0;
					}
			}
		} 	 	
		return(0);}			
	






