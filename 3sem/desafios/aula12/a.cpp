#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int a;
    cin>>a;
    for(int i=0; i<a; i++){

        ll a, b;
        cin>>a>>b;

        if(a-b != 1 && a-b != 0 && a-b != -1){

            ll c = (a+b)/2;

            cout<<c<<" "<<a+b-c<<"\n";
            
        }

        else cout<<"Ok"<<"\n";
        
    }

    return 0;
}
