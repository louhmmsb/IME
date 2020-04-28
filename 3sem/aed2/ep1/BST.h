#include "st.h"
#ifndef BST_H
#define BST_H

using namespace std;

//Nodo da BST
template<class Chave, class Item>
class BSTNode{

  private:
    Chave chave;
    Item data;
    BSTNode *esq;
    BSTNode *dir;
    int subSize;

  public:
    void setChave(Chave nova);
    void setData(Item nova);
    void setEsq(BSTNode *newEsq);
    void setDir(BSTNode *newDir);
    void setSS(int size);
    Chave getChave();
    Item getData();
    BSTNode *getEsq();
    BSTNode *getDir();
    int getSS();
    BSTNode();
    
};

//bloco de funções dos nodos da BST
template<class Chave, class Item>
void BSTNode<Chave, Item>::setChave(Chave nova){

    chave = nova;
    
}

template<class Chave, class Item>
void BSTNode<Chave, Item>::setData(Item novo){

    data = novo;
    
}

template<class Chave, class Item>
void BSTNode<Chave, Item>::setEsq(BSTNode<Chave, Item> *newEsq){

    esq = newEsq;
    
}

template<class Chave, class Item>
void BSTNode<Chave, Item>::setDir(BSTNode<Chave, Item> *newDir){

    dir = newDir;
    
}

template<class Chave, class Item>
void BSTNode<Chave, Item>::setSS(int size){

    subSize = size;
    
}

template<class Chave, class Item>
Chave BSTNode<Chave, Item>::getChave(){

    return chave;
    
}

