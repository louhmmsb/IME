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
    NFA(string r);
    int matchAux(int v, char c);
    bool match(string txt);
    void dfs(int ini);
    void DFS(vector<int> v);
};

