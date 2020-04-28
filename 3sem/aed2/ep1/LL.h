#include "st.h"
#ifndef LL_H
#define LL_H

using namespace std;

//Nodo das listas ligadas
template<class Chave, class Item>
class LLNode{

  private:
    Chave chave;
    Item data;
    LLNode *next;
    LLNode *prev;

  public:
    void setChave(Chave nova);
    void setData(Item nova);
    void setNext(LLNode *prox);
    void setPrev(LLNode *ant);
    Chave getChave();
    Item getData();
    LLNode *getNext();
    LLNode *getPrev();
    LLNode();
    
    void operator=(LLNode<Chave, Item> &a);
    
};

//bloco de funções dos nodos das listas ligadas
template<class Chave, class Item>
void LLNode<Chave, Item>::setChave(Chave nova){

    chave = nova;

}

template<class Chave, class Item>
void LLNode<Chave, Item>::setData(Item novo){

    data = novo;
    
}

template<class Chave, class Item>
void LLNode<Chave, Item>::setNext(LLNode<Chave, Item> *prox){

    next = prox;
    
}

template<class Chave, class Item>
void LLNode<Chave, Item>::setPrev(LLNode<Chave, Item> *ant){

    prev = ant;
    
}

template<class Chave, class Item>
Chave LLNode<Chave, Item>::getChave(){

    return chave;
    
}

template<class Chave, class Item>
Item LLNode<Chave, Item>::getData(){

    return data;
    
}

template<class Chave, class Item>
LLNode<Chave, Item>* LLNode<Chave, Item>::getNext(){

    return next;
    
}

template<class Chave, class Item>
LLNode<Chave, Item>* LLNode<Chave ,Item>::getPrev(){

    return prev;
    
}

template<class Chave, class Item>
void LLNode<Chave, Item>::operator=(LLNode<Chave, Item> &a){

    chave = a.chave;
    data = a.data;
    
}

template<class Chave, class Item>
LLNode<Chave, Item>::LLNode(){

    next = nullptr;
    prev = nullptr;
    
}

//classe que implementa a st usando lista ligada desordenada
template<class Chave, class Item>
class LD : public st<Chave, Item>{

  private:
    LLNode<Chave, Item> *head;
    LLNode<Chave, Item> *tail;
    int size;

  public:
    void insere(Chave chave, Item valor);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    LD();
    ~LD();
    
};

template<class Chave, class Item>
LD<Chave, Item>::LD(){

    head = new LLNode<Chave, Item>();
    tail = new LLNode<Chave, Item>();
    head->setNext(tail);
    tail->setPrev(head);
    
}

template<class Chave, class Item>
LD<Chave, Item>::~LD(){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();

    while(true){

        if(forward == tail){

            delete forward;
            delete backward;
            
            break;
            
        }

        delete forward->getPrev();
        delete backward->getNext();

        if(forward->getNext() == backward){

            delete forward;
            delete backward;

            break;
            
        }

        else if(forward == backward){

            delete forward;
            break;
            
        }

        forward = forward->getNext();
        backward = backward->getPrev();
        
    }
    
}

template<class Chave, class Item>
void LD<Chave, Item>::insere(Chave nova, Item novo){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    bool achou = false;

    while(true){

        if(forward == tail || backward == head) break;

        if(forward->getChave() == nova){
            
            forward->setData(att(forward->getData(), novo));
            achou = true;
            break;
            
        }
        
        else if(backward->getChave() == nova){

            backward->setData(att(backward->getData(), novo));
            achou = true;
            break;
            
        }  

        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
        
    }
    
    if(achou == false){

        LLNode<Chave, Item> *ins = new LLNode<Chave, Item>();
        ins->setChave(nova);
        ins->setData(novo);
        ins->setPrev(tail->getPrev());
        
        tail->getPrev()->setNext(ins);
        tail->setPrev(ins);

        ins->setNext(tail);
        
    }
    
}

template<class Chave, class Item>
Item LD<Chave, Item>::devolve(Chave chave){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(forward->getChave() == chave) return forward->getData();

        else if(backward->getChave() == chave) return backward->getData();
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
  
    }

    return {};
    
}

template<class Chave, class Item>
void LD<Chave, Item>::remove(Chave chave){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(forward->getChave() == chave){

            forward->getPrev()->setNext(forward->getNext());
            forward->getNext()->setPrev(forward->getPrev());
            delete forward;
            return;
            
        }

        else if(backward->getChave() == chave){

            backward->getPrev()->setNext(backward->getNext());
            backward->getNext()->setPrev(backward->getPrev());
            delete backward;
            return;
            
        }
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
    
    }

}

