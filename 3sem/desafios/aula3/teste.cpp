#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int v[212345], n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        scanf("%lli", &v[i]);
    }
    sort(v, v+n);
    if(k=0 && v[0]==1) cout<<"-1";
    else if(k<n && v[k-1]==v[k]) cout<<"-1";
    else cout<<v[k-1]<<endl;
    cout<<&k<<" "<<v<<" "<<&n;
    return 0;
}
