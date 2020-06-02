#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int dp[1007][5007];
int h[5007];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k, n;
        scanf("%d %d", &k, &n);
        k+=8;
        for(int i=n; i>=1; i--){
            scanf("%d", &h[i]);
        }
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for(int i=0; i<=n; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<=k; i++){
            for(int j = 3*i; j<=n; j++){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-2] + (h[j-1]-h[j])*(h[j-1]-h[j]));
            }
        }
        pi(dp[k][n]);
    }
    return 0;
}