template<class Chave, class Item>
Item BSTNode<Chave, Item>::getData(){

    return data;
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>* BSTNode<Chave, Item>::getEsq(){

    return esq;
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>* BSTNode<Chave, Item>::getDir(){

    return dir;
    
}

template<class Chave, class Item>
int BSTNode<Chave, Item>::getSS(){

    return subSize;
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>::BSTNode(){

    esq = nullptr;
    dir = nullptr;
    subSize = 1;
    
}

//classe que implementa a st usando BST
template<class Chave, class Item>
class BST : public st<Chave, Item>{

  private:
    BSTNode<Chave, Item> *raiz;
    bool vazia;
    void insereAux(Chave nova, Item novo, BSTNode<Chave, Item> *w);
    BSTNode<Chave, Item> *fMin(BSTNode<Chave, Item> *w);
    BSTNode<Chave, Item> *removeMin(BSTNode<Chave, Item> *w);
    BSTNode<Chave, Item> *removeAux(Chave chave, BSTNode<Chave, Item> *w);
    void killTree(BSTNode<Chave, Item> *root);

  public:
    void insere(Chave nova, Item novo);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    BST();
    ~BST();
    
};

template<class Chave, class Item>
BST<Chave, Item>::BST(){

    raiz = new BSTNode<Chave, Item>();
    vazia = true;
    
}

template<class Chave, class Item>
void BST<Chave, Item>::killTree(BSTNode<Chave, Item> *root){

    if(root == nullptr) return;
    
    killTree(root->getEsq());
    killTree(root->getDir());

    delete root;
        
    
}

template<class Chave, class Item>
BST<Chave, Item>::~BST(){

    killTree(raiz);
    
}

template<class Chave, class Item>
void BST<Chave, Item>::insereAux(Chave nova, Item novo, BSTNode<Chave, Item> *w){

    if(nova < w->getChave()){

        if(w->getEsq() == nullptr){

            BSTNode<Chave, Item> *p = new BSTNode<Chave, Item>();
            p->setChave(nova);
            p->setData(1);
            w->setEsq(p);
            w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
            
        }

        else {

            insereAux(nova, novo, w->getEsq());
            w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);

        }
        
    }

    else if(nova > w->getChave()){

        if(w->getDir() == nullptr){
            
            BSTNode<Chave, Item> *p = new BSTNode<Chave, Item>();
            p->setChave(nova);
            p->setData(1);
            w->setDir(p);
            w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
            
        }

        else {
            
            insereAux(nova, novo, w->getDir());
            w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);

        }
        
    }

    else w->setData(att(w->getData(), novo));
    
}

template<class Chave, class Item>
void BST<Chave, Item>::insere(Chave nova, Item novo){

    if(vazia){

        raiz->setChave(nova);
        raiz->setData(1);
        vazia = false;
        return;
        
    }

    else insereAux(nova, novo, raiz);
    
}

template<class Chave, class Item>
Item BST<Chave, Item>::devolve(Chave chave){

    BSTNode<Chave, Item> *p = raiz;
    
    while(p != nullptr){

        if(chave < p->getChave()) p = p->getEsq();

        else if(chave > p->getChave()) p = p->getDir();

        else break;
        
    }

    if(p != nullptr) return p->getData();
    else return {};
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>* BST<Chave, Item>::fMin(BSTNode<Chave, Item> *w){

    if(w == nullptr) return nullptr;
    
    while(w->getEsq() != nullptr) w = w->getEsq();

    return w;
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>* BST<Chave, Item>::removeMin(BSTNode<Chave, Item> *root){

    if(root == nullptr) return nullptr;

    if(root->getEsq() == nullptr){

        BSTNode<Chave, Item> *aux = root->getDir();

        delete root;
        return aux;
        
    }

    else{

        root->setEsq(removeMin(root->getEsq()));
        return root;
        
    }
    
}

template<class Chave, class Item>
BSTNode<Chave, Item>* BST<Chave, Item>::removeAux(Chave chave, BSTNode<Chave, Item> *w){

    if(w == nullptr) return nullptr;
    
    if(chave == w->getChave()){

        if(w->getDir() == nullptr){

            BSTNode<Chave, Item> *aux = w->getEsq();
            
            delete w;
            
            return aux;
            
        }

        else {

            BSTNode<Chave, Item> *aux;

            aux = fMin(w->getDir());
            if(aux != nullptr){
                
                w->setChave(aux->getChave());
                w->setData(aux->getData());

            }
            w->setDir(removeMin(w->getDir()));
            
        }
            
        
    }
    
    else if(chave < w->getChave()){

        w->setEsq(removeAux(chave, w->getEsq()));
        w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
        
    }

    else if(chave > w->getChave()){

        w->setDir(removeAux(chave, w->getDir()));
        w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
        
    }

    return w;
    
}

template<class Chave, class Item>
void BST<Chave, Item>::remove(Chave chave){

    raiz = removeAux(chave, raiz);
    
}

template<class Chave, class Item>
int BST<Chave, Item>::rank(Chave chave){

    if(vazia) return -1;

    BSTNode<Chave, Item> *p = raiz;

    int r = 0;
    
    while(p != nullptr){

        if(chave < p->getChave()) p = p->getEsq();
        
        else if(chave > p->getChave()){

            r += p->getSS() - ((p->getDir() == nullptr)? 0 : p->getDir()->getSS());
            
            p = p->getDir();

        }

        else {

            r += ((p->getEsq() == nullptr)? 0 : p->getEsq()->getSS());
            return r;
            
        }
        
    }

    return -1;
    
}

template<class Chave, class Item>
Chave BST<Chave, Item>::seleciona(int k){

    BSTNode<Chave, Item> *p = raiz;
    
    while(p != nullptr){

        if(((p->getEsq() == nullptr)? 0 : p->getEsq()->getSS()) == k) return p->getChave();

        else if(((p->getEsq() == nullptr)? 0 : p->getEsq()->getSS()) < k){

            k = k - (((p->getEsq() == nullptr)? 0 : p->getEsq()->getSS()) + 1);
            p = p->getDir();
            
        }

        else p = p->getEsq();
        
    }

    return {};
    
}

#endif
