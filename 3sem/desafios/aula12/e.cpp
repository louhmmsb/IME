#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n, tot = 0, ncasos1 = 0, ncasos2 = 0;
    string s, t;
    vector<int> casos1, casos2;

    cin>>n;

    vector<int> casos(n);
    
    cin>>s;
    cin>>t;

    for(int i=0; i<n; i++){

        if(s[i] == 'a' && t[i] == 'b'){
            
            casos1.push_back(i+1);
            ncasos1++;
            
        }
        
        else if(s[i] == 'b' && t[i] == 'a'){
            
            casos2.push_back(i+1);
            ncasos2++;
            
        }
        
    }

    if((ncasos1&1) ^ (ncasos2&1)){

        cout<<"-1"<<'\n';
        return 0;
            
    }

    if(ncasos1&1 == 1){
        
        cout<<(ncasos1+ncasos2)/2 + 1<<'\n';
        cout<<casos1[casos1.size()-1]<<" "<<casos1[casos1.size()-1]<<'\n';
        cout<<casos1[casos1.size()-1]<<" "<<casos2[casos2.size()-1]<<'\n';
        
        
    }
    
    else cout<<(ncasos1+ncasos2)/2<<'\n';

    int i=0;
    
    for(i=0; i<ncasos1-1;){

        cout<<casos1[i++]<<" "<<casos1[i++]<<'\n';
        
    }

    i=0;

    for(i=0; i<ncasos2-1;){

        cout<<casos2[i++]<<" "<<casos2[i++]<<'\n';
        
    }

    return 0;
    
}
