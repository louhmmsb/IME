#include "nfa.hpp"

NFA::NFA(string r){
    stack<int> ops, abre;
    //re = "(.*" + r + ".*)";
    re = '(' + r + ')';
    M = (int)re.size();
    for(int i=0; i<M; i++){
        int prev = i;
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
            prev = ops.top();
            ops.pop();
        }
        if(i < M-1 && (re[i+1] == '*' || re[i+1] == '+')){
            if(re[i+1] != '+')adj[prev].push_back(i+1);
            adj[i+1].push_back(prev);
        }
        if(re[i] == '(' || re[i] == '*' || re[i] == ')' | re[i] == '+'){
            adj[i].push_back(i+1);
        }
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
    
    for(int i=0; i<=M; i++){
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
        for(int j=0; j<=M; j++){
            if(vis[j]) pc.push_back(j);
        }
    }
    for(auto a : pc) if(a == M) return true;
    
    return false;
}
