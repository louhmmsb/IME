#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 10123;

void solve(){
    int m, n, t, a, b;
    pair<int, int> dp[MAX];
    if(scanf("%d %d %d", &m, &n, &t) == EOF) exit(0);

    a = min(m, n);
    b = max(m, n);

    dp[0].first = 0;
    for(int i=1; i<=t; i++){
        if(i-b>=0){
            if(dp[i-1].first+1 < dp[i-b].first && dp[i-1].first+1 < dp[i-a].first){
                dp[i].first = dp[i-1].first+1;
                dp[i].second = dp[i-1].second;
            }
            else if(dp[i-b].first < dp[i-a].first){
                dp[i].first = dp[i-b].first;
                dp[i].second = dp[i-b].second+1;
            }
            else{
                dp[i].first = dp[i-a].first;
                dp[i].second = dp[i-a].second+1;
            }
        }
        else if(i-a>=0){
            if(dp[i-1].first+1 < dp[i-a].first){
                dp[i].first = dp[i].first+1;
                dp[i].second = dp[i-1].second;
            }
            else{
                dp[i].first = dp[i-a].first;
                dp[i].second+=dp[i-a].second+1;
            }
        }
        else{
            dp[i].first = dp[i-1].first+1;
            dp[i].second = dp[i-1].second;
        }
    }
    //for(int i=0; i<=t; i++) cout<<i<<": "<<dp[i].first<<" "<<dp[i].second<<endl;
    cout<<dp[t].second;
    if(dp[t].first != 0)cout<<" "<<dp[t].first;
    cout<<"\n";
}

int main(){

    while(1) solve();

    return 0;
    
}
