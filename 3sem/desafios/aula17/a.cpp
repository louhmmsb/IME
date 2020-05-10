#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    ll a, b, r;
    cin>>a>>b;
    r = a%b;
    if(r==0) cout<<"0\n";
    else cout<<b - (r)<<'\n';
}

int main(){
    ll t;
    cin>>t;

    while(t--) solve();
    
    return 0;
}
