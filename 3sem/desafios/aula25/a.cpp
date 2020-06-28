#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 2007;

int v[MAX];
int s[MAX];

int dp[MAX][MAX];

int main(){
    int S, N;
    cin>>S>>N;

    for(int i=1; i<=N; i++){
        cin>>s[i]>>v[i];
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<=S; j++){
            if(s[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-s[i]]+v[i]);
            }
        }
    }
    cout<<dp[N][S]<<endl;
    return 0;
}
