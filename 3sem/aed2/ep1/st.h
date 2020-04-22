#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#ifndef ST_H
#define ST_H



//classe virtual pura que servirá apenas para ser herdada
template<class Chave, class Item>
class st{

  public:
    virtual void insere(Chave chave, Item valor) = 0;
    virtual Item devolve(Chave chave) = 0;
    virtual void remove(Chave chave) = 0;
    virtual int rank(Chave chave) = 0;
    virtual Chave seleciona(int k) = 0;
    virtual ~st() {};
    //função que vai servir para nossa st atualizar o valor de maneira diferente;
    template<class T>
    friend T att(T ant, T novo);
    
};

template<class Item>
Item att(Item ant, Item novo){

    return novo;
    
}


#endif
