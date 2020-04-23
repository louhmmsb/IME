#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MAX 1000000

vector<ll> crivo;

void fazCrivo(){

    crivo.push_back(2);

    for(ll i=3; i<MAX; i++){

        bool primo = true;
        
        for(ll j=0; j<crivo.size() && crivo[j]<(int)(sqrt(i)+1); j++){

            if(i%crivo[j] == 0){

                primo = false;
                break;
                
            }
            
        }

        if(primo) crivo.push_back(i);
        
    }

    cout<<"Cabei"<<endl;
    
}

int main(){

    fazCrivo();

    // for(auto a : crivo) cout<<a<<" ";
    // cout<<endl;

    ll n;

    for(ll i=0; i<n; i++){

        ll x;
        cin>>x;

        for(auto a : crivo){

            if (a*a == x){

                cout<<"YES\n";
                break;

            }

            else if(a*a > x){

                cout<<"NO\n";
                break;
                
            }
            
        }
        
    }

    return 0;
    
}
