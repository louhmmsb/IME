#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    ull n, k;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        if(n%10==0) n=n/10;
        else n = n-1;
    }
    cout<<n<<endl;
    return 0;
}
