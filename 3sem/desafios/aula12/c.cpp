#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){

    int n, m, aux;
    
    cin>>n>>m;
    
    vector<int> lb(n), cb(m), lp(n), cp(m);

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin>>aux;

            if(aux == 1){

                lp[i]++;
                cp[j]++;
                
            }

            else{

                lb[i]++;
                cb[j]++;
                
            }
            
        }
        
    }

    ull resultado = 0;

    for(int i=0; i<lp.size(); i++){

        if(lp[i] != 0) resultado += (((unsigned long long int)1)<<lp[i]) - 1;
        
    }

    for(int i=0; i<lb.size(); i++){

        if(lb[i] != 0) resultado += (((unsigned long long int)1)<<lb[i]) - 1;
        
    }

    for(int j=0; j<cp.size(); j++){

        if(cp[j] != 0) resultado += (((unsigned long long int)1)<<cp[j]) - 1 - cp[j];
        
    }

    for(int j=0; j<cb.size(); j++){

        if(cb[j] != 0) resultado += (((unsigned long long int)1)<<cb[j]) - 1 - cb[j];
        
    }

    //resultado += m*n;
    
    cout<<resultado<<"\n";
    
    return 0;
    
}
