#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int dp[2007][2007];

void solve(){
    string s, t;
    int aux = 0;
    memset(dp, 0, sizeof(dp));
    cin>>s>>t;
    int ss = (int)s.size(), ts = (int)t.size();
    for(int i=0; i<=ss; i++) dp[0][i] = i;
    for(int i=0; i<=ts; i++) dp[i][0] = i;

    for(int i=1; i<=ss; i++){
        for(int j=1; j<=ts; j++){
            if(s[i-1] == t[j-1]) aux = 0;
            else aux = 1;
            int sas = min(dp[i-1][j]+1, dp[i][j-1]+1);
            dp[i][j] = min(sas, dp[i-1][j-1]+aux);
        }
    }
    cout<<dp[ss][ts]<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--) solve();

    return 0;
}
