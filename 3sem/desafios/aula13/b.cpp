#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    deque<int> q;
    int n, s = 0, d = 0;
    bool eas = true;

    cin>>n;

    for(int i=0; i<n; i++){

        int aux;
        cin>>aux;
        q.push_back(aux);
        
    }

    while(!q.empty()){

        int aux;
        if(q.front()>q.back()){

            aux = q.front();
            q.pop_front();
            
        }

        else{

            aux = q.back();
            q.pop_back();
            
        }

        if(eas){

            s += aux;
            eas = false;
            
        }

        else{

            d += aux;
            eas = true;
            
        }
        
        
    }

    cout<<s<<" "<<d<<'\n';
    return 0;
    
}
