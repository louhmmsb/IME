#include <stdio.h>
#define MAX 100

	void ordenarporNUSP(int v[][], int tamanho){
		int aux, step, i, menor;
		for(step=0; step<tamanho-1; step++){
			for(menor=step, i=step+1; i<tamanho; i++)
				if(v[i][1] < v[menor][1])
				menor=i;
			for(int j=0; j<4; j++){
				aux=v[step][j];
				v[step][j]=v[menor][j];
				v[menor][j]=aux;
			}
		}
	}




/*	int main(){
		printf("Benvindo ao Sistema Estatístico de Uso do Salão de Estuddos\nBiblioteca Carlos Benjamim de Lyra - IME-USP\n");
		FILE *arquivoentrada;
		char arquivo[MAX]; 
		int entraousai[MAX], nusp[MAX], horas[MAX], minutos[MAX], eos, n, h, m;
		printf("Digite o nome do arquivo de dados: ");
		scanf("%s", arquivo);
		arquivoentrada = fopen(arquivo, "r");
		//if (arquivoentrada==NULL)    checagem pra ver se o arquivo foi lido (retirar dps)
		//	printf("ruim\n");
		while (!feof(arquivoentrada)){
			for (int i=0; i<=MAX; i++)
				if (fscanf(arquivoentrada, "%d %d %d:%d", &entraousai[i], &nusp[i], &horas[i], &minutos[i]) !=4) continue;
		}
		//for (int i=0;i<=MAX;i++) printa as coisas lidas pra testar se leu certo (retirar dps)	
		//	printf("%d %d %d:%02d\n", entraousai[i], nusp[i], horas[i], minutos[i]);		
		return(0);
	}*/






	int main(){
		printf("Benvindo ao Sistema Estatístico de Uso do Salão de Estuddos\nBiblioteca Carlos Benjamim de Lyra - IME-USP\n");
		FILE *arquivoentrada;
		char arquivo[MAX]; 
		int matriz[MAX][4], i1, i2, a=15;
		printf("Digite o nome do arquivo de dados: ");
		scanf("%s", arquivo);
		arquivoentrada = fopen(arquivo, "r");
		while (!feof(arquivoentrada)){
			for (i1=0; i1<=MAX; i1++)
				if (fscanf(arquivoentrada, "%d %d %d:%d", &matriz[i1][0], &matriz[i1][1], &matriz[i1][2], &matriz[i1][3]) !=4) continue;
		}
		void ordenarporNUSP(matriz, a);
		for (i2=0; i2<15; i2++){
			for(int j=0; j<4; j++){
				if(j==2)
					printf("%d:", matriz[i2][j]);
				else if(j==3)
					printf("%02d\n", matriz[i2][j]);
				else 
					printf("%d ", matriz[i2][j]);
			}
		}		
		return(0);
	}











