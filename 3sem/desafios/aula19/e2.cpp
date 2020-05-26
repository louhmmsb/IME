#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

class triple{
  public:
    int index, peso, qi;

    triple(int nIndex, int nPeso, int nQi){
        index = nIndex; peso = nPeso; qi = nQi;
    }

    bool operator <(triple a){
        if(peso != a.peso) return (peso<a.peso);
        else return qi>a.qi;
    }
};

int main(){
    int pAux, qiAux, n = 0;
    vector<triple> v;

    while((scanf("%d %d", &pAux, &qiAux))!=EOF){
        triple aux(++n, pAux, qiAux);
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    //for(auto a : v) cout<<a.peso<<" "<<a.qi<<" "<<a.index<<endl;

    int dp[n+10], print[n+10], resp = 0, beto;

    for(int i = n-1; i>=0; i--){
        dp[i] = 1;
        print[i] = -1;
        for(int j=i+1; j<n; j++){
            if(v[i].peso<v[j].peso && v[i].qi>v[j].qi && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                print[i]=j;
            }
        }
        if(dp[i]>resp){
            resp = dp[i];
            beto = i;
        }
    }
    printf("%d\n", resp);
    for(int i=beto; i!=-1; i=print[i])
        printf("%d\n", v[i].index);

    return 0;
    
}
