#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

bool myFunction(long long int i, long long int j){
    long long int ipoints=0, jpoints=0, i2=i, j2=j;
    while(i%3==0){
        i=i/3;
        ipoints+=10;
    }
    while(i%2==0){
        i=i/2;
        ipoints--;
    }
    while(j%3==0){
        j=j/3;
        jpoints+=10;
    }
    while(j%2==0){
        j=j/2;
        jpoints--;
    }
    if(ipoints==jpoints){
        
    }
    return (ipoints>jpoints);
}

int main(){
    int n;
    long long int v[123], a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        v[i]=a;
    }
    sort(v, v+n, myFunction);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
