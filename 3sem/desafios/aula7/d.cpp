#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll n, at, ant, size = 0;
  a:while(1){
        cin>>n;
        //cout<<"O N TA AQUI FILHO DA PUTA: "<<n<<endl;
        vector<ll> p;
        if(n == 0) return 0;
        else{
            ant = 0;
            size = 0;
            for(ll i=0; i<n; i++){
                cin>>at;
                if(at-ant == 1){
                    ant = at;
                    continue;
                }
                else{
                    while(size>0 && p[size-1] == ant+1){
                        ant = ant+1;
                        p.pop_back();
                        size--;
                    }
                    p.push_back(at);
                    size++;
                    if(size>1 && p[size-1]>p[size-2]){
                        printf("no\n");
                        while(++i<n){
                            cin>>at;
                        }
                        goto a;
                    }
                }
            }
        }
        printf("yes\n");
    }
    return 0;
}
