#include "queue.hpp"
#include <vector>

//aqui implementarei a classe hash table

const int MAX = 10000;

class hashTable{
  private:
    //vector de queues (queue definida em queue.hpp)
    vector<queue<pair<wstring, int>>> v(MAX);
    int p;

  public:
    hashTable(int _p = 7);
    int hash(wstring a);
    int insert(pair<wstring, int> a);
    int find(wstring a);
    int getNode(wstring a);
};

hashTable::hashTable(int _p){
    p = _p;
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

int hashTable::insert(pair<wstring, int> a){
    int index = hash(a.first);
    for(queue<pair<wstring, int>::iterator it = v[index].begin(); it  != v[index].end(); ++it){
        if((*it).first == a.first) return -1;
    }
    v[index].push_back(a);
    return 0;
}

int hashTable::find(wstring a){
    int index = hash(a);
    for(queue<pair<wstring, int>>::iterator it = v[index].begin(); it != v[index].end(); ++it){
        if((*it).first == a) return 1;
    }
    
    return 0;
}

int hashTable::getNode(wstring a){
    int index = hash(a);
    for(queue<pair<wstring, int>>::iterator it = v[index].begin(); it != v[index].end(); ++it){
        if((*it).first == a) return (*it).second;
    }
    return -1;
}
