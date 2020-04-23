#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

unordered_set<char> adj[30];
bool visitado[30];

void dfs(int ini){

    visitado[ini] = true;
    cout<<(char)(ini + 'a');
    for(int a : adj[ini]){

        if(visitado[a - 'a'] == true) continue;
        dfs(a - 'a');
        
    }
    
}

void solve(){

    string s;
    cin>>s;

    for(int i=0; i<30; i++) adj[i].clear();

    memset(visitado, 0, sizeof(visitado));
    
    for(int i=0; i<s.size(); i++){

        if(i != 0) adj[s[i]-'a'].insert(s[i-1]);
           
        if(i != s.size() - 1) adj[s[i]-'a'].insert(s[i+1]);
        
    }

    int ini = 0, com1 = 0;
    
    for(int i=0; i<26; i++){

        if(adj[i].size() > 2){

            cout<<"NO\n";
            return;
            
        }

        else if(adj[i].size() == 1){

            com1++;
            ini = i;
            
        }
        
    }

    if(com1 == 2 || s.size() == 1){

        cout<<"YES\n";
        dfs(ini);
        for(int i=0; i<26; i++){

            if(!visitado[i]) cout<<(char)(i+'a');
            
        }
        cout<<'\n';

    }

    else {

        cout<<"NO\n";
        return;
        
    }
    
}

int main(){
    string s, resp = "";
    int n;
    cin>>n;

    while(n--){

        solve();
        
    }

    return 0;
    
}
