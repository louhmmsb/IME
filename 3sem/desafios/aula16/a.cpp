#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    int n, d, resp = 0, a;
    vector<int> v;
    
    cin>>n>>d>>a;
    
    resp += a;
    for(int i=1; i<n; i++){
        cin>>a;
        while(d>0 && a>0){
            resp++;
            d-=i;
            a--;
        }
        if(d<0){resp--; break;}
        else if(d==0) break;
    }
    char c;
    while((c = getchar()) != '\n');
    cout<<resp<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
