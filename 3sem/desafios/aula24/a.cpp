#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(int n, int c){
    vector<int> v;
    int dp[n+100][2];
    memset(dp, 0, sizeof(dp));

    v.pb(-20);
    for(int i=0; i<n; i++){
        int aux;
        cin>>aux;
        v.pb(aux);
    }
    dp[1][0] = 0;
    dp[1][1] = -v[1]-c;

    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+v[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-v[i]-c);
    }
    cout<<dp[n][0]<<'\n';
}

int main(){
    int n, c;
    while(scanf("%d %d", &n, &c) == 2){
        solve(n, c);
    }
    
    return 0;
}
