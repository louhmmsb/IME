#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

int dp[107][107];
int n, v[107];

int soma(int ini1, int fim1, int ini2, int fim2){
    int soma1 = 0, soma2 = 0;
    for(int i=ini1; i<= fim1; i++){
        soma1+=v[i];
    }
    for(int i=ini2; i<= fim2; i++){
        soma2+=v[i];
    }
    return (soma1%100)*(soma2%100);
}

int solve(int ini, int fim){
    if(ini >= fim) return 0;
    if(dp[ini][fim] == -1){
        dp[ini][fim] = 0x3f3f3f3f;
        for(int i=ini; i<= fim; i++){
            dp[ini][fim] = min(dp[ini][fim], solve(ini, i)+solve(i+1, fim)+soma(ini, i, i+1, fim));
        }
    }
    return dp[ini][fim];
}

int main(){

    while(scanf("%d", &n) != EOF){
        for(int i=0; i<=n; i++){
            v[i] = 0;
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++){
            si(v[i]);
        }
        cout<<solve(0, n)<<endl;
    }
    return 0;
    
}
