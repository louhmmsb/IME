#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

vector<ll> v;
map<ll, bool> m;

int main(){
    ll n, k, r;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        ll aux;
        
        cin>>aux;
        v.push_back(aux);
    }

    if(k == 1){
        cout<<n<<'\n';
        return 0;
    }
    
    sort(v.begin(), v.end());
    r = v.size();
    
    for(auto a : v){
        if(!m.count(a) && binary_search(v.begin(), v.end(), k*a)){
            m.insert(make_pair(k*a, false));
            r--;
        }
    }
    
    cout<<r<<'\n';
    
    return 0;
}
