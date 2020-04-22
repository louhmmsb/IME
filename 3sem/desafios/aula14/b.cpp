#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){

    int next = 1, aux, n;
    bool deu = true;

    cin>>n;
    vector<int> p;

    for(int i=0; i<n; i++){

        cin>>aux;

        if(aux == next){

            next++;

            while(!p.empty() && p.back() == next){

                p.pop_back();
                next++;
                
            }
            
        }

        else{

            if(!p.empty() && p.back() < aux) deu = false;
            
            else p.push_back(aux);
                
        }
        
    }

    if(deu) cout<<"yes"<<'\n';
    else cout<<"no"<<'\n';
    
}

int main(){
    int n;

    cin>>n;

    while(n--){
        
        solve();
        
    }

    return 0;
    
}
