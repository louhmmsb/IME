#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int t, i, x, y, a, b, dist, conta=0, n=0;
    cin>>t;
    for(i=0; i<t; i++){
	cin>>x>>y>>a>>b;
	conta=(y-x)%(a+b);
	if(conta==0) cout<<(y-x)/(a+b)<<endl;
	else cout<<"-1"<<endl;
    }
    return 0;
}
