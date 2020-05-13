#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 0x3f3f3f3f;
int e, f, peso, n, p[507], v[507], dp[25007];

void solve(){
    si(e);si(f);si(n);
    peso = f-e;

    memset(dp, INF, sizeof(dp));
    for(int i=0; i<n; i++){
        si(v[i]);si(p[i]);
        dp[p[i]] = min(dp[p[i]], v[i]);
    }
    int i=0;
    for(i=0; i<=peso; i++){
        if(dp[i] == INF) continue;
        for(int j=0; j<n; j++){
            dp[i+p[j]] = min(dp[i+p[j]], dp[i]+v[j]);
        }
    }
    if(dp[peso] != INF) cout<<"The minimum amount of money in the piggy-bank is "<<dp[peso]<<".\n";
    else cout<<"This is impossible.\n";
    
}

int main(){
    int t;
    si(t);

    while(t--) solve();

    return 0;
}
