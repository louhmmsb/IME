#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int dp[1007][1007][11][2];
int n, m, k;
string s, t;

int solve(int sx, int tx, int kx, bool cont){
    if(kx == 0 or sx == n or tx == m) return 0;
    if(dp[sx][tx][kx][cont] != -1) return dp[sx][tx][kx][cont];

    if(s[sx] == t[tx]) dp[sx][tx][kx][cont] = max(solve(sx+1, tx+1, kx, true)+1, solve(sx+1, tx+1, kx-1, false)+1);
    if(cont == false){
        dp[sx][tx][kx][cont] = max(dp[sx][tx][kx][cont], max(solve(sx+1, tx, kx, false), solve(sx, tx+1, kx, false)));
    }
    else dp[sx][tx][kx][cont] = max(dp[sx][tx][kx][cont], max(solve(sx+1, tx, kx-1, false), solve(sx, tx+1, kx-1, false)));
    return dp[sx][tx][kx][cont];
}

int main(){

    si(n);si(m);si(k);
    cin>>s>>t;

    
    memset(dp, -1, sizeof(dp));
    int jooj = solve(0, 0, k, 0);
    cout<<jooj<<endl;

    return 0;
}
