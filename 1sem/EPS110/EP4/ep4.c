#include <stdio.h>       //1=branco, -1=preto, 0=vazio
	int modulo(int n){
		if (n<0) return(-n);
		else return (n);
	}

int podejogar(int tabuleiro[8][8], int cor,  int l, int c){
	int vl[8], vc[8], oposta, i, j, x=1, deu=0, a, viuoposta=0;
	if (cor==1) oposta=-1;
	else oposta=1;
	if(l>7 || l<0 || c>7 || c<0) return 0;	
	if (tabuleiro[l][c] != 0) return 0;
	//printf("\n%d %d %d %d %d %d %d\n", oposta, i, j, x, deu, a, viuoposta);
//	vl[8]={-1, -1, 0, 1, 1, 1, 0, -1}
//	vc[8]={0, 1, 1, 1, 0, -1, -1, -1}
	vl[0]=-1;
	vc[0]=0;
	vl[1]=-1;
	vc[1]=1;
	vl[2]=0;
	vc[2]=1;
	vl[3]=1;
	vc[3]=1;
	vl[4]=1;
	vc[4]=0;
	vl[5]=1;
	vc[5]=-1;
	vl[6]=0;
	vc[6]=-1;
	vl[7]=-1;
	vc[7]=-1;
	for(a=0; a<8 && deu==0; a++){
		i=vl[a]+l;
		j=vc[a]+c;
		viuoposta=0;
		while(i<7 && i>=1 && j<7 && j>=1){
			if(tabuleiro[i][j]==oposta){
				i=i+vl[a];
				j=j+vc[a];
				viuoposta=1;
			}
			else break;
		}
		if(tabuleiro[i][j]==cor && viuoposta==1) deu++;
	}
	if(deu>0) return(1);
	return(0);
}


//	void escolhejogada(int tabuleiro[8][8], int cor, int *linha, int *coluna)

void zeratab(int tabuleiro[8][8]){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			tabuleiro[i][j]=0;
		}
	}
}

void printatabuleiro(int tabuleiro[8][8]){
	int i, j;
	printf("X 0 1 2 3 4 5 6 7\n");
	for(i=0; i<8; i++){
		printf("%d ", i);
		for(j=0; j<8; j++){
			if (tabuleiro[i][j]==0) printf("  ");
			if (tabuleiro[i][j]==1) printf("B ");
			if (tabuleiro[i][j]==-1) printf("P ");
			if (tabuleiro[i][j]==2) printf("2  ");
		}
		printf("\n");
	}	
}

void testatab(int tabuleiro[8][8]){
	int tabuleiro_dois[8][8], i, j, temp;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			temp = -podejogar(tabuleiro, -1, i, j);
			tabuleiro_dois[i][j] = temp;
		}
	}
	printatabuleiro(tabuleiro_dois);
}

int podejogarb(int tabuleiro[8][8], int cor, int l, int c){
		int i=l, j=c, oposta, vai=1;
		if (cor==1) oposta=-1;
		else oposta=1;
		if(l>7 || l<0 || c>7 || c<0) return(0);
		if(tabuleiro[l][c]!=0) return(0); 
		j=c+1;
		while(j<7 && vai==1){
			if(tabuleiro[i][j]==oposta) j++;
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && j-c>1) return(1);
		vai=1;
		j=c-1;
		while(j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta) j--;
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && c-j>1) return(1);
		vai=1;
		j=c;
		i=l+1;
		while(i<7 && vai==1){
			if(tabuleiro[i][j]==oposta) i++;
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1) return(1);
		vai=1;
		i=l-1;
		while(i>=1 && vai==1){
			if(tabuleiro[i][j]==oposta) i--;
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && l-i>1) return(1);
		vai=1;
		i=l+1;
		j=c+1;
		while(i<7 && j<7 & vai==1){
			if(tabuleiro[i][j]==oposta){
				i++;
				j++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1 && j-c>1) return(1);
		vai=1;
		i=l-1;
		j=c-1;
		while(i>=1 && j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				i--;
				j--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && l-i>1 && c-j>1) return(1);
		vai=1;
		i=l-1;
		j=c+1;
		while(i>=1 && j<7 && vai==1){
			if(tabuleiro[i][j]==oposta){
				i--;
				j++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && l-i>1 && j-c>1) return(1);
		vai=1;
		i=l+1;
		j=c-1;
		while(i<7 && j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				i++;
				j--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1 && c-j>1) return(1);
		return(0);
	}
	
	void trocaparcial(int tabuleiro[8][8], int tabaux[8][8], int cor){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(tabaux[i][j]==2) tabuleiro[i][j]=cor;
			}
		}
	}
	
	void trocacompleta(int tabuleiro[8][8], int cor, int l, int c){
		int i=l, j=c, oposta, vai=1, tabaux[8][8];
		zeratab(tabaux);
		if (cor==1) oposta=-1;
		else oposta=1;
		j=c+1;
		while(j<7 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				j++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && j-c>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		j=c-1;
		while(j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				j--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && c-j>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		j=c;
		i=l+1;
		while(i<7 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		i=l-1;
		while(i>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && l-i>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		i=l+1;
		j=c+1;
		while(i<7 && j<7 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i++;
				j++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1 && j-c>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		i=l-1;
		j=c-1;
		while(i>=1 && j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i--;
				j--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor &&l-i>1 && c-j>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		i=l-1;
		j=c+1;
		while(i>=1 && j<7 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i--;
				j++;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && l-i>1 && j-c>1) trocaparcial(tabuleiro, tabaux, cor);
		zeratab(tabaux);
		vai=1;
		i=l+1;
		j=c-1;
		while(i<7 && j>=1 && vai==1){
			if(tabuleiro[i][j]==oposta){
				tabaux[i][j]=2;
				i++;
				j--;
			}
			else vai=0;
		}
		if(tabuleiro[i][j]==cor && i-l>1 && c-j>1) trocaparcial(tabuleiro, tabaux, cor);
	}
	
	void joga(int tabuleiro[8][8], int cor, int l, int c){
		tabuleiro[l][c]=cor;
	}
	
	
	
	int main(){
		int tabuleiro[8][8], player, pc, i, j, turno=-1, l, c, acabou=0;
		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				tabuleiro[i][j]=0;
			}
		}
		printf("Voce quer ser o preto ou o branco? (Preto comeca) (Preto=-1, Branco=1)");
		scanf("%d", &player);
		if (player==1) pc=-1;
		else pc=1;
		tabuleiro[3][3]=1;
		tabuleiro[4][4]=1;
		tabuleiro[3][4]=-1;
		tabuleiro[4][3]=-1;
		printatabuleiro(tabuleiro);
		testatab(tabuleiro);
		while(acabou==0){
			if(turno==player) {
				printf("Fale a linha e a coluna onde voce quer jogar: ");
				scanf("%d %d", &l, &c );
				if (podejogar(tabuleiro, player, l, c)==1){
					trocacompleta(tabuleiro, player, l, c);
					joga(tabuleiro, player, l, c);
					printatabuleiro(tabuleiro);
				}
			}
		}
		return(0);
	}
	
	
	
	
	
	
	
	
