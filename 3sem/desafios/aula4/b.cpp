#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int x, y, n, a=1, max=1, v[21234];
    cin>>n;
    cin>>x;
    for(long long int i=1; i<n; i++){
        cin>>y;
        if(y<=2*x) a++;
        else {
            if(a>max) max = a;
            a = 1;
        }
        x = y;
    }
    if (a>max) max = a;
    cout<<max<<endl;
    return 0;
}
