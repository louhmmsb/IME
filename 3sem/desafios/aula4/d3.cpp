#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int n, i, x[312345], y[312345], mini1=0, maxi1=0, mini2=0, maxi2=0, inter;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    for(i=0; i<n; i++){
        if(x[i]>x[maxi1]){
            maxi1 = i;
        }
        if(y[i]<y[mini1]){
            mini1 = i;
        }
    }
    mini2 = (mini1==0? 1 : 0);
    maxi2 = (maxi1==0? 1 : 0);
    for(i=0; i<n; i++){
        if(x[i]>=x[maxi2] && i!=maxi1){
            maxi2 = i;
        }
        if(y[i]<=y[mini2] && i!=mini1){
            mini2 = i;
        }
    }
    // cout<<x[maxi1]<<" "<<y[mini1]<<endl<<x[maxi2]<<" "<<y[mini2]<<endl;
    if(maxi1!=mini1) inter = max(y[mini1]-x[maxi2], y[mini2]-x[maxi1]);
    else inter = y[mini2]-x[maxi2];
    inter = max(inter, (long long int)0);
    cout<<inter<<endl;
    return 0;
}
