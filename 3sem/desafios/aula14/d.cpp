#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

struct coisa{

    ll ini, fim, index;

    coisa(ll i=0, ll f=0, ll ind=0){

        ini = i;
        fim = f;
        index = ind;
        
    }

    bool operator<(const coisa &t) const{

        if(ini < t.ini) return true;
        else if(ini == t.ini) return (fim > t.fim);
        return false;
        
    }
    
};

int main(){

    ll n, m;
    map<int, int> onde;
    vector<coisa> v;
    
    cin>>n>>m;

    for(ll i=1; i<=n; i++){
        
        ll x, y;
        cin>>x>>y;
        if(onde.find(x) != onde.end()){

            if(v[onde[x]].fim < y){

                v[onde[x]].fim = y;
                v[onde[x]].index = i;
                
            }
            
        }

        else {
                
            v.push_back(coisa(x, y, i));
            onde[x] = v.size() - 1;
                
        }
        
    }

    sort(v.begin(), v.end());
    if(v[0].ini != 1){

        cout<<"NO"<<'\n';
        return 0;
        
    }

    // for(auto y : v){

    //     cout<<y.ini<<"-"<<y.fim<<" Index: "<<y.index<<endl;
        
    // }
    
    vector<ll> resp;
    bool deu = false;
    resp.push_back(0);

    if(v[0].fim == m){

        cout<<"YES\n1\n"<<v[0].index<<'\n';
        return 0;
        
    }
    
    for(ll i=1; i<v.size(); i++){

        ll max = 0, maxIndex;
        ll j;

        deu = false;
        for(j=i; j<v.size() && v[j].ini<=v[resp[resp.size()-1]].fim+1; j++){

            if(v[j].fim > max){

                deu = true;
                max = v[j].fim;
                maxIndex = j;
                
            }

        }

        if(!deu){

            break;
            
        }
        
        i = j-1;
        resp.push_back(maxIndex);

        if(v[resp[resp.size()-1]].fim == m) break;
        
    }

    if(!deu || v[resp[resp.size()-1]].fim != m){

        cout<<"NO\n";
        return 0;
        
    }
        
    cout<<"YES\n"<<resp.size()<<'\n';
    for(auto i : resp) cout<<v[i].index<<' ';
    cout<<'\n';
    return 0;
    
}
