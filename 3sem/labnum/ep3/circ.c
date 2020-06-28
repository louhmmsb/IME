#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double circ(double x, double y){
    if(x*x + y*y <= 1) return 1;
    return 0;
}

int main(int argc, char **argv){
    int n, numero_de_sementes, bs, ws;

    if(argc < 3){
        printf("Argumentos...\n");
        return 0;
    }
    
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &numero_de_sementes);
    
    double b = 10.0, w = -1, m = 0, x, y, resp = 0.0;

    for(int i = 0; i<=numero_de_sementes; i++){
        srand(i);        
        for(int j = 0; j<=n; j++){
            x = (double)rand()/((double)RAND_MAX + 1);
            y = (double)rand()/((double)RAND_MAX + 1);
            resp += circ(x, y);
        }

        resp = 4*resp/n;
        double err = fabs(resp - M_PI);
        if(err > w){
            w = err;
            ws = i;
        }
        if(err < b){
            b = err;
            bs = i;
        }
        m += err;
    }
    m /= numero_de_sementes;

    if(argc == 4 && strcmp("latex", argv[3]) == 0){
        printf("%d & %g & %g & %g \\\\\n", n, b, w, m);
        printf("\\hline\n");
    }
    else{
        printf("Menor erro = %g\nSemente = %d\n", b, bs);
        printf("Maior erro = %g\nSemente = %d\n", w, ws);
        printf("Erro medio = %g\n", m);
    }

    return 0;
}
