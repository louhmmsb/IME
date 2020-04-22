#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

class dl{
  public:
    ll soma;
    ll seq;
    ll el;
    ll index;
    bool operator<(dl &b){
        return soma<b.soma;
    }
};



int main(){
    ll k, n, soma[212345];
    vector<dl> m;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>n;
        soma[i]=0;
        for(int j=0; j<n; j++){
            dl a;
            cin>>a.el;
            a.seq = i;
            a.index = j;
            soma[i] += a.el;
            m.push_back(a);
        }
    }
    for(int i=0; i<m.size(); i++){
        m[i].soma = soma[m[i].seq]-m[i].el;
    }
    sort(m.begin(), m.end());
    for(int i=1; i<m.size(); i++){
        if(m[i].soma == m[i-1].soma && m[i].seq != m[i-1].seq){
            cout<<"YES"<<endl;
            cout<<m[i].seq+1<<" "<<m[i].index+1<<endl;
            cout<<m[i-1].seq+1<<" "<<m[i-1].index+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