template<class Chave, class Item>
int LD<Chave, Item>::rank(Chave chave){

    int x = 0;
    
    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(forward == backward && forward->getChave() < chave) x++;

        else{

            if(forward->getChave() < chave) x++;
            
            if(backward->getChave() < chave) x++;

        }
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
  
    }

    return x;
    
}

template<class Chave, class Item>
Chave LD<Chave, Item>::seleciona(int k){
    
    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(rank(forward->getChave()) == k) return forward->getChave();

        else if(rank(backward->getChave()) == k) return backward->getChave();
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
  
    }

    return {};
    
}

//classe que implementa a st usando lista ligad ordenada
template<class Chave, class Item>
class LO : public st<Chave, Item>{

  private:
    LLNode<Chave, Item> *head;
    LLNode<Chave, Item> *tail;
    int size;

  public:
    void insere(Chave chave, Item valor);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    LO();
    ~LO();
    
};

template<class Chave, class Item>
LO<Chave, Item>::LO(){

    head = new LLNode<Chave, Item>();
    tail = new LLNode<Chave, Item>();
    head->setNext(tail);
    tail->setPrev(head);
    size = 0;
    
}

template<class Chave, class Item>
LO<Chave, Item>::~LO(){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();

    while(true){

        if(forward == tail){

            delete forward;
            delete backward;
            
            break;
            
        }

        delete forward->getPrev();
        delete backward->getNext();

        if(forward->getNext() == backward){

            delete forward;
            delete backward;

            break;
            
        }

        else if(forward == backward){

            delete forward;
            break;
            
        }

        forward = forward->getNext();
        backward = backward->getPrev();
        
    }
    
}

template<class Chave, class Item>
void LO<Chave, Item>::insere(Chave nova, Item novo){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev(), *procura;
    bool achou = false;

    while(true){

        if(forward == tail || backward == head){

            procura = tail;
            break;

        }

        if(forward->getChave() == nova){
            
            forward->setData(att(forward->getData(), novo));
            achou = true;
            break;
            
        }
        
        else if(backward->getChave() == nova){

            backward->setData(att(backward->getData(), novo));
            achou = true;
            break;
            
        }

        else if(forward->getChave() > nova){

            procura = forward;
            break;
            
        }

        else if(backward->getChave() < nova){

            procura = backward->getNext();            
            break;
            
        }

        //if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
        
    }
    
    if(achou == false){

        LLNode<Chave, Item> *ins = new LLNode<Chave, Item>();
        ins->setChave(nova);
        ins->setData(novo);
        ins->setPrev(procura->getPrev());
        
        procura->getPrev()->setNext(ins);
        procura->setPrev(ins);

        ins->setNext(procura);

        size++;
        
    }
    
}

template<class Chave, class Item>
Item LO<Chave, Item>::devolve(Chave chave){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(forward->getChave() == chave) return forward->getData();

        else if(backward->getChave() == chave) return backward->getData();
        
        if(forward->getChave() > chave || backward->getChave() < chave || forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
  
    }

    return {};
    
}

template<class Chave, class Item>
void LO<Chave, Item>::remove(Chave chave){

    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;

        if(forward->getChave() == chave){

            forward->getPrev()->setNext(forward->getNext());
            forward->getNext()->setPrev(forward->getPrev());
            size--;
            delete forward;
            break;
            
        }

        else if(backward->getChave() == chave){

            backward->getPrev()->setNext(backward->getNext());
            backward->getNext()->setPrev(backward->getPrev());
            size--;
            delete backward;
            break;
            
        }
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
    
    }

}

template<class Chave, class Item>
int LO<Chave, Item>::rank(Chave chave){

    int x = 0, cont = 0;
    bool peladir = false;
    
    LLNode<Chave, Item> *forward = head->getNext(), *backward = tail->getPrev();
    
    while(true){

        if(forward == tail || backward == head) break;
        
        if(forward == backward && forward->getChave() < chave) x++;

        else{

            if(forward->getChave() < chave) x++;
            
            if(backward->getChave() >= chave) cont++;

        }

        if(forward->getChave() > chave) break;

        else if(backward->getChave() < chave){

            peladir = true;
            break;
            
        }
        
        if(forward->getNext() == backward || forward == backward) break;

        forward = forward->getNext();
        backward = backward->getPrev();
  
    }

    if(peladir) return size - cont;

    return x;
    
}

template<class Chave, class Item>
Chave LO<Chave, Item>::seleciona(int k){
    
    LLNode<Chave, Item> *forward = head->getNext();

    if(k>=size || k<0) return {};
    
    while(k){
        
        forward = forward->getNext();
        k--;

    }

    return forward->getChave();
    
}

#endif
