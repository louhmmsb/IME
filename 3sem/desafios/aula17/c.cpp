#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 1001;

int DP[MAX][MAX];

int main(){
    char s[MAX], t[MAX], *c;
    while(NULL != (c = fgets(s, MAX, stdin))){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                DP[i][j] = 0;
            }
        }
        c = fgets(t, MAX, stdin);
        int n = strlen(s);
        int m = strlen(t);

        for(int i=0; i<MAX; i++){
            DP[0][i] = DP[i][0] = 0;
        }
    
        for(size_t i=1; i<=n; i++){
            for(size_t j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
                DP[i][j] = max(DP[i][j], DP[i-1][j]);
                DP[i][j] = max(DP[i][j], DP[i][j-1]);
            }
        }
        cout<<max(DP[n][m] - 1, 0)<<'\n';
    }

    return 0;
}
