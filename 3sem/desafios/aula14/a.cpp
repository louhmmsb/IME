#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

vector<char> v;

int main(){
    int a;
    cin>>a;

    for(int i=0; i<16; i++){

        char aux;
        cin>>aux;
        if(aux != '.')
        v.push_back(aux);
        
    }

    sort(v.begin(), v.end());

    int count = 1;
    for(int i=1; i<v.size(); i++){

        if(v[i] == v[i-1]) count++;
        else {

            // cout<<v[i-1]<<": "<<count<<endl;
            count = 1;

        }
        

        if(count > 2*a){

            cout<<"NO"<<'\n';
            return 0;
            
        }
        
    }

    cout<<"YES"<<'\n';
    return 0;
    
}
