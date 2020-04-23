#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){

    ll n, l;

    vector<int> v;

    cin>>n>>l;

    for(int i=0; i<n; i++){

        ll aux;
        cin>>aux;
        
        v.push_back(aux);
        
    }

    sort(v.begin(), v.end());

    double maxD = 0;
    double aux;
    
    for(int i=1; i<v.size(); i++){

        aux = (v[i] - v[i-1])/2.0;
        
        maxD = (aux > maxD)? aux : maxD;
        
    }
    
    aux = l - v.back();
    
    maxD = (aux > maxD)? aux : maxD;

    maxD = (v[0] > maxD)? v[0] : maxD;

    printf("%.9lf\n", maxD);

    return 0;
    
}
