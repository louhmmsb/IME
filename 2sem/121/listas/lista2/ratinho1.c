#include <stdio.h>
#include <stdlib.h>
#define MAX 1000



int main(){
  int *filay, lab[MAX][MAX], *filax, i, j, lin, col, ratolin, ratocol, queijolin, queijocol, filac=0, filaf=0, x, y, d=0;
  FILE * a;
  for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++){
      lab[i][j]=0;
    }
  }
  a = fopen("labirinto.txt", "r");
  fscanf(a, "%d %d", &lin, &col);
  filay = (int *) malloc((lin * col)*sizeof(int));
  filax = (int *) malloc((lin * col)*sizeof(int));
  for(i=0; i<lin*col; i++){
    filay[i]=0;
    filax[i]=0;
  }
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      fscanf(a, "%d", &lab[i][j]);
    }
  }
 for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      printf("%2d ", lab[i][j]);
    }
    printf("\n");
 }
  fscanf(a, "%d %d", &ratolin, &ratocol);
  ratolin = ratolin-1;
  ratocol = ratocol-1;
  fscanf(a, "%d %d", &queijolin, &queijocol);
  queijolin = queijolin-1;
  queijocol = queijocol-1;
  filax[filaf]=queijolin;
  filay[filaf]=queijocol;
  filaf++;
  lab[queijolin][queijocol]=d;
  while(filaf!=filac){
    x = filax[filac];
    y = filay[filac];
    filac++;
    for(i=x-1; i<=x+1; i=i+2){
      if(i>=0 && i<=col && lab[i][y]==-2){
	lab[i][y]=lab[x][y]+1;
	filax[filaf]=i;
	filay[filaf]=y;
	filaf++;
      }
    }
    for(j=y-1; j<=y+1; j=j+2){
      if(j>=0 && j<=lin && lab[x][j]==-2){
	lab[x][j]=lab[x][y]+1;
	filax[filaf]=x;
	filay[filaf]=j;
	filaf++;
      }
    }
  }
  free(filax);
  free(filay);
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      printf("%2d ", lab[i][j]);
    }
    printf("\n");
  }
  return 0;
}
	
    
  
  
  
