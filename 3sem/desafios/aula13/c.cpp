#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n, m, a, ant;
    char c, cant;
    cin>>n>>m;

    cin>>ant>>cant;
    if(cant == 'M'){

        cout<<"No"<<'\n';
        return 0;
        
    }
    
    for(int i=1; i<m; i++){

        cin>>a>>c;
        if(c == 'M'){

            cout<<"No"<<'\n';
            return 0;
        
        }

        else if(c != cant && a - ant <= 3){

            cout<<"No"<<'\n';
            return 0;
            
        }

        ant = a;
        cant = c;
        
    }

    cout<<"Yes"<<'\n';
    return 0;
    
}
