#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int cores[212345];
int t[212345];
int c[212345];
vector<int> adj[212345];
bool visitado[212345];

bool func(int a, int b){
    return cores[a]<cores[b];
}

int main(){
    int n, m, k, count = 0;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        cin>>cores[i];
        c[i] = -1;
    }
    
    for(int i=1; i<=m; i++){
        int l, r;
        cin>>l>>r;
        
        if(c[l] == -1 && c[r] == -1){
            c[l] = l;
            c[r] = l;
            t[l] = 1;
            adj[l].push_back(r);
        }
        else if(c[l] == c[r]) continue;
        else if(c[l] != -1 && c[r] != -1){
            if(t[c[l]]>t[c[r]]){
                adj[c[l]].push_back(c[r]);
                t[c[l]]+=t[c[r]]+1;
                int aux = t[c[r]];
                int aux2 = c[r];
                for(int j=0; j<aux; j++){
                    //for(auto a : adj[c[l]]) cout<<a<<" ";cout<<endl;
                    adj[c[l]].push_back(adj[c[r]][j]);
                    //for(auto a : adj[c[r]]) cout<<a<<" ";cout<<endl;
                    //cout<<"UE: "<<adj[c[r]][j]<<endl;
                    c[adj[c[r]][j]] = c[l];
                }
                c[aux2] = c[l];
            }
            else if(t[c[r]]>t[c[l]]){
                adj[c[r]].push_back(c[l]);
                t[c[r]]+=t[c[l]]+1;
                int aux = t[c[l]];
                int aux2 = c[l];
                for(int j=0; j<aux; j++){
                    adj[c[r]].push_back(adj[c[l]][j]);
                    c[adj[c[l]][j]] = c[r];
                }
                c[aux2] = c[r];
            }
        }
        else if(c[l] != -1){
            c[r] = c[l];
            t[c[l]]++;
            adj[c[l]].push_back(r);
        }
        else if(c[r] != -1){
            c[l] = c[r];
            t[c[r]]++;
            adj[c[r]].push_back(l);
        }
    }
    
    int resp = 0;
    
    for(int i=1; i<=n; i++){
        if(c[i] == -1 || visitado[c[i]]) continue;
        visitado[c[i]] = true;
        adj[c[i]].push_back(c[i]);
        //for(auto a : adj[c[i]]) cout<<a<<" ";cout<<endl;
        sort(adj[c[i]].begin(), adj[c[i]].end(), func);
        //for(auto a : adj[c[i]]) cout<<a<<" ";cout<<endl;
        int cont = 1;
        int max_c = 0;
        for(int j=1; j<(int)(adj[c[i]].size()); j++){
            if(cores[adj[c[i]][j]] == cores[adj[c[i]][j-1]]) cont++;
            else{
                max_c = (cont>max_c)? cont : max_c;
                cont = 1;
            }
        }
        max_c = (cont>max_c)? cont : max_c;
        resp+=(adj[c[i]].size()-max_c);
    }
    cout<<resp<<endl;
    return 0;
}
