#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll pot[33] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

int main(){
    ll n, v[212345], resposta[3], max = 1;
    bool aux = false, decima = false, debaixo = false;
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v, v+n);
    for(ll i=0; i<n; i++){
        for(int j=0; j<33; j++){
            if(binary_search(v, v+n, v[i]+pot[j])){
                max = 2;
                resposta[1] = v[i];
                resposta[2] = v[i]+pot[j];
                debaixo = false;
                decima = true;
                aux = true;
            }
            if(binary_search(v, v+n, v[i]-pot[j])){
                max = 2;
                resposta[1] = v[i];
                resposta[0] = v[i]-pot[j];
                if(aux){
                    cout<<"3"<<endl;
                    cout<<resposta[0]<<" "<<resposta[1]<<" "<<resposta[2]<<endl;
                    return 0;
                }
                debaixo = true;
                decima = false;
            }
            aux = false;
        }
    }
    if(max == 2){
        cout<<max<<endl;
        if(decima){
            cout<<resposta[1]<<" "<<resposta[2]<<endl;
        }
        if(debaixo){
            cout<<resposta[0]<<" "<<resposta[1]<<endl;
        }
    }
    else if(max == 1){
        cout<<"1"<<endl;
        cout<<v[0]<<endl;
    }
    return 0;
}
