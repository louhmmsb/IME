#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>

/*Esse sera o limite de iteracoes para assumir que o ponto nao converge*/
#define LIMITE 30

#define MAXRAIZES 100000

int convergiu;

/*Aqui começa o bloco onde defino as funcoes matematicas e suas derivadas*/
double complex f0(double complex x){

    return x*x*x*x - 1;
    
}


double complex df0(double complex x){

    return 4 * x*x*x;
    
}


double complex f1(double complex x){

    return x * x + 1;
    
}


double complex df1(double complex x){

    return 2 * x;
    
}


double complex f2(double complex x){

    return x*x*x - 1;
    
}


double complex df2(double complex x){

    return 3*x*x;
    
}


double complex f3(double complex x){

    return x*x*x - x;
    
}


double complex df3(double complex x){

    return 3*x*x - 1;
    
}


double complex f4(double complex x){

    return x*x*x*x*x*x*x*x + 15*x*x*x*x - 16;
    
}


double complex df4(double complex x){

    return 8*x*x*x*x*x*x*x + 60*x*x*x;
    
}

double complex f5(double complex x){

    return csin(x) - 1;
    
}

double complex df5(double complex x){

    return ccos(x);
    
}


/*Aqui termina o bloco onde defino as funcoes matematicas*/

/*Essa funcao avalia a funcao de indice i no ponto x0*/
double complex eval(int i, double complex x0);

/*Essa funcao avalia a derivada da funcao de indice i no ponto x0*/
double complex evalD(int i, double complex x0);

/*Aqui eu defino o array onde guardo todas as funcoes e suas derivadas*/
double complex (*funarr[6][2])(double complex) = { {f0, df0}, {f1, df1}, {f2, df2}, {f3, df3}, {f4, df4}, {f5, df5} };

/*Essa funcao faz a conta do metodo de newton (x - f(x)/f'(x)) para a funcao de indice i, no ponto x0*/
double complex g(int i, double complex x0);

/*Essa funcao aplica o metodo de newton para a funcao de indice i no ponto x0, com precisao de epsilon*/
double complex newton(int i, double complex x0, double epsilon);

/*Essa funcao cria os arquivos de texto com os pontos e usando um script em bash, os plota em gnuplot e depois deleta os arquivos de texto*/
void newton_basins(double complex x0, double complex xn, int nH, int nV);


int main(){

    int nH, nV;
    double x0r, x0i, xnr, xni;
    double complex x0, xn;

    printf("Qual resolução você quer (Pontos na HorizonalxPontos na Vertical): ") ;
    scanf("%dx%d", &nH, &nV);

    printf("Digite a parte real do ponto superior: ");
    scanf("%lf", &x0r);
    printf("Digite a parte imaginária do ponto superior: ");
    scanf("%lf", &x0i);
    x0 = x0r + x0i * I;

    printf("Digite a parte real do ponto inferior: ");
    scanf("%lf", &xnr);
    printf("Digite a parte imaginária do ponto inferior: ");
    scanf("%lf", &xni);
    xn = xnr + xni * I;

    newton_basins(x0, xn, nH, nV);
    
    return 0;
    
}

/*Aqui estao as implementacoes das funcoes que foram declaradas em cima da main*/
int comp(double complex x, double complex y, double epsilon){

    if(cabs(x-y)<epsilon) return 1;
    return 0;
    
}

double complex eval(int i, double complex x0){

    return funarr[i][0](x0);
    
}

double complex evalD(int i, double complex x0){

    return funarr[i][1](x0);
    
}

double complex g(int i, double complex x0){

    double complex a = x0 - funarr[i][0](x0)/funarr[i][1](x0);
    return a;
    
}

double complex newton(int i, double complex x0, double epsilon){

    double complex x, calc;
    int j = 0;
    
    x = g(i, x0);

    for(j = 0; j < LIMITE; j++){

        if(cabs(funarr[i][1](x)) < epsilon){

            convergiu = 0;
            break;
                
        }
        
        calc = g(i, x);

        if(cabs(funarr[i][0](x)) < epsilon) break;
        x = calc;
        
    }
    
    if(j == LIMITE) convergiu = 0;
    return x;
    
}

void newton_basins(double complex x0, double complex xn, int nH, int nV){

    int qualfunc, deu = 0, nraizes = 1, i = 0;
    double epsilon = 1e-8, x0r, x0i, xnr, xni, epsilonH, epsilonV;
    double complex p, calc, raizes[MAXRAIZES];
    char command[300];
    FILE *file;

    file = fopen("out.txt", "w");
    
    printf("Qual das seguintes funcoes voce quer simular:\n");
    printf("0:x^4 - 1 \n");
    printf("1:x^2 + 1 \n");
    printf("2:x^3 - 1 \n");
    printf("3:x^3 - x \n");
    printf("4:x^8 + 15x^4 - 16 \n");
    printf("5:sin(x) - 1\n");
    scanf("%d", &qualfunc);

    xnr = creal(xn);
    x0r = creal(x0);

    xni = cimag(xn);
    x0i = cimag(x0);

    epsilonH = (xnr - x0r)/nH;
    epsilonV = (xni - x0i)/nV;

    printf("Rodando...\n");
    
    for(p = x0; cimag(p) >= cimag(xn); p += epsilonV * I){

        for(; creal(p) <= creal(xn); p += epsilonH){

            convergiu = 1;
            calc = newton(qualfunc, p, epsilon);

            if(convergiu){
                    
                deu = 0;
                for(i=1; i<nraizes; i++){

                    if(cabs(calc - raizes[i]) <= 1000*epsilon){

                        deu = 1;
                        break;
                            
                    }
                        
                }

                if(deu == 1){

                    fprintf(file, "%lf %lf %d\n", creal(p), cimag(p), i);
                    
                }

                else {

                    raizes[i] = calc;
                    nraizes++;
                    fprintf(file, "%lf %lf %d\n", creal(p), cimag(p), i);
                        
                }
                    
            }

            else {
                
                fprintf(file, "%lf %lf %d\n", creal(p), cimag(p), 0);
                
            }
                
        }

        p = creal(x0) + cimag(p) * I;
            
    }

    fclose(file);

    
    
    sprintf(command, "./printa.sh %d %d %d %lf %lf %lf %lf", nraizes+1, nH, nV, x0r, xnr, xni, x0i);

    system(command);
    return;
    
}
