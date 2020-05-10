#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 5123;

ll f[MAX];

ll fibo(int n){
    if(f[n] == 0) f[n] = fibo(n-1)+fibo(n-2);
    return f[n];
}

int main(){
    f[0] = f[1] = 1;
    while(1){
        vector<int> v;
        ll ant, at, c;
        ll cont = 0;
        ll resp = 1;
        while((c = getchar()) == '\n');
        c = (c - '0');
        if(!c) break;
        cont = 1;
        ant = c;
        while((c = getchar()) != '\n'){
            c -='0';
            if(ant*10+c > 26) v.push_back(cont-1);
            if(c==0){
                ant*=10;
                if(cont-2>=0)v.push_back(cont-2);
            }
            else{
                cont++;
                ant = c;
            }
        }
        
        if(v.empty() || v.back() != cont-1) v.push_back(cont-1);
        for(auto a : v)cerr<<a<<" ";cerr<<endl;

        ant = -1;
        for(auto a : v){
            resp*=fibo(a - ant);
            ant = a;
        }

        cout<<resp<<endl;
        
    }   
        
    return 0;
}
