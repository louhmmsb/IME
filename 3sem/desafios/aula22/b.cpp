#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    static int caso = 0;
    ll n;
    cin>>n;
    vector<ll> v(n+7);
    ll dp[n+7];
    caso++;
    for(int i=1; i<=n; i++) cin>>v[i];

    dp[0] = 0;
    dp[1] = v[1];
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+v[i]);
    }

    cout<<"Case "<<caso<<": "<<dp[n]<<endl;
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();

    return 0;
}
