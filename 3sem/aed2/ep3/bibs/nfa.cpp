#include "nfa.hpp"

NFA::NFA(string r){
    stack<int> ops, abre;    
    re = '(' + r + ')';
    M = (int)re.size();
    for(int i=0; i<M; i++){
        int prev = i;
        if(re[i] == '['){
            int j = i;
            bool bob = false;
            if(j < M-1 && re[j+1] == '^') bob = ++j, true;
            j++;
            for(; j < M; j++){
                if(re[j] == '-'){
                    if(j > 0 && re[j-1] != '[' && j < M-1 && re[j+1] != ']'){
                        inter[j-1].first = 1;
                        inter[j-1].second = j+1;
                        j++;
                        continue;
                    }
                }
                if(re[j] == ']') break;
                inter[j].first = 0;
                inter[j].second = j;
            }
            inter[i].first = (bob)? 3 : 2;
            inter[i].second = j;
            inter[j].second = i;
            i = j;
            adj[i].push_back(i+1);
        }
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

int NFA::matchAux(int v, char c){
    int resp = -1;
    int i = v;

    switch(inter[v].first){
        case 2:
            while(re[i] != ']'){
                if(inter[i].first == 1){
                    if(c >= re[i] && c <= re[inter[i].second]) break;                
                    i = inter[i].second;
                }
                else if(re[i] == c) break;
                i++;
            }
            if(re[i] != ']') resp = inter[v].second;
            break;
        case 3:
            i+=2;
            while(re[i] != ']'){
                if(inter[i].first == 1){
                    if(c >= re[i] && c <= re[inter[i].second]) break;                
                    i = inter[i].second;
                }
                else if(re[i] == c) break;
                i++;
            }
            if(re[i] == ']') resp = inter[v].second;
            break;
        case 0:
        default:
            if(re[i] == '.' || re[i] == c) resp = v+1;
            break;
    }
    return resp;
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
            int sas = matchAux(v, txt[i]);
            if(sas != -1) match.push_back(sas);
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
