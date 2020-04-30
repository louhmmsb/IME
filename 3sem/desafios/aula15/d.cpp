#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

bool visitado[51];
vector<ull> v[51];
ull perigo = 1;

void dfs(ull ini){
    visitado[ini] = true;
    
    for(auto a : v[ini]){
        if(visitado[a] == true) continue;
        perigo *= (ull)2;
        dfs(a);
    }
}

int main(){
    ull n, m;

    cin>>n>>m;

    for(ull i=0; i<m; i++){
        ull x, y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(ull i=0; i<n; i++){
        if(visitado[i] == false) dfs(i);
    }

    cout<<perigo<<'\n';
    return 0;
    
}
