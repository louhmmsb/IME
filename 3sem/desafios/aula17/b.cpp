#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    ll n, x, sum=0;
    vector<int> v;
    
    cin>>n>>x;
    for(ll i=0; i<n; i++){
        ll aux;
        cin>>aux;
        sum += aux;

        v.push_back(aux);
    }

    sort(v.begin(), v.end());

    ll i;
    for(i=0; i<n; i++){
        if(sum >= (n-i)*x) break;
        sum -= v[i];
    }

    cout<<n-i<<'\n';
    
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();

    return 0;
}
