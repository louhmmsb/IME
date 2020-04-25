#include "st.h"
#ifndef BRT_H
#define BRT_h

using namespace std;

//Nodo da Rubro Negra
template<class Chave, class Item>
class BRTNode{

  private:
    Chave chave;
    Item data;
    char color;
    BRTNode *esq;
    BRTNode *dir;
    int subSize;

  public:
    void setChave(Chave nova);
    void setData(Item nova);
    void setColor(char novaCor);
    void change();
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
void BRTNode<Chave, Item>::change(){

    color = (color == 'r')? 'b' : 'r';
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
char BRTNode<Chave, Item>::getColor(){

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
    int size(BRTNode<Chave, Item> *q);
    void rotEsq(BRTNode<Chave, Item> *&root);
    void rotDir(BRTNode<Chave, Item> *&root);
    bool isRed(BRTNode<Chave, Item>  *root);
    bool check1(BRTNode<Chave, Item> *root);
    bool check2(BRTNode<Chave, Item> *root);
    bool check3(BRTNode<Chave, Item> *root);
    void flip(BRTNode<Chave, Item> *root);
    void moveVE(BRTNode<Chave, Item> *&root);
    void moveVD(BRTNode<Chave, Item> *&root);
    void arruma(BRTNode<Chave, Item> *&w);
    void insereAux(Chave nova, Item novo, BRTNode<Chave, Item> *&w);
    BRTNode<Chave, Item> achaMin(BRTNode<Chave, Item> *root);
    void removeMin(BRTNode<Chave, Item> *&root);
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
void BRT<Chave, Item>::killTree(BRTNode<Chave, Item> *root){

    if(root == nullptr) return;
    
    killTree(root->getEsq());
    killTree(root->getDir());
    delete root;
    
}

template<class Chave, class Item>
BRT<Chave, Item>::~BRT(){

    killTree(raiz);
    
}

template<class Chave, class Item>
int BRT<Chave, Item>::size(BRTNode<Chave, Item> *q){

    return (q == nullptr)? 0 : q->getSS();
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::rotEsq(BRTNode<Chave, Item> *&root){

    BRTNode<Chave, Item> *rr = root->getDir(), *rrl = root->getDir()->getEsq(), *a = root->getEsq(), *b = rrl, *c = root->getDir()->getDir();
    
    rr->setColor(root->getColor());
    root->setColor('r');
    
    rr->setEsq(root);
    root->setDir(rrl);
    root = rr;

    root->getEsq()->setSS(((a == nullptr)? 0 : a->getSS()) + ((b == nullptr)? 0 : b->getSS()) + 1);
    root->setSS(root->getEsq()->getSS() + ((c == nullptr)? 0 : c->getSS()) + 1);
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::rotDir(BRTNode<Chave, Item> *&root){

    BRTNode<Chave, Item> *rl = root->getEsq(), *rlr = root->getEsq()->getDir(), *a = root->getEsq()->getEsq(), *b  = rlr, *c = root->getDir();

    rl->setColor(root->getColor());
    root->setColor('r');
    
    rl->setDir(root);
    root->setEsq(rlr);
    root = rl;

    root->getDir()->setSS(((b == nullptr)? 0 : b->getSS()) + ((c == nullptr)? 0 : c->getSS()) + 1);
    root->setSS(root->getDir()->getSS() + ((a == nullptr)? 0 : a->getSS()) + 1);
    
}

template<class Chave, class Item>
bool BRT<Chave, Item>::isRed(BRTNode<Chave, Item> *root){

    return (root == nullptr || root->getColor() == 'b')? false : true;
    
}

template<class Chave, class Item>
bool BRT<Chave, Item>::check1(BRTNode<Chave, Item> *root){

    return (!isRed(root->getEsq()) && isRed(root->getDir()));
    
}

template<class Chave, class Item>
bool BRT<Chave, Item>::check2(BRTNode<Chave, Item> *root){

    return (isRed(root->getEsq()) && isRed(root->getEsq()->getEsq()));
    
}

template<class Chave, class Item>
bool BRT<Chave, Item>::check3(BRTNode<Chave, Item> *root){

    return (isRed(root->getEsq()) && isRed(root->getDir()));
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::flip(BRTNode<Chave, Item> *root){

    root->change();
    root->getDir()->change();
    root->getEsq()->change();
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::moveVE(BRTNode<Chave, Item> *&root){

    flip(root);
    
    if(isRed(root->getDir()->getEsq())){

        rotDir(root->getDir());
        rotEsq(root);
        flip(root);
        
    }
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::moveVD(BRTNode<Chave, Item> *&root){

    flip(root);
    if(isRed(root->getEsq()->getEsq())){

        rotDir(root);
        flip(root);
        
    }
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::arruma(BRTNode<Chave, Item> *&root){

    if(isRed(root->getDir())) rotEsq(root);
    if(check2(root)) rotDir(root);
    if(check3(root)) flip(root);

    root->setSS((((root->getDir() == nullptr)? 0 : root->getDir()->getSS())) + (((root->getEsq() == nullptr)? 0 : root->getEsq()->getSS())) + 1);
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::insereAux(Chave nova, Item novo, BRTNode<Chave, Item> *&w){
    
    if(w == nullptr){

        w = new BRTNode<Chave, Item>();
        w->setChave(nova);
        w->setData(1);
        return;
        
    }
    
    if(nova < w->getChave()) insereAux(nova, novo, w->getEsq());

    else if(nova > w->getChave()) insereAux(nova, novo, w->getDir());

    else w->setData(att(w->getData(), novo));

    if(check1(w)) rotEsq(w);
    if(check2(w)) rotDir(w);
    if(check3(w)) flip(w);

    w->setSS((((w->getDir() == nullptr)? 0 : w->getDir()->getSS())) + (((w->getEsq() == nullptr)? 0 : w->getEsq()->getSS())) + 1);
    
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

    raiz->setColor('b');
    
}

template<class Chave, class Item>
Item BRT<Chave, Item>::devolve(Chave chave){

    BRTNode<Chave, Item> *p = raiz;
    
    while(p != nullptr){

        if(p->getChave() == chave) return p->getData();

        else if(chave < p->getChave()) p = p->getEsq();

        else if(chave > p->getChave()) p = p->getDir();
        
    }

    return {};
    
}

template<class Chave, class Item>
BRTNode<Chave, Item> BRT<Chave, Item>::achaMin(BRTNode<Chave, Item> *root){
    
    while(root->getEsq() != nullptr) root = root->getEsq();

    return *(root);
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::removeMin(BRTNode<Chave, Item> *&root){

    if(root->getEsq() == nullptr){

        delete root;
        root = nullptr;
        
    }

    if(!isRed(root->getEsq()) && !isRed(root->getEsq()->getEsq())){

        moveVE(root);
        
    }

    removeMin(root->getEsq());
    arruma(root);
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::removeAux(Chave chave, BRTNode<Chave, Item> *&w){

    if(w == nullptr) return;

    if(chave < w->getChave()){

        if(!isRed(w->getEsq()) && !isRed(w->getEsq()->getEsq())) moveVE(w);
        removeAux(chave, w->getEsq());
        
    }

    else {

        if(isRed(w->getEsq())) rotDir(w);

        if(chave == w->getChave() && w->getDir() == nullptr){

            delete w;
            w = nullptr;
            return;
            
        }

        if(!isRed(w->getDir()) && !isRed(w->getDir()->getEsq())) moveVD(w);
        
        if(chave == w->getChave()){

            BRTNode<Chave, Item> menor = achaMin(w->getDir());

            w->setChave(menor.getChave());
            w->setData(menor.getData());

            removeMin(w->getDir());
            
        }

        else removeAux(chave, w->getDir());
        
    }

    arruma(w);
    
}

template<class Chave, class Item>
void BRT<Chave, Item>::remove(Chave chave){

    if(!isRed(raiz->getEsq()) && !isRed(raiz->getDir())) raiz->setColor('r');
    
    removeAux(chave, raiz);
    
}

template<class Chave, class Item>
int BRT<Chave, Item>::rank(Chave chave){

   if(raiz == nullptr) return -1;

    BRTNode<Chave, Item> *p = raiz;

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
Chave BRT<Chave, Item>::seleciona(int k){

    BRTNode<Chave, Item> *p = raiz;
    
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
