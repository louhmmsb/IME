#include "queue.hpp"

//aqui implementarei a classe hash table

template<class key, class value>
class hashTable{
  private:
    vector<queue<pair<key, value>>>;

  public:
    hashTable();
    ~hashTable();
    void insert(pair<key, value> a);
    void remove(key a);
    int find(key a);
};
