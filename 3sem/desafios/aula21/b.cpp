#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

ll sas(ll a, ll b){
    if(a%b == 0) return a/b;
    return a/b+1;
}

int main(){
    ll n, m;
    ll q;

    cin>>n>>m>>q;
    ll aux = __gcd(n, m);
    //cout<<__gcd(n, m)<<endl;

    for(int i=0; i<q; i++){
        ll sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;

        if(sx == 1) sx = n;
        else sx = m;
        if(ex == 1) ex = n;
        else ex = m;

        sx = sx/aux;
        ex = ex/aux;

        bool deu = false;
        if(sas(ey, ex) == sas(sy, sx)) deu = true;
        if(aux == 1) deu = true;

        if(deu) cout<<"YES\n";
        else cout<<"NO\n";
    }
        
    return 0;
}
