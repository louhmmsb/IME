#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

using namespace std;

const int MAX = 10000;

class NFA{
  private:
    pair<int, int> inter[MAX];
    vector<int> adj[MAX];
    bool vis[MAX];
    int M;
    string re;

  public:
    //Construtor da classe, constrói o grafo da regex.
    NFA(string r);
    //Função para fazer o match da string com a regex
    bool match(string txt);
    //Funções auxiliares para fazer o match da string com a regex
    void dfs(int ini);
    void DFS(vector<int> v);
    int matchAux(int v, char c);
};

