#include "st.h"
#ifndef TREAP_H
#define TREAP_H

#define MAX 100

using namespace std;

//Nodo da TREAP
template<class Chave, class Item>
class TNode{

  private:
    Chave chave;
    Item data;
    int prio;
    TNode *esq;
    TNode *dir;
    int subSize;

  public:
    void setChave(Chave nova);
    void setData(Item nova);
    void setEsq(TNode *newEsq);
    void setDir(TNode *newDir);
    void setSS(int size);
    Chave getChave();
    Item getData();
    int getPrio();
    TNode *&getEsq();
    TNode *&getDir();
    int getSS();
    TNode();
    
};

//bloco de funções dos nodos da T
template<class Chave, class Item>
void TNode<Chave, Item>::setChave(Chave nova){

    chave = nova;
    
}

template<class Chave, class Item>
void TNode<Chave, Item>::setData(Item novo){

    data = novo;
    
}

template<class Chave, class Item>
void TNode<Chave, Item>::setEsq(TNode<Chave, Item> *newEsq){

    esq = newEsq;
    
}

template<class Chave, class Item>
void TNode<Chave, Item>::setDir(TNode<Chave, Item> *newDir){

    dir = newDir;
    
}

template<class Chave, class Item>
void TNode<Chave, Item>::setSS(int size){

    subSize = size;
    
}

template<class Chave, class Item>
Chave TNode<Chave, Item>::getChave(){

    return chave;
    
}

template<class Chave, class Item>
Item TNode<Chave, Item>::getData(){

    return data;
    
}

template<class Chave, class Item>
int TNode<Chave, Item>::getPrio(){

    return prio;
    
}

template<class Chave, class Item>
TNode<Chave, Item>*& TNode<Chave, Item>::getEsq(){

    return esq;
    
}

template<class Chave, class Item>
TNode<Chave, Item>*& TNode<Chave, Item>::getDir(){

    return dir;
    
}

template<class Chave, class Item>
int TNode<Chave, Item>::getSS(){

    return subSize;
    
}

template<class Chave, class Item>
TNode<Chave, Item>::TNode(){

    prio = rand() % MAX;
    esq = nullptr;
    dir = nullptr;
    subSize = 1;
    
}

//classe que implementa a st usando TREAP
template<class Chave, class Item>
class TREAP : public st<Chave, Item>{
    
  private:
    TNode<Chave, Item> *raiz;
    void rotEsq(TNode<Chave, Item> *&root);
    void rotDir(TNode<Chave, Item> *&root);
    void insereAux(Chave nova, Item novo, TNode<Chave, Item> *&w);
    void removeAux(Chave chave, TNode<Chave, Item> *&w);
    void killTree(TNode<Chave, Item> *root);
    void showAux(TNode<Chave, Item> *root); //para debugar

  public:
    void insere(Chave nova, Item novo);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    TREAP();
    ~TREAP();
    void show(); //para debugar
    
};

