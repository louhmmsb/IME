#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x);

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int d, sumTime, sumMin = 0, sumMax = 0;
    vector<int> mins, maxs, resp;
    si(d);si(sumTime);

    for(int i=0; i<d; i++){
        int auxMin, auxMax;
        si(auxMin);si(auxMax);
        mins.pb(auxMin);
        resp.pb(auxMin);
        maxs.pb(auxMax);
        sumMin+=auxMin;
        sumMax+=auxMax;
    }
    if(sumTime>=sumMin && sumTime<=sumMax){
        int dif = sumTime-sumMin;
        cout<<"YES\n";
        int i=0;
        while(dif>0){
            if(resp[i]<maxs[i]){
                resp[i]++;
                dif--;
            }
            else i++;
        }
        for(auto a : resp) cout<<a<<" ";cout<<"\n";
    }
    else cout<<"NO\n";

    return 0;

}
