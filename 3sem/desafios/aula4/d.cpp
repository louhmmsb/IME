#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

class ponto{
  public:
    long long int min;
    long long int max;
    ponto(long long int a=-1, long long int b=-1){
        min = a;
        max = b;
    }
    void operator =(const ponto &novo){
        min = novo.min;
        max = novo.max;
    }
    long long int size(){
        return max-min;
    }
};

ponto intersec(ponto a, ponto b){
    ponto x;
    if(min(a.max, b.max)<max(a.min, b.min)){
        x.min = -1;
        x.max = -1;
    }
    else {
        x.min = max(a.min, b.min);
        x.max = min(a.max, b.max);
    }
    return x;
}

int main(){
    long long int i, n, j, max=0;
    ponto v[312345], a;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>v[i].min;
        cin>>v[i].max;
    }
    for(i=0; i<n; i++){
        a.min = -2;
        for(j=0; j<n; j++){
            if(i==j) continue;
            if(a.min==-1) break;
            if(a.min==-2) a = v[j];
            else{
                a = intersec(a,v[j]);
            }
        }
        if(a.size()>max) max = a.size();
    }
    cout<<max<<endl;
    return 0;
}
