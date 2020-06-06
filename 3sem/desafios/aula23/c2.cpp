#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int dp[507][507];
int tab[507][507];

int solve(){
    int r, c, aux1, aux2;
    si(r);si(c);
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>tab[i][j];
        }
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[r][c] = 1;
    for(int i=r; i>=1; i--){
        for(int j=c; j>=1; j--){
            if(j == c && i == r) continue;
            aux1 = aux2 = 0x3f3f3f3f;
            if(i != r) aux1 = dp[i+1][j];
            if(j != c) aux2 = dp[i][j+1];
            dp[i][j] = max(min(aux1, aux2)-tab[i][j], 1);
        }
    }
    cout<<dp[1][1]<<endl;
}

int main(){
    int t;
    si(t);

    while(t--) solve();

    return 0;
}
