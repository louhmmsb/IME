#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    
    int a1, a2, k1, k2, n, min, max, mink, maxk, players, cartoes;
    vector<int> v;
    cin>>a1>>a2>>k1>>k2>>n;

    if(k2>k1){

        min = a1;
        mink = k1;
        max = a2;
        maxk = k2;
        
    }

    else{

        min = a2;
        mink = k2;
        max = a1;
        maxk = k1;
        
    }
    
    for(int i=0; i<min; i++){

        v.push_back(mink);
        
    }

    for(int i=0; i<max; i++){

        v.push_back(maxk);
        
    }

    players = n - a1*(k1-1) - a2*(k2-1);

    if(players>a1+a2) cout<<a1+a2<<" ";
    else if(players>0) cout<<players<<" ";
    else cout<<"0"<<" ";
    
    cartoes = n;
    players = 0;
        
    for(int i=0; i<v.size(); i++){

        if(cartoes >= v[i]){
            cartoes-=v[i];
            players++;
        }
        else break;
        
    }
    
    cout<<players<<"\n";
    return 0;
    
}
