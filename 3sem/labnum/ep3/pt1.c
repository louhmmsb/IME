#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 6


double x[] = {0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0};

double f[] = {0.0000, 1.5297, 9.5120, 8.7025, 2.8087, 1.0881, 0.3537};

double a[N+1];

//para calcular o denominador das contas para fazer o polinômio de newton
double calcula_den(int index){
    double resp = 1.0;
    for(int i=0; i<index; i++){
        resp*=x[index]-x[i];
    }
    return resp;
}

//para caucular o polinômio inteiro, index = 6
double calcula_p(int grau, double xp){
    double resp = f[0];
    double prod = 1.0;
    for(int i=1; i<=grau; i++){
        prod *= (xp - x[i-1]);
        resp += a[i]*prod;
    }
    return resp;
}

//para calcular o valor do coeficiente do termo de grau index
void calcula_a(int index){
    for(int i=1; i<=index; i++){
        a[i] = (f[i] - calcula_p(i-1, x[i]))/calcula_den(i);
    }
}

//para calcular todos os coeficientes
void calcula_as(){
    a[0] = f[0];
    for(int i=1; i<=N; i++){
        calcula_a(i);
    }
}

//calcular a área usando a regra do trapezoide
double trapezoid(int n){
    double h = (x[N]-x[0])/n;
    double area = 0.0;

    for(int i=1; i<=n-1; i++){
        area+=calcula_p(N, x[0]+i*h);
    }

    area = h*((f[0]+f[N])/2 + area);

    return area;
}



//calcular a área usando a regra de simpson
double simpsons(int n){
    double h = (x[N]-x[0])/(2*n);
    double area = 0.0;

    for(int i=0; i<=n-1; i++){
        area += (calcula_p(N, x[0]+2*i*h)+4*calcula_p(N, x[0]+(2*i+1)*h)+calcula_p(N, x[0]+(2*i+2)*h));
    }
    area *= (h/3);

    return area;
    
}


int main(int argc, char** argv){
    if(argc < 2){
        printf("Passe o n como argumento para rodar o programa.\n");
        return 0;
    }
    
    //setar todos os coeficientes
    calcula_as();

    //converter pra int o valor de n
    int n;
    sscanf(argv[1], "%d", &n);

    //resolver e printar
    if(argc == 3 && strcmp("latex", argv[2]) == 0){
        printf("%d & %lf & %lf \\\\\n", n, trapezoid(n), simpsons(n));
    }
    
    else{
    printf("Area calculada pela regra do trapezoide = %.7lf\n", trapezoid(n));
    printf("Area calculada pela regra de simpson    = %.7lf\n", simpsons(n));
    }

    return 0;
}
