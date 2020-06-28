#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll n, cx, cy, ux, uy, resp = 0;
    cin>>cx>>cy>>ux>>uy>>n;

    for(ll i=0; i<n; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        if((a*cx+b*cy+c) > 0 && (a*ux+b*uy+c) < 0) resp++;
        if((a*cx+b*cy+c) < 0 && (a*ux+b*uy+c) > 0) resp++;
    }
    
    cout<<resp<<'\n';
    return 0;
}
