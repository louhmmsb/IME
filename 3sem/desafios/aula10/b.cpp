#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll sup = 1000000000, inf = 1;
    char resp = 'a';
    while(1){
        int aux = (sup+inf)/2;
        cout<<"Q "<<aux<<"\n";
        cout.flush();
        cin>>resp;
        if(resp == '=') break;
        else if(resp == '<') sup = aux-1;
        else if(resp == '>') inf = aux+1;
    }
    return 0;
}
