#include "st.h"
#include "LL.h"
#ifndef HASH_H
#define HASH_H
#define MAXHASH 10000

using namespace std;

//Implementação usando hash
template<class Chave, class Item>
class HASH : public st<Chave, Item>{

  private:
    int size;
    LLNode<Chave, Item> **array;
    int usados;
    int hash(Chave chave);

  public:
    void insere(Chave chave, Item valor);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    HASH(int ini = MAXHASH);
    ~HASH();    
    
};

template<class Chave, class Item>
HASH<Chave, Item>::HASH(int ini){

    array = new LLNode<Chave, Item>*[ini]();

    for(int i = 0; i<ini; i++){

        array[i] = nullptr;
        
    }
        
    size = ini;
    
}

template<class Chave, class Item>
HASH<Chave, Item>::~HASH(){

    delete[] array;
    
}

template<class Chave, class Item>
int HASH<Chave, Item>::hash(Chave chave){

    int resp = 0;
    
    for(auto a : chave){

        resp += resp*10 + a;
        resp = resp%size;
        
    }
    

    return resp;
    
}

template<class Chave, class Item>
void HASH<Chave, Item>::insere(Chave nova, Item novo){

    int index = hash(nova);

    if(array[index] == nullptr){

        array[index] = new LLNode<Chave, Item>();
        array[index]->setChave(nova);
        array[index]->setData(novo);
        array[index]->setNext(nullptr);
        
    }

    else {

        LLNode<Chave, Item> *aux = array[index];

        while(aux->getNext() != nullptr){

            if(aux->getChave() == nova){

                aux->setData(att(aux->getData(), novo));
                return;

            }

            aux = aux->getNext();
            
        }

        if(aux->getChave() == nova){

            aux->setData(att(aux->getData(), novo));
            return;

        }

        else {

            LLNode<Chave, Item> *novoNodo = new LLNode<Chave, Item>();

            novoNodo->setChave(nova);
            novoNodo->setData(novo);
            novoNodo->setNext(nullptr);
            
            aux->setNext(novoNodo);
            
        }

    }
    
}

template<class Chave, class Item>
Item HASH<Chave, Item>::devolve(Chave chave){

    int index = hash(chave);
    LLNode<Chave, Item> *aux = array[index];

    while(aux != nullptr){

        if(aux->getChave() == chave) return aux->getData();

        aux = aux->getNext();
        
    }

    return {};
    
}

template<class Chave, class Item>
void HASH<Chave, Item>::remove(Chave chave){

    int index = hash(chave);

    LLNode<Chave, Item> *aux = array[index];
    if(aux == nullptr) return;

    if(aux->getChave() == chave){

        array[index] = array[index]->getNext();
        delete aux;
        return;
        
    }

    while(aux->getNext() != nullptr){

        if(aux->getNext()->getChave() == chave){

            LLNode<Chave, Item> *kill = aux->getNext();

            aux->setNext(aux->getNext()->getNext());
            delete kill;
            return;
            
        }
        
    }

    if(aux->getChave() == chave) delete aux;
    
}

template<class Chave, class Item>
int HASH<Chave, Item>::rank(Chave chave){

    int resp = 0;

    for(int i = 0; i<MAXHASH; i++){

        LLNode<Chave, Item> *a = array[i];

        while(a != nullptr){

            if(a->getChave() < chave) resp++;

            a = a->getNext();
            
        }
        
    }

    return resp;
    
}

template<class Chave, class Item>
Chave HASH<Chave, Item>::seleciona(int k){

    for(int i = 0; i<MAXHASH; i++){

        LLNode<Chave, Item> *a = array[i];

        while(a != nullptr){

            if(rank(a->getChave()) == k) return a->getChave();

            a = a->getNext();
            
        }
        
    }

    return {};
    
}

#endif
