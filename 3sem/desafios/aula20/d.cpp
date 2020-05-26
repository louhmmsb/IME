#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 5610;

struct turtle{
    int w, s;
    turtle(int W = 0, int S = 0): w(W), s(S){};

    bool operator <(const turtle t) const{
        if(s != t.s) return s < t.s;

        return w < t.w;
    }
};

int DP[MAX];
turtle T[MAX];

int main(){
    int n = 0;
    while(scanf("%d %d", &T[n].w, &T[n].s) != EOF) n++;

    sort(T, T+n);

    memset(DP, 0x3f3f3f3f, sizeof(DP));
    DP[0] = 0;

    int r = 0;

    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if(T[i].s >= DP[j]+T[i].w){
                DP[j+1]=min(DP[j+1], DP[j] + T[i].w);
                r = max(r, j+1);
            }
        }
    }
    pi(r);

    return 0;
}
