#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll n, u;
        scanf("%lld %lld", &n, &u);
        vector<ll> v(n);
        for(ll i=0; i<u; i++){
            ll l, r, val;
            scanf("%lld %lld %lld", &l, &r, &val);
            for(ll j=l; j<=r; j++){
                v[j]+=val;
            }
        }
        ll q;
        scanf("%lld", &q);
        for(ll i=0; i<q; i++){
            ll index;
            scanf("%lld", &index);
            printf("%lld\n", v[index]);
        }
    }
    return 0;
}
