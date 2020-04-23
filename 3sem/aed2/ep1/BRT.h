#include "st.h"
#ifndef BRT_H
#define BRT_h

using namespace std;

//Nodo da Rubro Negra
template<class Chave, class Item>
class BRTNode{

  private:
    Chave chae;
    Item data;
    char color;
    BRTNode *esq;
    BRTNode *dir;
    int subSize;

  public:
    void setChave(Chave nova);
    void setData(Item nova);
    void setColor();
    void setEsq(BRTNode *newEsq);
    void setDir(BRTNode *newDir);
    void setSS(int size);
    Chave getChave();
    Item getData();
    char getColor();
    int getPrio();
    BRTNode *&getEsq();
    BRTNode *&getDir();
    int getSS();
    BRTNode();
    
};

//bloco de funções dos nodos da Black-Red Tree
template<class Chave, class Item>
void BRTNode<Chave, Item>::setChave(Chave nova){

    chave = nova;
    
}

template<class Chave, class Item>
void BRTNode<Chave, Item>::setData(Item novo){

    data = novo;
    
}

template<class Chave, class Item>
void BRTNode<Chave, Item>::setColor(char novaCor){

    if(novaCor == 'r' || novaCor == 'b')
        color = novaCor;
    else cout<<"Cor inválida";
    
}

template<class Chave, class Item>
void BRTNode<Chave, Item>::setEsq(BRTNode<Chave, Item> *newEsq){

    esq = newEsq;
    
}

template<class Chave, class Item>
void BRTNode<Chave, Item>::setDir(BRTNode<Chave, Item> *newDir){

    dir = newDir;
    
}

template<class Chave, class Item>
void BRTNode<Chave, Item>::setSS(int size){

    subSize = size;
    
}

template<class Chave, class Item>
Chave BRTNode<Chave, Item>::getChave(){

    return chave;
    
}

template<class Chave, class Item>
Item BRTNode<Chave, Item>::getData(){

    return data;
    
}

template<class Chave, class Item>
int BRTNode<Chave, Item>::getColor(){

    return color;
    
}

template<class Chave, class Item>
BRTNode<Chave, Item>*& BRTNode<Chave, Item>::getEsq(){

    return esq;
    
}

template<class Chave, class Item>
BRTNode<Chave, Item>*& BRTNode<Chave, Item>::getDir(){

    return dir;
    
}

template<class Chave, class Item>
int BRTNode<Chave, Item>::getSS(){

    return subSize;
    
}

template<class Chave, class Item>
BRTNode<Chave, Item>::BRTNode(){

    color = 'r';
    subSize = 1;
    esq = dir = nullptr;
    
}

//classe que implementa a st usando uma Black-Red Tree
template<class Chave, class Item>
class BRT : public st<Chave, Item>{

  private:
    BRTNode<Chave, Item> *raiz;
    void rotEsq(BRTNode<Chave, Item> *&root);
    void rotDir(BRTNode<Chave, Item> *&root);
    void insereAux(Chave nova, Item novo, BRTNode<Chave, Item> *&w);
    void fixTree(BRTNode<Chave, Item> *&w);
    void removeAux(Chave chave, BRTNode<Chave, Item> *&w);
    void killTree(BRTNode<Chave, Item> *root);

  public:
    void insere(Chave nova, Item novo);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    BRT();
    ~BRT();
    
};

template<class Chave, class Item>
BRT<Chave, Item>::BRT(){

    raiz = nullptr;
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::rotEsq(BRTNode<Chave, Item> *&root){

    
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::insereAux(Chave nova, Item novo, BRTNode<Chave, Item> *&w){

    if(w->getChave() == nova){

        w->setData(att(w->getData(), novo));
        return;
        
    }
    
    if(w == nullptr){

        w = new BRTNode<Chave, Item>();
        w->setChave(nova);
        w->setData(1);
        
    }
    
    if(nova < w->getChave()){

        insereAux(nova, novo, w->getEsq());
        
    }

    else if(nova > w-getChave()){

        insereAux(nova, novo, w->getDir());
        
    }
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::insere(Chave nova, Item novo){

    if(raiz == nullptr){

        raiz = new BRTNode<Chave, Item>();
        raiz->setColor('b');
        raiz->setChave(nova);
        raiz->setData(1);
        
    }

    else insereAux(nova, novo, raiz);
    
}
