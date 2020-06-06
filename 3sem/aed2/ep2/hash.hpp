#ifndef HASH_H
#define HASH_H

#include "queue.hpp"
#include "util.hpp"
#include <vector>


//aqui implementarei a classe hash table

class hashTable{
  private:
    const int MAX = 200000;
    //vector de queues (queue definida em queue.hpp)
    std::vector<queue<Pair<wstring, int> > > v;
    int p;
    int Size;

  public:
    hashTable(int _p = 97);
    int hash(wstring a);
    int insert(Pair<wstring, int> a);
    int find(wstring a);
    int size();
    int getNode(wstring a);
};

hashTable::hashTable(int _p){
    p = _p;
    Size = 0;
    v.resize(MAX);
}

int hashTable::hash(wstring a){
    int res = 0;
    for(auto x : a){
        res *= p;
        res += (int)x;
        res = res%MAX;
    }
    return res;
}

int hashTable::insert(Pair<wstring, int> a){
    int index = hash(a.first);
    for(auto it = v[index].begin(); it  != v[index].end(); ++it){
        if((*it).first == a.first) return -1;
    }
    v[index].push_back(a);
    Size++;
    return 0;
}

int hashTable::find(wstring a){
    int index = hash(a);
    for(queue<Pair<wstring, int>>::iterator it = v[index].begin(); it != v[index].end(); ++it){
        if((*it).first == a) return 1;
    }
    
    return 0;
}

int hashTable::getNode(wstring a){
    int index = hash(a);
    for(queue<Pair<wstring, int>>::iterator it = v[index].begin(); it != v[index].end(); ++it){
        if((*it).first == a) return (*it).second;
    }
    return -1;
}

int hashTable::size(){
    return Size;
}

#endif
