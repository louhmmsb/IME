#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAXN = 1e6+7;
vector<int> adj[MAXN], t(MAXN), resp;
int n, r, sum=0;

int dfs(int u){
    int sub=t[u];
    for(auto a : adj[u]){
        int prox = dfs(a);
        if(3*prox == sum && resp.size() < 2) resp.pb(a);
        else sub+=prox;
    }
    return sub;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int p;
        scanf("%d %d", &p, &t[i]);
        sum+=t[i];
        if(p) adj[p-1].pb(i);
        else r = i;
    }
    dfs(r);
    if(sum%3 || resp.size() != 2){
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n", ++resp[0], ++resp[1]);
    return 0;
}
