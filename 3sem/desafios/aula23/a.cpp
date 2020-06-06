#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

vector<int> v[2007];
int cores[2007];
bool visitado[2007];
bool deuruim = false;

void dfs(int node, int cor){
    visitado[node] = true;
    cores[node] = cor;
    for(auto a : v[node]){
        if(cores[a] != 0 && cores[a] == cor) deuruim = true;
        if(visitado[a]) continue;
        int nova_cor = (cor == 1)? 2 : 1;
        dfs(a, nova_cor);
    }
}

void solve(){
    static int caso = 0;
    int b, c;
    cin>>b>>c;
    memset(v, 0, sizeof(v));
    memset(cores, 0, sizeof(cores));
    memset(visitado, 0, sizeof(visitado));
    deuruim = false;
    for(int i=0; i<c; i++){
        int aux1, aux2;
        cin>>aux1>>aux2;
        v[aux1].pb(aux2);
        v[aux2].pb(aux1);
    }
    for(int i=1; i<=b; i++){
        if(!visitado[i]) dfs(i, 1);
    }
    cout<<"Scenario #"<<(++caso)<<":"<<endl;
    if(deuruim) cout<<"Suspicious bugs found!";
    else cout<<"No suspicious bugs found!";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}
