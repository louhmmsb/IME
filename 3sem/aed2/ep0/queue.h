#ifndef QUEUE_H
#define QUEUE_H

template <class Item>
class Node{
  public:
    Item *data;
    Node<Item> *next;
    ~Node();
};

template <class Item>
Node<Item>::~Node(){
    if(data != nullptr)
    delete data;
}



template <class Item>
class Queue{
  private:
    int n;
  public:
    Node<Item> *head;
    Node<Item> *end;
    Queue();
    ~Queue();
    void insere(Item *item);
    Item *show();
    Item *top();
    Item *remove();
    Item *remove(Node<Item> *node);
    int nElem();
};

template <class Item>
Queue<Item>::Queue(){
    n = 0;
    head = new Node<Item>;
    head->next = nullptr;
    end = head;
}

template <class Item>
Queue<Item>::~Queue(){
    Node<Item> *percorre, *kill;
    percorre = head;
    while(percorre != nullptr){
         kill = percorre;
         percorre = percorre->next;
         delete kill;
    }
}

template <class Item>
void Queue<Item>::insere(Item *item){
    Node<Item> *novo = new Node<Item>;
    novo->data = item;
    novo->next = nullptr;
    if(n == 0){
        head->next = novo;
        end = novo;
    }
    else {
        end->next = novo;
        end = end->next;
    }
    n++;
}

template <class Item>
Item* Queue<Item>::top(){
    if(head->next != nullptr) return head->next->data;
    return nullptr;
}

template <class Item>
Item* Queue<Item>::remove(){
    Node<Item> *percorre = head->next;
    Aviao *devolve;
    if(n==0) return nullptr;
    n--;
    head->next = percorre->next;
    devolve = percorre->data;
    percorre->data = nullptr;
    delete percorre;
    return devolve;
}

template <class Item>
Item* Queue<Item>::remove(Node<Item> *node){
    Node<Item> *percorre = head->next, *atras = head;
    Aviao *devolve;
    while(percorre != node){
        atras = atras->next;
        percorre = atras->next;
    }
    n--;
    atras->next = percorre->next;
    devolve = percorre->data;
    percorre->data = nullptr;
    delete percorre;
    return devolve;
}

template <class Item>
int Queue<Item>::nElem(){
    return n;
}




#endif
