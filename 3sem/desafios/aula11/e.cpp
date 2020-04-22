#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll n;
vector<ll> tab[312345];
bool visitado[312345];

ll dfs(ll ini, bool passei, ll x){

    ll result = 0;
    visitado[ini] = true;
    if(ini == x) passei = true;

    if (passei == true) result++;
    
    for(ll i=0; i<tab[ini].size(); i++){

        if(visitado[tab[ini][i]] == false) result += dfs(tab[ini][i], passei, x);
        
    }

    return result;
        
}

int main(){
    ll x, y;
    cin>>n>>x>>y;
    for(ll i=0; i<n-1; i++){

        ll aux1, aux2;
        cin>>aux1>>aux2;
        tab[aux1].push_back(aux2);
        tab[aux2].push_back(aux1);
        
    }

    bool passei = false;
    ll resp1 = dfs(y, passei, x);

    passei = false;
    memset(visitado, false, n+1);
    ll resp2 = dfs(x, passei, y);

    ll resp = n*(n-1) - (resp1*resp2);
    //cout<<resp1<<" "<<resp2<<endl;
    cout<<resp<<'\n';
    return 0;
    
}
