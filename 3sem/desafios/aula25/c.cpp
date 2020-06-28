#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int soma = 0;
int n, m;

vector<int> adj[1012345];
int temGato[1012345];
bool visitado[1012345];

void dfs(int ini, int nGatos){
    visitado[ini] = true;
    nGatos = nGatos*temGato[ini]+temGato[ini];
    if(adj[ini].size() == 0 && nGatos<=m) soma++;
    if(nGatos > m) return;
    int conta_vis = 0;
    for(int a : adj[ini]){
        if(visitado[a]){
            conta_vis++;
            continue;
        }
        dfs(a, nGatos);
    }
    if(conta_vis == adj[ini].size() && nGatos<=m) soma++;
}

int main(){
    cin>>n>>m;

    for(int i=1; i<=n; i++) cin>>temGato[i];

    for(int i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(1, 0);
    cout<<soma<<endl;

    return 0;
    
}
