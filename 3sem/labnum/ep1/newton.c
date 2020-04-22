#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>

#define LIMITE 30
#define MAXRAIZES 15

int convergiu;


int comp(double complex x, double complex y, double epsilon);


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


double complex eval(int i, double complex x0);


double complex evalD(int i, double complex x0);


double complex (*funarr[5][2])(double complex) = { {f0, df0}, {f1, df1}, {f2, df2}, {f3, df3}, {f4, df4} };


double complex g(int i, double complex x0);


double complex newton(int i, double complex x0, double epsilon);



int main(){

    int qualfunc, deu = 0, nraizes = 0, i = 0, nH, nV;
    double epsilon, x0r, x0i, xnr, xni, epsilonH, epsilonV;
    double complex x0, xn, p, calc, raizes[MAXRAIZES];
    char keep, name[22], command[25];
    FILE *files[MAXRAIZES];

    files[MAXRAIZES-1] = fopen("n.txt", "w");
    
    printf("Qual epsilon voce quer usar: ");
    scanf("%lf", &epsilon);

    printf("Quantos pontos você quer na vertical: ");
    scanf("%d", &nV);

    printf("Quantos pontos você quer na horizontal: ");
    scanf("%d", &nH);
    
    //printf("Qual a distância dos intervalos: ");
    //scanf("%lf", &epsilonI);
    
    printf("Qual das seguintes funcoes voce quer simular:\n");
    printf("0:x^4 - 1 \n");
    printf("1:x^2 + 1 \n");
    printf("2:x^3 - 1 \n");
    printf("3:x^3 - x \n");
    printf("4:x^8 + 15x^4 - 16 \n");
    scanf("%d", &qualfunc);

    printf("Digite o x0r: ");
    scanf("%lf", &x0r);
    printf("Digite o x0i: ");
    scanf("%lf", &x0i);
    x0 = x0r + x0i * I;

    printf("Digite o xnr: ");
    scanf("%lf", &xnr);
    printf("Digite o xni: ");
    scanf("%lf", &xni);
    xn = xnr + xni * I;

    epsilonH = (xnr - x0r)/nH;
    epsilonV = (xni = x0i)/nV;

    for(p = x0; cimag(p) >= cimag(xn); p -= epsilonV * I){

        for(; creal(p) <= creal(xn); p += epsilonH){

            convergiu = 1;
            calc = newton(qualfunc, p, epsilon);

            if(convergiu){
                //printf("%lf + %lfi converge para %lf + %lfi\n", creal(p), cimag(p), creal(calc), cimag(calc));
                    
                deu = 0;
                for(i=0; i<nraizes; i++){

                    if(cabs(calc - raizes[i]) < epsilon){

                        deu = 1;
                        break;
                            
                    }
                        
                }

                if(deu == 1){

                    fprintf(files[i], "%lf %lf\n", creal(p), cimag(p));
                    
                }

                else {

                    printf("Achei uma nova raiz: %lf %lfi\n", creal(calc), cimag(calc));
                    raizes[i] = calc;
                    nraizes++;
                    sprintf(name, "%d.txt", i);
                    files[i] = fopen(name, "w");
                    fprintf(files[i], "%lf %lf\n", creal(p), cimag(p));
                        
                }
                    
            }

            else {
                
                fprintf(files[MAXRAIZES-1], "%lf %lf\n", creal(p), cimag(p));
                
            }
                
        }

        p = creal(x0) + cimag(p) * I;
            
    }

    for(i=0; i<nraizes; i++){

        fclose(files[i]);
            
    }

    sprintf(command, "./printa.sh %d %d %d", nraizes+1, nH, nV);

    system(command);
    return 0;
    
}





//int comp(double complex x, double complex y, double epsilon){

//if(abs(creal(x)-creal(y)) < epsilon && abs(cimag(x)-cimag(y)) < epsilon) return 1;
//return 0;
    
//}

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

        //if(cabs(funarr[i][0](calc)) > cabs(funarr[i][0](x))){
            
        //printf("Esse x0 não esta convergindo para uma raiz\n");
        //convergiu = 0;
        //break;
            
        //}
        
        //if(comp(calc, x, epsilon)) break;
        if(cabs(funarr[i][0](x)) < epsilon) break;
        x = calc;
        
    }
    
    if(j == LIMITE) convergiu = 0;
    return x;
    
}
