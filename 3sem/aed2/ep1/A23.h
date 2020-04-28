#include "st.h"
#ifndef A23_H
#define A23_H

using namespace std;

//Nodo da 2-3
template<class Chave, class Item>
class A23Node{

  private:
    Chave chaveEsq;
    Chave chaveDir;
    Item dataEsq;
    Item dataDir;
    A23Node *esq;
    A23Node *meio;
    A23Node *dir;
    int subSize;
    bool no3;
    bool buraco;

  public:
    void setChaveEsq(Chave nova);
    void setChaveDir(Chave nova);
    void setDataEsq(Item nova);
    void setDataDir(Item nova);
    void setEsq(A23Node *newEsq);
    void setMeio(A23Node *newMeio);
    void setDir(A23Node *newDir);
    void setSS(int size);
    void set3(bool nodetype);
    void setBuraco(bool newBuraco);
    Chave getChaveEsq();
    Chave getChaveDir();
    Item getDataEsq();
    Item getDataDir();
    A23Node *&getEsq();
    A23Node *&getMeio();
    A23Node *&getDir();
    int getSS();
    bool is3();
    bool isBuraco();
    A23Node();
    
};

//bloco de funções dos nodos da 2-3

template<class Chave, class Item>
void A23Node<Chave, Item>::setChaveEsq(Chave nova){

    chaveEsq = nova;
    
}


template<class Chave, class Item>
void A23Node<Chave, Item>::setChaveDir(Chave nova){

    chaveDir = nova;
    
}


