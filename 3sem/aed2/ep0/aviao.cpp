#include "aviao.h"
#include <iostream>

using namespace std;

void Aviao::setEspera(int novaEspera){
    
    Espera = novaEspera;
    
}

int Aviao::comb(){
    
    return Comb;
    
}

int Aviao::tempo(){
    
    return Tempo;
    
}

int Aviao::espera(){
    
    return Espera;
    
}

void Aviao::atualiza(){
    
    if(Dec == 0) Comb--;
    
}

int Aviao::emerg(){
    
    return Emerg;
    
}

void Aviao::setEmerg(int reason){
    
    Emerg = reason;
    
}

string Aviao::tag(){
    
    return Tag;
    
}

string Aviao::aero(){
    
    return Aero;
    
}

int Aviao::fila(){
    
    return Fila;
    
}

void Aviao::setFila(int nFila){
    
    Fila = nFila;
    
}

ostream & operator<<(ostream &out, Aviao aviao){
    
    out<<aviao.tag()<<" | "<<aviao.aero()<<" | ";
    
    if(aviao.tempo() != -1) out<<"T est: "<<aviao.tempo()<< " | ";
    
    else out<<"Comb: "<<aviao.comb()<<" | ";
    
    out<<"T esperado para ";
    
    if(aviao.tempo() != -1) out<<"decolar: ";
    
    else out<<"pousar: ";
    
    out<<aviao.espera()<< " | ";
    
    out<<"Emergência = ";
    
    if(aviao.emerg() == 0) out<<"Não";
    
    else if(aviao.emerg() == 1) out<<"Sim, causa: voo especial";
    
    else if(aviao.emerg() == 2) out<<"Sim, causa: combustível";
    
    else if(aviao.emerg() == 3) out<<"Sim, causa: esperou demais";
    
    cout<<" | Fila: "<<aviao.fila();
    
    cout<<endl;
    
    return out;
    
}

//passo como parâmetros o C e o V dados pelo usuário no começo da execução
Aviao::Aviao(int C, int V){
    
    int sorteador;
    const int emergchance = 25;

    //para criar a tag do aeroporto eu sorteio um dos possíveis lugares do vetor nomes
    Aero = AEROPORTOS[rand()%NAERO];

    //essa parte do código serve para dar (100/emergchance)% de chance do avião ser de emergência
    sorteador = rand()%emergchance;
    if (sorteador == 0) Emerg = 1;
    else Emerg = 0;

    //combustível é gerado aleatoriamente entre 1 e C
    Comb = rand()%C;
    Comb += 1;

    //isso decidirá se os avião irá decolar ou pousar
    Dec = rand()%2;
    
    //tempo estimado de voo é gerado aleatoriamente entre 1 e V para aviões que estão decolando, os que estão pousando recebem tempo -1
    if (Dec == 1){
        
        Tempo = rand()%V;
        Tempo += 1;
        
    }
    
    else Tempo = -1;

    //tempo de espera começa em 0 (existe apenas para aviões que vão decolar)
    Espera = 0;

    //a tag é gerada aleatoriamente a partir do vetor companhias e dois dígitos aleatórios
    Tag = COMPANHIAS[rand()%NCOMP] + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    
}


Aviao::Aviao(){
    
    char decide;

    cout<<"Digite se o avião é de emergência(S para emerg e N para normal): ";
    cin>>decide;

    if(decide == 'S') Emerg = true;
    else Emerg = false;
    
    cout<<"Digite a tag do avião: ";
    cin>>Tag;

    cout<<"Digite se o avião quer pousar ou decolar (Escreva D para decolar e P para pousar): ";
    cin>>decide;

    if(decide == 'P'){
        
        Tempo = -1;

        cout<<"Digite a quantidade de combustível: ";
        cin>>Comb;

        cout<<"Digite de qual aeroporto o avião veio: ";
        cin>>Aero;
        
    }
    
    else {
        
        cout<<"Tempo esperado de voo do avião: ";
        cin>>Tempo;

        cout<<"Digite para qual aeroporto o avião vai: ";
        cin>>Aero;
        
    }

    
        
}
