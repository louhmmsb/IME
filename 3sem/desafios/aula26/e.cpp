#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAXN = 1e3+7, MAXL = 12;

vector<int> adj[MAXN];

int prof[MAXN], pai[MAXN][MAXL];

void dfs(int u, int p){
    for(auto a : adj[u]){
        if(a != p){
            prof[a] = prof[u] + 1;
            pai[a][0] = u;
            dfs(a, u);
        }
    }
}

void precalc(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<MAXL; j++){
            pai[i][j] = pai[pai[i][j-1]][j-1];
        }
    }
}

void init(int n, int ini){
    prof[1] = 0;
    dfs(ini, ini);
    precalc(n);
}

int LCA(int v, int u){
    if(prof[v] > prof[u]) swap(v, u);

    for(int p=MAXL-1; p>=0; p--){
        if((1<<p)<=(prof[u] - prof[v])){
            u = pai[u][p];
        }
    }
    
    for(int p=MAXL-1; p>=0; p--){
        if(pai[v][p] != pai[u][p]){
            u = pai[u][p];
            v = pai[v][p];
        }
    }
    
    if(v != u) return pai[v][0];

    return v;
}

void solve(){
    static int contaCasos = 0;
    int n, soma;
    si(n);
    for(int i=0; i<=n+3; i++) adj[i].clear();
    soma = ((1+n)*n)/2;
    for(int i=1; i<=n; i++){
        int m;
        si(m);
        for(int j=0; j<m; j++){
            int aux;
            si(aux);
            adj[i].pb(aux);
            soma-=aux;
            adj[aux].pb(i);
        }
    }
    int q;
    init(n, soma);
    scanf("%d", &q);
    printf("Case %d:\n", ++contaCasos);
    for(int i=0; i<q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
}

int main(){
    int t;
    si(t);

    while(t--){
        solve();
    }

    return 0;
}
