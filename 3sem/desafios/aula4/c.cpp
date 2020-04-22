#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int n, a, b, k, v[212345], pontos = 0;
    cin>>n>>a>>b>>k;
    for(int i=0; i<n; i++){
        cin>>v[i];
        v[i]=v[i]%(a+b);
        if(v[i]==0){
            //v[i] = (int)ceil((float)b/a);
            v[i] = (b+a-1)/a;
        }
        else if(v[i]<=a) v[i]=0;
        else{
            //v[i] = (int)ceil((float)v[i]/a);
            v[i] = (v[i]-1)/a;
        }
    }
    sort(v, v+n);
    for(int i=0; i<n; i++){
        if(v[i]==0) pontos++;
        else if(k){
            k-=v[i];
            if(k>=0)pontos++;
        }
    }
    cout<<pontos<<endl;
    return 0;
}
