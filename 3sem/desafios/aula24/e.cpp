#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define fastIO() if(1){ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    int n;
    cin>>n;
    n <<= 1;

    vector<pair <int, ll> > adj[n];

    for(int i=0; i<n-1; i++){
        int a, b;
        ll c;
        cin>>a>>b>>c;
        a--, b--;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    vector<int> pais(n, -1), f(1);
    vector<ll> custo(n);

    pais[0] = 0;
    for(int x=0; x<f.size(); x++){
        int i = f[x];
        for(auto [j, c] : adj[i]){
            if(pais[j] == -1){
                pais[j] = i;
                custo[j] = c;
                f.pb(j);
            }
        }
    }
    vector<int> tam(n, 1);
    ll mn = 0, mx = 0;
    reverse(f.begin(), f.end());
    for(int i : f){
        tam[pais[i]] += tam[i];
        mx += custo[i] * min(tam[i], n-tam[i]);
        mn += custo[i] * (tam[i] & 1);
    }
    cout<<mn<<" "<< mx<<'\n';
}

int main(){
    fastIO();
    int t;
    for(cin >> t; t--; solve());

    return 0;
}
