#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

const int MAX = 10000;

class NFA{
  private:
    vector<int> adj[MAX];
    bool vis[MAX];
    int M;
    string re;

  public:
    NFA(string r);
    bool match(string txt);
    void dfs(int ini);
    void DFS(vector<int> v);
};

NFA::NFA(string r){
    stack<int> ops, abre;
    re = "(.*" + r + ".*)";
    cout<<re<<endl;
    M = (int)re.size();
    cout<<M<<endl;
    for(int i=0; i<M; i++){
        if(re[i] == '(' || re[i] == '|'){
            ops.push(i);
            if(re[i] == '(') abre.push(i);
        }
        else if(re[i] == ')'){
            
            while(re[ops.top()] == '|'){
                int ou = ops.top();
                ops.pop();
                adj[ou].push_back(i);
                adj[abre.top()].push_back(ou+1);
            }
            abre.pop();
            ops.pop();
        }
        if(i < M-1 && re[i+1] == '*'){
            adj[ops.top()].push_back(i);
            adj[i+1].push_back(ops.top());
        }
        if(re[i] == '(' || re[i] == '*' || re[i] == ')'){
            adj[i].push_back(i+1);
        }
    }
    for(int i=0; i<M; i++){
        cout<<re[i]<<": ";
        for(auto a : adj[i]) cout<<a<<" "; cout<<endl;
    }
}

void NFA::dfs(int ini){
    vis[ini] = true;
    for(auto a : adj[ini]){
        if(vis[a]) continue;
        dfs(a);
    }
}

void NFA::DFS(vector<int> v){
    memset(vis, 0, sizeof(vis));
    for(auto a : v){
        dfs(a);
    }
}

bool NFA::match(string txt){
    int size_text = (int) txt.size();
    vector<int> match, pc;

    match.push_back(0);
    DFS(match);
    
    for(int i = 0; i<MAX; i++){
        if(vis[i]) pc.push_back(i);
    }

    for(int i=0; i < size_text; i++){
        match.clear();
        for(auto v : pc){
            if(v == M) continue;
            if(txt[i] == re[v] || re[v] == '.') match.push_back(v+1);
        }
        DFS(match);
        pc.clear();
        for(int i=0; i<MAX; i++){
            if(vis[i]) pc.push_back(i);
        }
    }
    for(auto a : pc) if(a == M) return true;
    
    return false;
}


int main(int argc, char** argv){
    string regex(argv[1]), txt(argv[2]);
    NFA sas(regex);

    cout<<sas.match(txt)<<endl;
    return 0;
}
