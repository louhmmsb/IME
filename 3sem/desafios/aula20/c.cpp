#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    double a, b, c, d;
    cin>>a>>b>>c>>d;

    double s = (a+b+c+d)/2;
    s = sqrt((s-a)*(s-b)*(s-c)*(s-d));
    printf("%.2lf\n", s);
}

int main(){
    int t;
    si(t);

    while(t--){
        solve();
    }

    return 0;
}
