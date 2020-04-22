#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int x, y, n;
    cin>>x>>y>>n;
    bool deu;
    for(int i=1; i<=n; i++){
        deu = false;
        if(i%x == 0){
            cout<<"Fizz";
            deu = true;
        }
        if(i%y == 0){
            cout<<"Buzz";
            deu = true;
        }
        if(deu == false) cout<<i;
        cout<<endl;
    }
    return 0;
}