template<class Chave, class Item>
TREAP<Chave, Item>::TREAP(){

    raiz = nullptr;
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::killTree(TNode<Chave, Item> *root){

    if(root == nullptr) return;

    killTree(root->getEsq());
    killTree(root->getDir());

    delete root;
    
}

template<class Chave, class Item>
TREAP<Chave, Item>::~TREAP(){

    killTree(raiz);
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::rotEsq(TNode<Chave, Item> *&root){

    TNode<Chave, Item> *rr = root->getDir(), *rrl = root->getDir()->getEsq(), *a = root->getEsq(), *b = rrl, *c = root->getDir()->getDir();
    
    //cout<<"\nAntes ESQ\n--------------------------\n"<<endl<<"Raiz = "<<root->getChave()<<endl;
    //show();
    rr->setEsq(root);
    root->setDir(rrl);
    root = rr;
    //cout<<"\nDepois ESQ\n--------------------------\n"<<endl;
    //show();

    root->getEsq()->setSS(((a == nullptr)? 0 : a->getSS()) + ((b == nullptr)? 0 : b->getSS()) + 1);
    root->setSS(root->getEsq()->getSS() + ((c == nullptr)? 0 : c->getSS()) + 1);
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::rotDir(TNode<Chave, Item> *&root){

    TNode<Chave, Item> *rl = root->getEsq(), *rlr = root->getEsq()->getDir(), *a = root->getEsq()->getEsq(), *b  = rlr, *c = root->getDir();

    //cout<<"\nAntes DIR\n--------------------------\n"<<endl<<"Raiz = "<<root->getChave()<<endl;
    //show();
    rl->setDir(root);
    root->setEsq(rlr);
    root = rl;
    //cout<<"\nDepois DIR\n--------------------------\n"<<endl;
    //show();

    root->getDir()->setSS(((b == nullptr)? 0 : b->getSS()) + ((c == nullptr)? 0 : c->getSS()) + 1);
    root->setSS(root->getDir()->getSS() + ((a == nullptr)? 0 : a->getSS()) + 1);
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::insereAux(Chave nova, Item novo, TNode<Chave, Item> *&w){

    if(w == nullptr){

        w = new TNode<Chave, Item>();
        w->setChave(nova);
        w->setData(1);
        return;
        
    }

    else if(w->getChave() == nova){

        w->setData(att(w->getData(), novo));
        
    }

    if(nova < w->getChave()){

        insereAux(nova, novo, w->getEsq());
        if(w->getEsq() != nullptr && w->getEsq()->getPrio() > w->getPrio()) rotDir(w);
        w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
        
    }

    else if(nova > w->getChave()){
        
        insereAux(nova, novo, w->getDir());
        if(w->getDir() != nullptr && w->getDir()->getPrio() > w->getPrio()) rotEsq(w);
        w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
        
    }
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::insere(Chave nova, Item novo){
    
    insereAux(nova, novo, raiz);
    
}

template<class Chave, class Item>
Item TREAP<Chave, Item>::devolve(Chave chave){

    TNode<Chave, Item> *p = raiz;
    Item resp;
    
    while(1){

        if(p == nullptr) return {};
        
        if(chave < p->getChave()) p = p->getEsq();

        else if(chave > p->getChave()) p = p->getDir();

        else {

            resp = p->getData();
            break;
            
        }
        
    }

    return resp;
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::removeAux(Chave chave, TNode<Chave, Item> *&w){

    if(w == nullptr) return;

    if(chave < w->getChave()){

        removeAux(chave, w->getEsq());
                  
    }

    else if(chave > w->getChave()){
            
        removeAux(chave, w->getDir());

    }
    
    else {

        //caso seja folha
        if(w->getEsq() == nullptr && w->getDir() == nullptr){

            delete w;
            w = nullptr;
            return;
            
        }

        //caso tenha os dois filhos
        //desse jeito eu mando o nodo q eu tenho q remover pra baixo no treap até q ele se torne uma folha
        else if(w->getEsq() != nullptr && w->getDir() != nullptr){

            if(w->getEsq()->getPrio() < w->getDir()->getPrio()){
                
                rotEsq(w);
                
                removeAux(chave, w->getEsq());

            }

            else {

                rotDir(w);

                removeAux(chave, w->getDir());
            
            }

        }

        //caso só tenha um filho eu só preciso remover o nodo e colar o filho dele no resto da árvore
        else {

            TNode<Chave, Item> *f = (w->getEsq() != nullptr)? w->getEsq() : w->getDir();
            
            delete w;
            w = nullptr;
            w = f;
                
        }
        
    }

    w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::remove(Chave chave){

    if(raiz == nullptr) return;

    removeAux(chave, raiz);
    
}

template<class Chave, class Item>
int TREAP<Chave, Item>::rank(Chave chave){

    if(raiz == nullptr) return -1;

    TNode<Chave, Item> *p = raiz;

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
Chave TREAP<Chave, Item>::seleciona(int k){

    TNode<Chave, Item> *p = raiz;
    
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

template<class Chave, class Item>
void TREAP<Chave, Item>::showAux(TNode<Chave, Item> *root){

    if(root == nullptr) return;

    showAux(root->getEsq());

    cout<<root->getChave()<<endl;

    showAux(root->getDir());
    
}

template<class Chave, class Item>
void TREAP<Chave, Item>::show(){

    showAux(raiz);
    
}

#endif
