#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int q, x, y, k, dif, dmoves;
    cin>>q;
    for(int i=0; i<q; i++){
        dmoves=0;
        cin>>x>>y>>k;
        if(max(x,y)>k){
            cout<<"-1"<<endl;
            continue;
        }
        if(abs(x-y)%2 == 1){
            cout<<k-1<<endl;
            continue;
        }
        else{
            dif = abs(x-y);
            dmoves+=dif;
            dmoves+=min(x,y);
            k-=dmoves;
            if(k%2 == 1) dmoves+=k-2;
            else dmoves+=k;
        }
        cout<<dmoves<<endl;
    }
}
