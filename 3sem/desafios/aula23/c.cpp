#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

pair<int, int> dp[507][507];

pair<int, int>  sas(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return a;
    else if(a.first == b.first){
        if(a.second > b.second) return a;
        else return b;
    }
    else return b;
}

void solve(){
    int r, c, v;
    si(r);si(c);
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            si(v);
            if(i == 1 && j == 1){
                dp[i][j] = mp(1, v);
                continue;
            }
            if(i == 1){
                if(dp[i][j-1].second + v >= 0) dp[i][j] = mp(dp[i][j-1].first, dp[i][j-1].second+v);
                else dp[i][j] = mp(dp[i][j-1].first - (dp[i][j-1].second + v), 0);
            }
            else if(j == 1){
                if(dp[i-1][j].second + v >= 0) dp[i][j] = mp(dp[i-1][j].first, dp[i-1][j].second+v);
                else dp[i][j] = mp(dp[i-1][j].first - (dp[i-1][j].second + v), 0);
            }
            else{
                pair<int, int> aux1, aux2;
                if(dp[i][j-1].second + v >= 0) aux1 = mp(dp[i][j-1].first, dp[i][j-1].second+v);
                else aux1 = mp(dp[i][j-1].first - (dp[i][j-1].second + v), 0);
                if(dp[i-1][j].second + v >= 0) aux2 = mp(dp[i-1][j].first, dp[i-1][j].second+v);
                else aux2 = mp(dp[i-1][j].first - (dp[i-1][j].second + v), 0);
                dp[i][j] = sas(aux1, aux2);
            }
        }
    }
    cout<<dp[r][c].first<<endl;
}

int main(){
    int t;
    si(t);

    while(t--) solve();
}
