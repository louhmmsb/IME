#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int dp[107], v[107];

void solve(){
    int n, k;
    cin>>n>>k;

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    memset(v, 0, sizeof(v));

    for(int i=1; i<=k; i++){
        cin>>v[i];
    }
    dp[0] = 0;
    for(int i=0; i<=k; i++){
        for(int j=0; j<=k; j++){
            if(j <= i && v[j] != -1)
                dp[i] = min(dp[i], dp[i-j] + v[j]);
        }
    }
    
    cout<<((dp[k] == 0x3f3f3f3f)? -1 : dp[k])<<endl;
}

int main(){
    int C;
    cin>>C;

    while(C--) solve();

    return 0;
}
