#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Aqui estão as funções implementadas no EP

double xaocubo(double *x){
    return x[0]*x[0]*x[0];
}

double circ(double *x){
    if(x[0]*x[0]+x[1]*x[1] <= 1) return 1.0;
    return 0.0;
}

double seno(double *x){
    return sin(x[0]);
}

double euler(double *x){
    return exp(-x[0])+exp(-1/x[0])/(x[0]*x[0]);
}

//Essa função coloca números aleatórios no vetor x
void gera_aleatorio(double *x, int xsize){
    for(int i=0; i<xsize; i++) x[i] = ((double)(rand())/((double)RAND_MAX+1));
}

//\int_a^bf(x)dx = \int_0^1f(u(x))u'(x)dx = (b-a)\int_0^1f(u(x))dx ~ (b-a)\sum_i=1^{n-1}f(u(xi))

//Essa função aplica aplica a fórmula que leva o intervalo 0 1 ao intervalo a b no vetor x
void u(double *x, int xsize, double *a, double *b){
    for(int i=0; i<xsize; i++){
        x[i] = (b[i]-a[i])*x[i]+a[i];
    }
}

//Essa função aplica uma função matemática genérica a um vetor de x transformado pela função u
double calcula(double (*g)(double*), double *x, int xsize, double *a, double *b){
    u(x, xsize, a, b);
    return g(x);
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("Para usar o programa passe o número de dimensões e o n como parâmetro, ex: ./pt2.out 1 1000\n");
        return 0;
    }
    
    double resp = 0.0, *a, *b, *x, c = 1.0, (*g)(double*);
    int dim, n, escolha;
    
    sscanf(argv[1], "%d", &dim);
    sscanf(argv[2], "%d", &n);
    srand(time(NULL));

    a = (double*)malloc(dim*sizeof(double));
    b = (double*)malloc(dim*sizeof(double));
    x = (double*)malloc(dim*sizeof(double));

    for(int i=1; i<=dim; i++){
        printf("Digite as boundaries da integral da dimensão %d: ", i);
        scanf("%lf %lf", &a[i-1], &b[i-1]);
    }

    printf("Qual função você quer integrar: \n");
    printf("1 - sin(x)\n");
    printf("2 - x^3\n");
    printf("3 - e^(-x)\n");
    scanf("%d", &escolha);

    switch(escolha){
    case 1:
        g = seno;
        break;
    case 2:
        g = xaocubo;
        break;
    case 3:
        g = euler;
        b[0] = 1;
        break;
    default:
        return 0;
    }

    for(int i=0; i<dim; i++){
        c *= b[i]-a[i];
    }
    
    for(int i=0; i<n; i++){
        gera_aleatorio(x, dim);
        resp += calcula(g, x, dim, a, b);
    }
    
    resp = c*resp/n;
    printf("O valor da integral calculada por monte carlo com n = %d é: %lf\n", n, resp);
    
    free(a);
    free(b);
    free(x);
    
    return 0;
}
