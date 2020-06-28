#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n;
    int ans[53];
    ll m;
    scanf("%d %lld", &n, &m);
    int l = 1, r = n;
    for(int i=1; i<=n; i++){
        ll power;
        if(n-i-1 <= 0) power = 1;
        else power = (1LL<<(n-i-1));
        
        if(m <= power) ans[l++] = i;
        else{
            ans[r--] = i;
            m -= power;
        }
    }
    for(int i=1; i<=n; i++){
        printf("%d%c", ans[i], (i==n)? '\n' : ' ');
    }
    return 0;
}
