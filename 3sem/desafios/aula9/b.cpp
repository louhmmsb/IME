#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n;
    ll a = 0, b = 0, c = 0, d = 0, aux;
    char qual = 'a';
    cin>>n;
    for(int i=0; i<n; i++){
        if(qual == 'a'){
            cin>>aux;
            a+=aux;
            qual = 'b';
        }
        else if(qual == 'b'){
            cin>>aux;
            b+=aux;
            qual = 'c';
        }
        else if(qual == 'c'){
            cin>>aux;
            c+=aux;
            qual = 'd';
        }
        else if(qual == 'd'){
            cin>>aux;
            d+=aux;
            qual = 'a';
        }
    }
    if(a>=b && a>=c && a>=d) cout<<"A"<<endl;
    else if(b>=c && b>=d) cout<<"B"<<endl;
    else if(c>=d) cout<<"C"<<endl;
    else cout<<"D"<<endl;
    return 0;
}
