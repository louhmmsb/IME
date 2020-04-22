#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int x, x2, x3, x4, abc;
    cin>>x>>x2>>x3>>x4;
    abc=max(max(x,x2), max(x3,x4));
    if(x!=abc && x2!=abc) cout<<x+x2-abc<<" ";
    if(x!=abc && x3!=abc) cout<<x+x3-abc<<" ";
    if(x!=abc && x4!=abc) cout<<x+x4-abc<<" ";
    if(x2!=abc && x3!=abc) cout<<x2+x3-abc<<" ";
    if(x2!=abc && x4!=abc) cout<<x2+x4-abc<<" ";
    if(x3!=abc && x4!=abc) cout<<x3+x4-abc<<" ";
    return 0;
}
