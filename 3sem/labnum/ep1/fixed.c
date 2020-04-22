#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//f(x) = exp(x) -  2x^2;
//f'(x) = exp(x) - 4x;



int convergiu;

//função f dada no enunciado
double f(double x);

//primeira derivada de f(x) (em função de x)
double df(double x);

//primeira função de ponto fixo x - f(x)
double g1(double x);

//segunda função de ponto fixo x - f(x)/f'(x)
double g2(double x);

//função que vai calcular as iterações
double gk(double (*g)(double), double epsilon, double x0);





int main(){

    double epsilon, x0, raiz, (*func)(double);
    char c;
    int qualfunc, primeira = 0;
    
    printf("Qual precisao voce quer nos calculos (coloque na forma de 0.1, 0.01, etc): ");
    scanf("%lf", &epsilon);

    while(1){
        
        if(primeira != 0){
            printf("Voce quer tentar mais uma raiz (s para sim e n para nao): ");   
            scanf(" %c", &c);
            if(c == 'n') break;
        
        }
        
        primeira = 1;
        
        convergiu = 1;
        printf("Digite o x0 para procurar uma das raizes: ");
        scanf("%lf", &x0);

        printf("Qual funcao de ponto fixo voce quer usar? (A função 2 acha todas as raizes)\n");
        printf("1: x - f(x)\n");
        printf("2: x - f(x)/df(x)\n");
        fflush(stdin);
        scanf("%d", &qualfunc);

        if(qualfunc == 1) func = g1;
        else if(qualfunc == 2) func = g2;
        
        
        raiz = gk(func, epsilon, x0);

        if(convergiu == 0) continue;
        else{

            printf("Encontrei a raiz: %lf\n", raiz);
            
        }

    }

    return 0;
        
}




double f(double x){

    return exp(x)-2*x*x;
        
}

double df(double x){

    return exp(x)-4*x;
    
}

double g1(double x){

    return x - f(x);
    
}

double g2(double x){

    return x - f(x)/df(x);
    
}

double gk(double (*g)(double), double epsilon, double x0){

    double x, calc;
    x = g(x0);

    while(1){

        calc = g(x);

        if(abs(f(calc)) > abs(f(x))){
            
            printf("Esse x0 não esta convergindo\n");
            convergiu = 0;
            break;
            
        }
        
        if(calc > x-epsilon && calc < x+epsilon) break;
        x = calc;
        
    }

    return x;
    
}
