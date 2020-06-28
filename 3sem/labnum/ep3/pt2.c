#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv){
    
    double resp1=0, resp2=0, resp3=0, a2=3, b2=7, m1 = 10, m2 = 10, m3 = 10, p1 = -1, p2 = -1, p3 = -1, media1 = 0.0, media2 = 0.0, media3 = 0.0;
    int n, numero_de_sementes, ms1, ms2, ms3, ps1, ps2, ps3;
    double v1 = -cos(1)+1, v2 = 580.0, v3 = 1.0;
        
    if(argc < 3){
        printf("Para usar passe o número de parcelas que serão usadas para aplicar o monte carlo e o número de sementes que quer testar\n");
        return 0;
    }
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &numero_de_sementes);

    for(int i=0; i<=numero_de_sementes; i++){
        srand(i*time(NULL));
        resp1 = resp2 = resp3 = 0.0;
        
        for(int j=0; j<n; j++){
            double x = (double)rand()/((double)RAND_MAX + 1);
            resp1 += sin(x);
            resp3 += exp(-x)+exp(-1/x)/(x*x);
            x = (b2-a2)*x+a2;
            resp2 += x*x*x;
        }
        
        resp1 /= n;
        resp2 = (b2-a2)*resp2/n;
        resp3 /= n;

        if(fabs(resp1-v1) > p1){
            p1 = fabs(resp1-v1);
            ps1 = i;
        }
        if(fabs(resp2-v2) > p2){
            p2 = fabs(resp2-v2);
            ps2 = i;
        }
        if(fabs(resp3-v3) > p3){
            p3 = fabs(resp3-v3);
            ps3  = i;
        }

        if(fabs(resp1-v1) < m1){
            m1 = fabs(resp1-v1);
            ms1 = i;
        }
        if(fabs(resp2-v2) < m2){
            m2 = fabs(resp2-v2);
            ms2 = i;
        }
        if(fabs(resp3-v3) < m3){
            m3 = fabs(resp3-v3);
            ms3 = i;
        }
        media1 += fabs(resp1-v1);
        media2 += fabs(resp2-v2);
        media3 += fabs(resp3-v3);
    }

    media1 /= numero_de_sementes;
    media2 /= numero_de_sementes;
    media3 /= numero_de_sementes;
    
    if(argc == 4 && strcmp("latex", argv[3]) == 0){
        printf("$\\sin{x}$ & %d & %e & %e & %e \\\\\n", n, m1, p1, media1);
        printf("\\hline\n");
        printf("$x^3$ & %d & %e & %e & %e \\\\\n", n, m2, p2, media2);
        printf("\\hline\n");
        printf("$e^{-x}$ & %d & %e & %e & %e \\\\\n", n, m3, p3, media3);
        printf("\\hline\n");
    }
    else{
        printf("Melhor1 = %lf Semente = %d\nPior1 = %lf Semente = %d\nMedia = %lf\n", m1, ms1, p1, ps1, media1);
        printf("Melhor2 = %lf Semente = %d\nPior2 = %lf Semente = %d\nMedia = %lf\n", m2, ms2, p2, ps2, media2);
        printf("Melhor3 = %lf Semente = %d\nPior3 = %lf Semente = %d\nMedia = %lf\n", m3, ms3, p3, ps3, media3);
    }
    
    return 0;
}
