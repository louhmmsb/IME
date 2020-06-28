#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

vector<pair<int, int> > corte(vector<pair<int, int> > old){
    int conta[100007];
    int max = 0;
    memset(conta, 0, sizeof(conta));
    for(auto a : old){
        conta[a.first]++;
        if(a.first > max) max = a.first;
    }
    for(int i=1; i<=max+4; i++){
        conta[i]+=conta[i-1];
    }

    vector<pair<int, int> > resp(old.size()+1);
    resp.pb(mp(0, 0));
    for(auto a : old){
        resp[conta[a.first]--] = a;
    }
    return resp;
}

void solve(){
    int n, q;
    static int conta = 0;
    vector<pair<int, int> > v;
    scanf("%d %d", &n, &q);

    for(int i=1; i<=n; i++){
        int aux;
        scanf("%d", &aux);
        v.pb(mp(aux, i));
    }
    //for(auto a : v) cout<<a.first<<":"<<a.second<<" ";cout<<endl;
    v = corte(v);
    //for(auto a : v) cout<<a.first<<":"<<a.second<<" ";cout<<endl;

    printf("Case %d:\n", ++conta);
    for(int i=0; i<q; i++){
        int m, M;
        scanf("%d %d", &m, &M);
        //cout<<m<<" "<<M<<endl;
        for(auto a : v){
            if(a.second >= m && a.second <= M){
                printf("%d\n", a.first);
                break;
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--) solve();
    
    return 0;
}
