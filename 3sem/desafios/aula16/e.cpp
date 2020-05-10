#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int resp;
bool visitado[11234];
int dist[11234];
vector<int> v[11234];

void dfs(int ini, int d){
    visitado[ini] = true;
    dist[ini] = d;
    if(dist[ini] > dist[resp]) resp = ini;
    for(auto a : v[ini]){
        if(visitado[a]) continue;
        dfs(a, d+1);
    }
}

int main(){
    int n, u, w;
    cin>>n;
    

    for(int i=0; i<n-1; i++){
        cin>>u>>w;

        v[u].push_back(w);
        v[w].push_back(u);
    }

    dfs(w, 0);
    memset(visitado, false, sizeof(visitado));
    memset(dist, 0, sizeof(dist));

    dfs(resp, 0);

    cout<<dist[resp]<<'\n';
    return 0;
    
}
