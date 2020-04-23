#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MAX 1000000

vector<ll> crivo;

vector<pair <int, int> > leitor;

bool bob[212345];
    
void fazCrivo(){

    int index = 0;

    for(ll i=2; i<MAX; i++){

        bool primo = true;

        if(i == 2) crivo.push_back(2);
        
        else {
            for(ll j=0; j<crivo.size() && crivo[j]<(int)(sqrt(i)+1); j++){

                if(i%crivo[j] == 0){

                    primo = false;
                    break;
                
                }
            
            }
            
        }

        if(primo){

            crivo.push_back(i);

            while(index < leitor.size() && leitor[index].first < i*i){

                bob[leitor[index].second] = false;
                index++;
                
            }
            
            if(index < leitor.size() && leitor[index].first == i*i){

                bob[leitor[index].second] = true;
                index++;
                
            }

            if(index >= leitor.size()) break;
        
        }
    
    }

}

int main(){

    ll n;
    cin>>n;
    
    for(ll i=0; i<n; i++){

        ll x;
        cin>>x;
        leitor.push_back(make_pair(x, i));
        
    }

    sort(leitor.begin(), leitor.end());

    fazCrivo();

    for(int i=0; i<n;i++){

        string aux = (bob[i])? "YES\n" : "NO\n";
        cout<<aux;
        
    }

    return 0;
    
}
