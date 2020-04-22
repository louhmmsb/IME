#include "st.h"
#ifndef V_H
#define V_H

using namespace std;

//Nodo dos vetores
template<class Chave, class Item>
class VNode{

  private:
    Chave chave;
    Item data;
    
  public:
    void setChave(Chave nova);
    void setData(Item novo);
    Chave getChave();
    Item getData();
    void operator=(VNode<Chave, Item> &a);
    
};

//bloco de funções dos nodos dos vetores
template<class Chave, class Item>
void VNode<Chave, Item>::setChave(Chave nova){

    chave = nova;
    
}

template<class Chave, class Item>
void VNode<Chave, Item>::setData(Item novo){

    data = novo;
    
}

template<class Chave, class Item>
Chave VNode<Chave, Item>::getChave(){

    return chave;
    
}

template<class Chave, class Item>
Item VNode<Chave, Item>::getData(){

    return data;
    
}

template<class Chave, class Item>
void VNode<Chave, Item>::operator=(VNode<Chave, Item> &a){

    chave = a.chave;
    data = a.data;
    
}



//classe que implementa a st usando vetor desordenado
template<class Chave, class Item>
class VD : public st<Chave, Item>{

  private:
    VNode<Chave, Item> *array;
    int size;
    int nElem;

  public:
    void insere(Chave chave, Item valor);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    VD(int ini = 16);
    ~VD();
    
};

template<class Chave, class Item>
VD<Chave, Item>::VD(int ini){
    
    array = new VNode<Chave, Item>[ini]();
    size = ini;

    nElem = 0;
    
}

template<class Chave, class Item>
VD<Chave, Item>::~VD(){

    delete[] array;

}

template<class Chave, class Item>
void VD<Chave, Item>::insere(Chave nova, Item novo){

    if(nElem == size){

        VNode<Chave, Item> *aux;
        aux = new VNode<Chave, Item>[size*2]();

        for(int i=0; i<nElem; i++){

            aux[i] = array[i];
            
        }

        delete[] array;

        array = aux;
        size *= 2;
            
    }

    bool achou = false;
    
    for(int i=0; i<nElem; i++){

        if(array[i].getChave() == nova){

            achou = true;
            array[i].setData(att(array[i].getData(), novo));
            break;
            
        }
        
    }

    if(achou == false){

        array[nElem].setChave(nova);
        array[nElem].setData(novo);
        nElem++;
        
    }
    
}

template<class Chave, class Item>
Item VD<Chave, Item>::devolve(Chave chave){
    
    for(int i=0; i<nElem; i++){
        
        if(array[i].getChave() == chave) return array[i].getData();
        
    }

    return {};
    
}

template<class Chave, class Item>
void VD<Chave, Item>::remove(Chave chave){

    for(int i=0; i<nElem; i++){

        if(array[i].getChave() == chave){

            array[i].setChave(array[nElem-1].getChave());
            array[i].setData(array[nElem-1].getData());
            nElem--;
            
        }
        
    }
    
}

template<class Chave, class Item>
int VD<Chave, Item>::rank(Chave chave){

    int x = 0;
    
    for(int i=0; i<nElem; i++){

        if(array[i].getChave() < chave) x++;
        
    }

    return x;
    
}

template<class Chave, class Item>
Chave VD<Chave, Item>::seleciona(int k){

    int aux;
    
    for(int i=0; i<nElem; i++){

        aux = rank(array[i].getChave());

        if(aux == k) return array[i].getChave();
        
    }

    return {};
    
}



//classe que implementa a st usando vetor ordenado
template<class Chave, class Item>
class VO: public st<Chave, Item>{

  private:
    VNode<Chave, Item> *array;
    int size;
    int nElem;

  public:
    int search(Chave chave);
    void insere(Chave chave, Item valor);
    Item devolve(Chave chave);
    void remove(Chave chave);
    int rank(Chave chave);
    Chave seleciona(int k);
    VO(int ini = 16);
    ~VO();
    //void show(); função feita para debug
    
};

template<class Chave, class Item>
int VO<Chave, Item>::search(Chave chave){

    int top = nElem - 1, bot = 0, atual = 0;

    if (nElem == 0) return 0;

    while(top > bot){

        atual = (top+bot)/2;
        
        if(array[atual].getChave() == chave) return atual;

        else if(array[atual].getChave() < chave) bot = atual + 1;

        else if(array[atual].getChave() > chave) top = atual - 1;
        
    }

    if(array[atual].getChave() < chave) return atual + 1;
    else return atual;
    
}

template<class Chave, class Item>
VO<Chave, Item>::VO(int ini){
    
    array = new VNode<Chave, Item>[ini]();
    size = ini;

    nElem = 0;
    
}

template<class Chave, class Item>
VO<Chave, Item>::~VO(){

    delete[] array;
    
}

template<class Chave, class Item>
void VO<Chave, Item>::insere(Chave nova, Item novo){

    if(nElem == size){

        VNode<Chave, Item> *aux;
        aux = new VNode<Chave, Item>[size*2]();

        for(int i=0; i<nElem; i++){

            aux[i] = array[i];
            
        }

        delete[] array;

        array = aux;
        size *= 2;
            
    }

    int index = search(nova);
    //cout<<index<<endl;
    
    if(array[index].getChave() == nova) array[index].setData(att(array[index].getData(), novo));

    else{
        
        for(int i = nElem; i > index; i--){

            array[i] = array[i - 1];
            
        }

        array[index].setChave(nova);
        array[index].setData(novo);
        
    }

    nElem++;
    
}

template<class Chave, class Item>
Item VO<Chave, Item>::devolve(Chave chave){
    
    int index = search(chave);

    if(array[index].getChave() == chave) return array[index].getData();

    else return {};
    
}

template<class Chave, class Item>
void VO<Chave, Item>::remove(Chave chave){

    int index = search(chave);

    for(int i = index; i < nElem - 1; i++){

        array[i] = array[i+1];
        
    }

    nElem--;
    
}

template<class Chave, class Item>
int VO<Chave, Item>::rank(Chave chave){

    int index = search(chave);

    return index;
    
}

template<class Chave, class Item>
Chave VO<Chave, Item>::seleciona(int k){
    
    if(k >=0 && k<nElem) return array[k].getChave();

    return {};
    
}

/*função feita para debug
template<class Chave, class Item>
void VO<Chave, Item>::show(){

    for(int i=0; i<nElem; i++) cout<<array[i].getChave()<<" ";
    cout<<endl;
    
}
*/

#endif
