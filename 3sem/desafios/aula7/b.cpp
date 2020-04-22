#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll t, n, aux;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        set<ll> s;
        for(int j=0; j<n; j++){
            cin>>aux;
            s.insert(aux);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
