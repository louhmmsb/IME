#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 2007;

int dp[MAX][MAX];

int main(){
    int n, v[MAX], y;
    si(n);
    for(int i=1; i<=n; i++){
        si(v[i]);
        dp[i][i] = v[i]*n;
    }

    for(int e=n; e>=1; e--){
        for(int d=e+1; d<=n; d++){
            y = n-d+e;
            dp[e][d] = max(dp[e+1][d] + v[e]*y, dp[e][d-1] + v[d]*y);
        }
    }

    //for(int i=1; i<=n; i++){
    //for(int j=1; j<=n; j++){
    //cout<<setw(2)<<dp[i][j]<<" ";
//}
    //cout<<endl;
//}
    
    pi(dp[1][n]);
    return 0;
}
