%{
#include <stdio.h>
    char nome_1[20], nome_2[20];
    int massan1, massan2, vidan1, vidan2, posxn1, posxn2, posyn1, posyn2, pmassa, praio, resolx, resoly;
    
    %}
L [a-zA-Z]
INT -?[0-9]+
FLOAT -?[0-9]*.[0-9]{3}
%%

%x lernome NOME:[a-zA-Z] 
NAVE1: {BEGIN()}

RESOLUÇÃO: {char x[5], y[5];
    for(i=0; i<4; i++){
	x[i]=yytext[i];
	y[i]=yytext[i+5];
    }
    x[4]="\0";
    y[4]="\0";
    resolx=atoi(x);
    resoly=atoi(y);
}
<lernome> {}
