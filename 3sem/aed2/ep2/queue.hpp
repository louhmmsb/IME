#ifndef QUEUE_H
#define QUEUE_H

template<class T> class q_iter;

template<class T>
class queue{

  private:
    class node{
        friend class queue;
        friend class q_iter<T>;
        T data;
        node *next;
        node(T a);
        node();
    };
    node *head;
    node *tail;
    int Size;

  public:
    friend class q_iter<T>;
    typedef q_iter<T> iterator;
    queue();
    ~queue();
    bool empty();
    int size();
    T front();
    T back();
    void push_back(T a);
    void pop_front();
    void show();
    iterator begin();
    iterator end();
};

template<class T>
queue<T>::node::node(T a){
    data = a;
    next = nullptr;
}

template<class T>
queue<T>::node::node(){
    data = {};
    next = nullptr;
}

template<class T>
queue<T>::queue(){
    tail = new queue::node();
    head  = tail;
    Size = 0;
}

template<class T>
queue<T>::~queue(){
    queue<T>::node *aux = head, *kill;
    while(aux != tail){
        kill = aux;
        aux = aux->next;
        delete kill;
        kill = nullptr;
    }
    delete aux;
}

template<class T>
bool queue<T>::empty(){
    return size == 0;
}

template<class T>
int queue<T>::size(){
    return Size;
}

template<class T>
T queue<T>::front(){
    return head->data;
}

template<class T>
T queue<T>::back(){
    return tail->data;
}

template<class T>
void queue<T>::push_back(T a){
    if(Size == 0){
        head = new queue<T>::node(a);
        head->next = tail;
        Size++;
        return;
    }
    tail->next = new queue<T>::node();
    tail->data = a;
    tail = tail->next;
    Size++;
}

template<class T>
void queue<T>::pop_front(){
    queue<T>::node *kill = head;
    if(Size == 1){
        delete head;
        head = nullptr;
        head = tail;
        Size--;
        return;
    }
    head = head->next;
    delete kill;
    Size--;
}

template<class T>
void queue<T>::show(){
    for(queue<T>::iterator it = begin(); it != end(); ++it) std::cout<<*it<<" ";
}

template<class T>
q_iter<T> queue<T>::begin(){
    q_iter<T> it(head);
    return it;
}

template<class T>
q_iter<T> queue<T>::end(){
    q_iter<T> it(tail);
    return it;
}

template<class T>
class q_iter{
  private:
    class queue<T>::node *p = nullptr;

  public:
    q_iter operator++(){
        p = p->next;
    }
    T operator*(){
        return p->data;
    }
    bool operator!=(q_iter a){
        return (p != a.p);
    }
    q_iter(class queue<T>::node *a = nullptr){
        p = a;
    }
};

#endif
