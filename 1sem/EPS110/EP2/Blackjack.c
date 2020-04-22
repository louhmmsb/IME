#include <stdio.h>
#define c11 830.641326
#define c21 194.717468168126
#define c1 999.5
#define c2 1.00005

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

	double random(double old){
		double new=frac(c1*module(seno(old))+c2);
		return(new);
		}

	int main(){
		double semente, winp100;
		char l=37;
		int simn, limiar=12, carta, player, banca, wins=0, contaasteriscos;
		printf("Digite a semente (0 < x < 1): ");
		scanf("%lf", &semente);
		printf("Digite o numero de simulaçoes para cada limiar: ");
		scanf("%d", &simn);
		while(limiar<=20){
			for (int i=0; i<simn; i++){
				player=0;
				banca=0;
				while (player<limiar){ 
					semente=random(semente);
					carta=card(semente);
					if (carta==11||carta==12||carta==13)
						carta=10;
					player=player+carta;
					}
				while (banca<=player){ 
					semente=random(semente);
					carta=card(semente);
					if (carta==11||carta==12||carta==13)
						carta=10;
					banca=banca+carta;
					}
				if (player==21 || 21>player>banca || player<21 && banca>21)
					wins++;
					}
				winp100=(float)100*wins/simn;
				printf("%d ( %3.1lf %c) : ", limiar, winp100, l);
				contaasteriscos=winp100;
				for(contaasteriscos; contaasteriscos>0; contaasteriscos--){
					printf("*");
					}
				printf("\n");
				limiar++;
				wins=0;
				}
		return(0);
		}

