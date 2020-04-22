#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

class inter{
  public:
    ll l;
    ll r;
    ll val;
    bool operator<(const inter &i)const{
        if(l == i.l) return r<i.r;
        else return l<i.l;
    }
    //friend ostream& operator<<(ostream& out, inter i);
};

//ostream& operator<<(ostream& out, inter i){
//out<<"l: "<<i.l<<" "<<"r: "<<i.r<<" "<<"val: "<<i.val<<endl;
//  return out;
//}

int main(){
    ll t, n, u, q;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &u);
        vector<inter> v;
        for(ll i=0; i<u; i++){
            ll l, r, val;
            inter aux;
            scanf("%lld %lld %lld", &l, &r, &val);
            aux.l = l;aux.r = r;aux.val = val;
            v.push_back(aux);
        }
        sort(v.begin(), v.end());
        //for(ll i=0; i<v.size(); i++){
        //cout<<v[i];
        //}
        scanf("%lld", &q);
        for(ll i=0; i<q; i++){
            ll index;
            scanf("%lld", &index);
            ll soma = 0;
            vector<inter>::iterator a;
            inter aux;
            aux.l = index;
            aux.r = index;
            a = lower_bound(v.begin(), v.end(), aux);
            ll j = (long long int)(a-v.begin());
            for(j=0; j<v.size(); j++){
                if(index>= v[j].l && index<= v[j].r) soma+=v[j].val;
                if(v[j].l > index) break;
            }
            printf("%lld\n", soma);
        }
    }
    return 0;
}
