#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n, m, t;
    cin>>t;

    while(t--){
        cin>>n>>m;

        if(n%m == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
