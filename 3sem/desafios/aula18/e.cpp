#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll DP[10000007][2];

void calc(ll n){
    for(int i=4; i<=n; i++){
        DP[i][1] = (3*DP[i-1][0])%1000000007;
        DP[i][0] = (2*DP[i-1][0] + DP[i-1][1])%1000000007;
    }
}

int main(){
    ll n;
    cin>>n;
    DP[3][0] = 7;
    DP[3][1] = 6;
    if(n == 1) cout<<"0\n";
    else if(n == 2) cout<<"3\n";
    else if(n == 3) cout<<"6\n";
    else {
        calc(n);
        cout<<DP[n][1]<<"\n";
    }
    
    return 0;
}