template<class Chave, class Item>
void A23Node<Chave, Item>::setDataEsq(Item nova){

    dataEsq = nova;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setDataDir(Item nova){

    dataDir = nova;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setEsq(A23Node *newEsq){

    esq = newEsq;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setMeio(A23Node *newMeio){

    meio = newMeio;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setDir(A23Node *newDir){

    dir = newDir;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setSS(int size){

    subSize = size;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::set3(bool nodetype){

    no3 = nodetype;
    
}

template<class Chave, class Item>
void A23Node<Chave, Item>::setBuraco(bool newBuraco){

    buraco = newBuraco;

}

template<class Chave, class Item>
Chave A23Node<Chave, Item>::getChaveEsq(){

    return chaveEsq;
    
}

template<class Chave, class Item>
Chave A23Node<Chave, Item>::getChaveDir(){

    return chaveDir;
    
}

template<class Chave, class Item>
Item A23Node<Chave, Item>::getDataEsq(){

    return dataEsq;
    
}

template<class Chave, class Item>
Item A23Node<Chave, Item>::getDataDir(){

    return dataDir;
    
}

template<class Chave, class Item>
A23Node<Chave, Item>*& A23Node<Chave, Item>::getEsq(){

    return esq;
    
}

template<class Chave, class Item>
A23Node<Chave, Item>*& A23Node<Chave, Item>::getMeio(){

    return meio;
    
}

template<class Chave, class Item>
A23Node<Chave, Item>*& A23Node<Chave, Item>::getDir(){

    return dir;
    
}

template<class Chave, class Item>
int A23Node<Chave, Item>::getSS(){

    return subSize;
    
}

template<class Chave, class Item>
bool A23Node<Chave, Item>::is3(){

    return no3;
    
}

template<class Chave, class Item>
bool A23Node<Chave, Item>::isBuraco(){

    return buraco;
    
}

template<class Chave, class Item>
A23Node<Chave, Item>::A23Node(){

    esq = nullptr;
    meio = nullptr;
    dir  = nullptr;
    subSize = 1;
    no3 = false;
    buraco = false;
    
}

//class que implementa a st usando uma 2-3
template<class Chave, class Item>
class A23 : public st<Chave, Item>{

  private:
    A23Node<Chave, Item> *raiz;
    bool cresceu;
    bool achei(Chave chave, A23Node<Chave, Item> *root);
    int compara(Chave chave, A23Node<Chave, Item> *root);
    void explode(Chave chave, Item novo, A23Node<Chave, Item> *&root);
    void insereAux(Chave chave, Item novo, A23Node<Chave, Item> *&root);
    void caso1(A23Node<Chave, Item> *&root);
    void caso2(A23Node<Chave, Item> *&root);
    void caso3(A23Node<Chave, Item> *&root);
    void caso4(A23Node<Chave, Item> *&root);
    void removeMin(A23Node<Chave, Item> *&root);
    A23Node<Chave, Item> achaMin(A23Node<Chave, Item> *root);
    void removeAux(Chave chave, A23Node<Chave, Item> *&root);
    int sizeTree(A23Node<Chave, Item> *root);
    void killTree(A23Node<Chave, Item> *root);

  public:
    void insere(Chave nova, Item novo);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    A23();
    ~A23();
    
};

template<class Chave, class Item>
A23<Chave, Item>::A23(){

    raiz = nullptr;
    
}

template<class Chave, class Item>
void A23<Chave, Item>::killTree(A23Node<Chave, Item> *root){

    if(root == nullptr) return;
    
    killTree(root->getEsq());
    killTree(root->getMeio());
    killTree(root->getDir());
    
    delete root;
    
}

template<class Chave, class Item>
A23<Chave, Item>::~A23(){

    killTree(raiz);
    
}

template<class Chave, class Item>
bool A23<Chave, Item>::achei(Chave chave, A23Node<Chave, Item> *root){

    if(chave == root->getChaveEsq()) return true;

    if(root->is3() && chave == root->getChaveDir()) return true;

    return false;
    
}

template<class Chave, class Item>
int A23<Chave, Item>::compara(Chave chave, A23Node<Chave, Item> *root){

    if(chave < root->getChaveEsq()) return -1;
    
    if(!root->is3()) return 0;

    else {

        if(chave < root->getChaveDir()) return 0;
        
    }

    return 1;
    
}

template<class Chave, class Item>
void A23<Chave, Item>::explode(Chave chave, Item novo, A23Node<Chave, Item> *&root){

    root->set3(false);

    A23Node<Chave, Item> *novaEsq = new A23Node<Chave, Item>(), *novaDir = new A23Node<Chave, Item>();

    novaEsq->set3(false);
    novaDir->set3(false);
    novaEsq->setBuraco(false);
    novaDir->setBuraco(false);
        
    if(chave < root->getChaveEsq()){

        novaEsq->setChaveEsq(chave);
        novaEsq->setDataEsq(novo);

        novaDir->setChaveEsq(root->getChaveDir());
        novaDir->setDataEsq(root->getDataDir());
        
    }

    else if(chave > root->getChaveDir()){

        novaEsq->setChaveEsq(root->getChaveEsq());
        novaEsq->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getChaveDir());
        root->setDataEsq(root->getDataDir());

        novaDir->setChaveEsq(chave);
        novaDir->setDataEsq(novo);        
        
    }

    else {

        novaDir->setChaveEsq(root->getChaveDir());
        novaDir->setDataEsq(root->getDataDir());

        novaEsq->setChaveEsq(root->getChaveEsq());
        novaEsq->setDataEsq(root->getDataEsq());

        root->setChaveEsq(chave);
        root->setDataEsq(novo);
        
    }

    root->setEsq(novaEsq);
    root->setMeio(novaDir);
    root->setDir(nullptr);
    
}

template<class Chave, class Item>
void A23<Chave, Item>::insereAux(Chave nova, Item novo, A23Node<Chave, Item> *&root){

    if(root->getEsq() == nullptr){

        if(!root->is3()){

            if(nova == root->getChaveEsq()){

                root->setDataEsq(att(root->getDataEsq(), novo));
                cresceu = false;
                return;

            }

            else {

                if(nova < root->getChaveEsq()){

                    root->setChaveDir(root->getChaveEsq());
                    root->setDataDir(root->getDataEsq());

                    root->setChaveEsq(nova);
                    root->setDataEsq(novo);

                    cresceu  = false;

                    root->set3(true);
                    return;
                    
                }

                else {

                    root->setChaveDir(nova);
                    root->setDataDir(novo);

                    cresceu = false;
                    
                    root->set3(true);
                    return;
                    
                }
                
            }
            
        }
        
        else {
            
            if(nova == root->getChaveDir()){
                
                root->setDataDir(att(root->getDataDir(), novo));
                cresceu = false;
                
            }
            
            else if(nova > root->getChaveDir()){
                
                explode(nova, novo, root);
                cresceu = true;
                
            }

            else if(nova == root->getChaveEsq()){
                
                root->setDataEsq(att(root->getDataEsq(), novo));
                cresceu = false;
                
            }

            else if(nova > root->getChaveEsq()){

                explode(nova, novo, root);
                cresceu = true;
                
            }

            else {

                explode(nova, novo, root);
                cresceu = true;
                
            }
            
        }
        
    }

    else {

        if(nova == root->getChaveEsq()){

            root->setDataEsq(att(root->getDataEsq(), novo));
            cresceu = false;
            
        }

        else if(!root->is3()){

            if(nova < root->getChaveEsq()){

                insereAux(nova, novo, root->getEsq());
                if(cresceu){

                    root->setChaveDir(root->getChaveEsq());
                    root->setDataDir(root->getDataEsq());

                    root->setChaveEsq(root->getEsq()->getChaveEsq());
                    root->setDataEsq(root->getEsq()->getDataEsq());

                    root->setDir(root->getMeio());
                    root->setMeio(root->getEsq()->getMeio());

                    A23Node<Chave, Item> *aux = root->getEsq();
                    
                    root->setEsq(root->getEsq()->getEsq());

                    delete aux;
                    aux  = nullptr;

                    cresceu = false;
                    root->set3(true);
                    
                }
                
            } 

            else {

                insereAux(nova, novo, root->getMeio());
                if(cresceu){

                    root->setChaveDir(root->getMeio()->getChaveEsq());
                    root->setDataDir(root->getMeio()->getDataEsq());

                    root->setDir(root->getMeio()->getMeio());

                    A23Node<Chave, Item> *aux = root->getMeio();
                    
                    root->setMeio(root->getMeio()->getEsq());

                    delete aux;
                    aux = nullptr;

                    cresceu = false;
                    root->set3(true);
                    
                }

            }
            
        }

        else{

            if(nova == root->getChaveDir()){

                root->setDataDir(att(root->getDataEsq(), novo));
                cresceu = false;
                
            }

            else if(nova > root->getChaveDir()){

                insereAux(nova, novo, root->getDir());
                if(cresceu){

                    A23Node<Chave, Item> *novoMeio = new A23Node<Chave, Item>();

                    novoMeio->setChaveEsq(root->getChaveDir());
                    novoMeio->setDataEsq(root->getDataDir());

                    root->set3(false);

                    novoMeio->setEsq(root);
                    novoMeio->setMeio(root->getDir());

                    root->setDir(nullptr);

                    root = novoMeio;

                    cresceu = true;
                    
                }
                
            }

            else if(nova > root->getChaveEsq()){

                insereAux(nova, novo, root->getMeio());

                if(cresceu){

                    A23Node<Chave, Item> *e = new A23Node<Chave, Item>(), *d = new A23Node<Chave, Item>(), *aux;

                    e->set3(false);
                    e->setBuraco(false);
                    d->set3(false);
                    d->setBuraco(false);
                    root->getMeio()->set3(false);
                    root->getMeio()->setBuraco(false);

                    e->setChaveEsq(root->getChaveEsq());
                    e->setDataEsq(root->getDataEsq());

                    d->setChaveEsq(root->getChaveDir());
                    d->setDataEsq(root->getDataDir());

                    e->setEsq(root->getEsq());
                    e->setMeio(root->getMeio()->getEsq());

                    d->setEsq(root->getMeio()->getMeio());
                    d->setMeio(root->getDir());

                    root->getMeio()->setEsq(e);
                    root->getMeio()->setMeio(d);

                    aux = root;

                    root = root->getMeio();

                    delete aux;

                    cresceu = true;

                }

            }

            else {

                insereAux(nova, novo, root->getEsq());

                if(cresceu){
                    
                    A23Node<Chave, Item> *novoMeio = new A23Node<Chave, Item>();

                    novoMeio->set3(false);
                    novoMeio->setBuraco(false);
                    root->set3(false);
                    root->setBuraco(false);

                    novoMeio->setChaveEsq(root->getChaveEsq());
                    novoMeio->setDataEsq(root->getDataEsq());

                    novoMeio->setEsq(root->getEsq());

                    root->setChaveEsq(root->getChaveDir());
                    root->setDataEsq(root->getDataDir());
                    root->setEsq(root->getMeio());
                    root->setMeio(root->getDir());
                    root->setDir(nullptr);

                    novoMeio->setMeio(root);
                
                    root = novoMeio;

                    cresceu = true;

                }

            }
            
        }
        
    }
    
}

template<class Chave, class Item>
void A23<Chave, Item>::insere(Chave nova, Item novo){

    if(raiz == nullptr){

        raiz = new A23Node<Chave,Item>();
        raiz->setChaveEsq(nova);
        raiz->setDataEsq(1);
        raiz->set3(false);
        raiz->setBuraco(false);
        raiz->setEsq(nullptr);
        
    }

    else insereAux(nova, novo, raiz);
    
}

template<class Chave, class Item>
Item A23<Chave, Item>::devolve(Chave chave){

    A23Node<Chave, Item> *aux = raiz;
    
    while(aux != nullptr){

        if(chave < aux->getChaveEsq()) aux = aux->getEsq();

        else if(chave == aux->getChaveEsq()) return aux->getDataEsq();

        else if(!aux->is3() || chave < aux->getChaveDir()) aux = aux->getMeio();

        else if(chave == aux->getChaveDir()) return aux->getDataDir();

        else aux = aux->getDir();
        
    }

    return {};
    
}

template<class Chave, class Item>
void A23<Chave, Item>::caso1(A23Node<Chave, Item> *&root){

    if(root->getMeio()->isBuraco()){

        root->getEsq()->setChaveDir(root->getChaveEsq());
        root->getEsq()->setDataDir(root->getDataEsq());

        root->getEsq()->setDir(root->getMeio()->getMeio());
        delete root->getMeio();
        
        root->getEsq()->set3(true);

        root->setBuraco(true);

        root->setMeio(root->getEsq());

        root->setEsq(nullptr);
        
        
    }

    else if(root->getEsq()->isBuraco()){

        root->getMeio()->setChaveDir(root->getMeio()->getChaveEsq());
        root->getMeio()->setDataDir(root->getMeio()->getDataEsq());

        root->getMeio()->setChaveEsq(root->getChaveEsq());
        root->getMeio()->setDataEsq(root->getDataEsq());

        root->getMeio()->setDir(root->getMeio()->getMeio());
        root->getMeio()->setMeio(root->getMeio()->getEsq()); 
        root->getMeio()->setEsq(root->getEsq()->getMeio());
        
        delete root->getEsq();
        root->setEsq(nullptr);

        root->getMeio()->set3(true);
        
        root->setBuraco(true);
        
    }
    
}

template<class Chave, class Item>
void A23<Chave, Item>::caso2(A23Node<Chave, Item> *&root){

    if(root->getMeio()->isBuraco()){

        root->getMeio()->setBuraco(false);
        root->getMeio()->set3(false);
        root->getEsq()->set3(false);

        root->getMeio()->setChaveEsq(root->getChaveEsq());
        root->getMeio()->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getEsq()->getChaveDir());
        root->setDataEsq(root->getEsq()->getDataDir());

        root->getMeio()->setEsq(root->getEsq()->getDir());
        root->getEsq()->setDir(nullptr);
        
    }

    else if(root->getEsq()->isBuraco()){

        root->getEsq()->setBuraco(false);
        root->getEsq()->set3(false);
        root->getMeio()->set3(false);
        root->set3(false);

        root->getEsq()->setChaveEsq(root->getChaveEsq());
        root->getEsq()->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getMeio()->getChaveEsq());
        root->setDataEsq(root->getMeio()->getDataEsq());

        root->getMeio()->setChaveEsq(root->getMeio()->getChaveDir());
        root->getMeio()->setDataEsq(root->getMeio()->getDataDir());

        root->getEsq()->setEsq(root->getEsq()->getMeio());
        root->getEsq()->setMeio(root->getMeio()->getEsq());
        root->getMeio()->setEsq(root->getMeio()->getMeio());
        root->getMeio()->setMeio(root->getMeio()->getDir());
        root->getMeio()->setDir(nullptr);
        
    }
    
}

template<class Chave, class Item>
void A23<Chave, Item>::caso3(A23Node<Chave, Item> *&root){

    if(root->getDir()->isBuraco()){
        
        root->set3(false);
        root->getMeio()->set3(true);

        root->getMeio()->setChaveDir(root->getChaveDir());
        root->getMeio()->setDataDir(root->getDataEsq());

        root->getMeio()->setDir(root->getDir()->getMeio());

        delete root->getDir();
        root->setDir(nullptr);
        
    }

    else if(root->getEsq()->isBuraco()){

        root->set3(false);
        root->getMeio()->set3(true);

        root->getMeio()->setChaveDir(root->getMeio()->getChaveEsq());
        root->getMeio()->setDataDir(root->getMeio()->getDataEsq());

        root->getMeio()->setChaveEsq(root->getChaveEsq());
        root->getMeio()->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getChaveDir());
        root->setDataEsq(root->getDataDir());

        root->getMeio()->setDir(root->getMeio()->getMeio());
        root->getMeio()->setMeio(root->getMeio()->getEsq());
        root->getMeio()->setEsq(root->getEsq()->getMeio());

        delete root->getEsq();
        
        root->setEsq(root->getMeio());
        root->setMeio(root->getDir());

        root->setDir(nullptr);
        
        
    }

    else if(root->getMeio()->isBuraco()){

        root->set3(false);
        root->getEsq()->set3(true);

        root->getEsq()->setChaveDir(root->getChaveEsq());
        root->getEsq()->setDataDir(root->getDataEsq());

        root->setChaveEsq(root->getChaveDir());
        root->setDataEsq(root->getDataDir());

        root->getEsq()->setDir(root->getMeio()->getMeio());

        delete root->getMeio();

        root->setMeio(root->getDir());

        root->setDir(nullptr);
        
    }
    
}

template<class Chave, class Item>
void A23<Chave, Item>::caso4(A23Node<Chave, Item> *&root){

    if(root->getDir()->isBuraco()){

        root->getMeio()->set3(false);
        root->getDir()->set3(false);
        root->getDir()->setBuraco(false);

        root->getDir()->setChaveEsq(root->getChaveDir());
        root->getDir()->setDataEsq(root->getDataDir());

        root->setChaveDir(root->getMeio()->getChaveDir());
        root->setDataDir(root->getMeio()->getDataDir());

        root->getDir()->setEsq(root->getMeio()->getDir());

        root->getMeio()->setDir(nullptr);
        
    }

    else if(root->getEsq()->isBuraco()){

        root->getMeio()->set3(false);
        root->getEsq()->set3(false);
        root->getEsq()->setBuraco(false);
        
        root->getEsq()->setChaveEsq(root->getChaveEsq());
        root->getEsq()->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getMeio()->getChaveEsq());
        root->setDataEsq(root->getMeio()->getDataEsq());

        root->getMeio()->setChaveEsq(root->getMeio()->getChaveDir());
        root->getMeio()->setDataEsq(root->getMeio()->getDataDir());

        root->getEsq()->setEsq(root->getEsq()->getMeio());
        root->getEsq()->setMeio(root->getMeio()->getEsq());

        root->getMeio()->setEsq(root->getMeio()->getMeio());
        root->getMeio()->setMeio(root->getMeio()->getDir());
        root->getMeio()->setDir(nullptr);
        
    }

    else if(root->getMeio()->isBuraco()){

        root->getEsq()->set3(false);
        root->getMeio()->set3(false);
        root->getMeio()->setBuraco(false);

        root->getMeio()->setChaveEsq(root->getChaveEsq());
        root->getMeio()->setDataEsq(root->getDataEsq());

        root->setChaveEsq(root->getEsq()->getChaveDir());
        root->setDataEsq(root->getEsq()->getDataDir());

        root->getMeio()->setEsq(root->getEsq()->getDir());

        root->getEsq()->setDir(nullptr);
        
    }
    
}

template<class Chave, class Item>
void A23<Chave,Item>::removeMin(A23Node<Chave, Item> *&root){

    if(root == nullptr) return;

    if(root->getEsq() == nullptr){

        if(root->is3()){

            root->setChaveEsq(root->getChaveDir());
            root->setDataEsq(root->getDataDir());

            root->set3(false);

            return;
            
        }

        else if(!root->is3()) root->setBuraco(true);

        return;
        
    }
    
    removeMin(root->getEsq());

    if(!root->is3()){

        if(root->getEsq()->isBuraco()){
        
            if(!root->getMeio()->is3()) caso1(root);
            else if(root->getMeio()->is3()) caso2(root);

        }

        else if(root->getMeio()->isBuraco()){

            if(!root->getEsq()->is3()) caso1(root);
            else if(root->getEsq()->is3()) caso2(root);

        }

    }

    else if(root->is3()){

        if(root->getEsq()->isBuraco()){

            if(!root->getMeio()->is3()) caso3(root);
            else if(root->getMeio()->is3()) caso4(root);
            
        }

        else if(root->getMeio()->isBuraco()){

            if(!root->getEsq()->is3()) caso3(root);
            else if(root->getEsq()->is3()) caso4(root);
            
        }

        else if(root->getDir()->isBuraco()){

            if(!root->getMeio()->is3()) caso3(root);
            else if(root->getMeio()->is3()) caso4(root);
            
        }
        
    }
    
}

template<class Chave, class Item>
A23Node<Chave, Item> A23<Chave, Item>::achaMin(A23Node<Chave, Item> *root){

    while(root->getEsq() != nullptr) root = root->getEsq();

    return *(root);
    
}

template<class Chave, class Item>
void A23<Chave, Item>::removeAux(Chave chave, A23Node<Chave, Item> *&root){

    if(root == nullptr) return;

    if(root->getEsq() == nullptr){

        if(chave == root->getChaveEsq()){

            removeMin(root);
            return;

        }

        else if(root->is3() && chave == root->getChaveDir()){

            root->set3(false);
            return;

        }
        
    }

    else {

        if(chave == root->getChaveEsq()){

            A23Node<Chave, Item> aux = achaMin(root->getMeio());
            root->setChaveEsq(aux.getChaveEsq());
            root->setDataEsq(aux.getDataEsq());

            removeMin(root->getMeio());
            
        }

        else if(chave < root->getChaveEsq()) removeAux(chave, root->getEsq());

        else {

            if(root->is3()){

                if(chave == root->getChaveDir()){

                    A23Node<Chave, Item> aux = achaMin(root->getDir());

                    root->setChaveDir(aux.getChaveEsq());
                    root->setDataDir(aux.getDataDir());

                    removeMin(root->getDir());
                    
                }

                else if(chave < root->getChaveDir()) removeAux(chave, root->getMeio());

                else removeAux(chave, root->getDir());
                
            }

            else removeAux(chave, root->getMeio());
            
        }
        
    }

    if(!root->is3()){

        if(root->getEsq() != nullptr && root->getEsq()->isBuraco()){
        
            if(!root->getMeio()->is3()) caso1(root);
            else if(root->getMeio()->is3()) caso2(root);
            
        }

        else if(root->getMeio() != nullptr && root->getMeio()->isBuraco()){

            if(!root->getEsq()->is3()) caso1(root);
            else if(root->getEsq()->is3()) caso2(root);
            
        }

    }
    
    else if(root->is3()){
        
        if(root->getEsq() != nullptr && root->getEsq()->isBuraco()){
            
            if(!root->getMeio()->is3()) caso3(root);
            else if(root->getMeio()->is3()) caso4(root);
            
        }
        
        else if(root->getMeio() != nullptr && root->getMeio()->isBuraco()){
            
            if(!root->getEsq()->is3()) caso3(root);
            else if(root->getEsq()->is3()) caso4(root);
            
        }
        
        else if(root->getDir() != nullptr && root->getDir()->isBuraco()){
            
            if(!root->getMeio()->is3()) caso3(root);
            else if(root->getMeio()->is3()) caso4(root);
            
        }
        
    }
    
}

template<class Chave, class Item>
void A23<Chave, Item>::remove(Chave chave){

    if(raiz == nullptr) return;
    
    removeAux(chave, raiz);
    
    if(raiz->isBuraco()){

        A23Node<Chave, Item> *aux;
        aux  = raiz;
        raiz = raiz->getMeio();
        
        delete aux;
        
    }
    
}

template<class Chave, class Item>
int A23<Chave, Item>::sizeTree(A23Node<Chave, Item> *root){

    if(root == nullptr) return 0;
    int size = sizeTree(root->getEsq()) + sizeTree(root->getMeio()) + 1;

    if(root->is3()) size += sizeTree(root->getDir()) + 1;

    return size;
    
}

template<class Chave, class Item>
int A23<Chave, Item>::rank(Chave chave){
    
    A23Node<Chave, Item> *aux = raiz;

    int resp = 0;

    while(1){
    
        if(chave < aux->getChaveEsq()) aux = aux->getEsq();

        else if(chave == aux->getChaveEsq()){

            resp += sizeTree(aux->getEsq());
            break;
        
        }

        else if(!aux->is3() || chave < aux->getChaveDir()){

            resp += sizeTree(aux->getEsq()) + 1;
            aux = aux->getMeio();
        
        }

        else if(chave == aux->getChaveDir()){
            
            resp += sizeTree(aux->getEsq()) + sizeTree(aux->getMeio()) + 1;
            break;
            
        }

        else {

            resp += sizeTree(aux->getEsq()) + sizeTree(aux->getMeio()) + 2;
            aux = aux->getDir();
        
        }

    }

    return resp;
    
}

template<class Chave, class Item>
Chave A23<Chave, Item>::seleciona(int k){

    A23Node<Chave, Item> *aux = raiz;
    
    while(aux != nullptr){

        int tamE = sizeTree(aux->getEsq());

        if(k < tamE) aux = aux->getEsq();

        else if(k > tamE){

            if(aux->is3()){
                
                int tamM = sizeTree(aux->getMeio());

                if(k < tamE + tamM + 1){

                    aux = aux->getMeio();
                    k -= (tamE + 1);
                
                }

                else if(k > tamE + tamM + 1){

                    aux = aux->getDir();
                    k -= (tamE + tamM + 2);
                    
                }

                else return aux->getChaveDir();

            }

            else {

                aux = aux->getMeio();
                k -= (tamE + 1);

            }

        }

        else return aux->getChaveEsq();
        
    }

    return {};
    
}

#endif
