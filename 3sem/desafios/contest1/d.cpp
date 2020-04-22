#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

class dl{
  public:
    ll n;
    ll index;
    ll remainder;
    bool operator<(dl const &a) const{
        return remainder<a.remainder;
    }
    bool operator>(dl const &a) const{
        return remainder>a.remainder;
    }
    bool operator==(dl const &a) const{
        return remainder==a.remainder;
    }
    friend ostream& operator<<(ostream &out, dl &a){
        out<<a.remainder;
        return out;
    }
};

bool byIndex(dl a, dl b){
    return a.index<b.index;
}

int main(){
    ll n, m, aux, ans = 0;
    map<ll, ll> count;
    vector<dl> v;
    dl reader;
    cin>>n>>m;
    for(ll i=0; i<n; i++){
        cin>>reader.n;
        reader.remainder = reader.n%m;
        reader.index = i;
        v.push_back(reader);
    }
    //for(auto a:v) cout<<a<<" ";
    //cout<<endl;
    sort(v.begin(), v.end());
    //for(auto a:v) cout<<a<<" ";
    //cout<<endl;
    for(reader.remainder=0; reader.remainder<m; reader.remainder++){
        auto upper = upper_bound(v.begin(), v.end(), reader);
        auto lower = lower_bound(v.begin(), v.end(), reader);
        aux = (long long int)(upper-lower);
        count[reader.remainder] = aux;
        //cout<<reader.remainder<<": "<<upper-v.begin()<<endl;
        if(aux>n/m){
            for(int j=1; j<(aux-n/m)+1; j++){
                //cout<<reader.remainder<<": "<<upper-v.begin()-j<<endl;
                v[upper-v.begin()-j].remainder++;
                v[upper-v.begin()-j].remainder = (v[upper-v.begin()-j].remainder)%m;
                v[upper-v.begin()-j].n++;
                ans++;
                //for(auto a:v) cout<<a<<" ";
                //cout<<endl;
            }
        }
        //for(auto a:v) cout<<a<<" ";
        //cout<<endl;
    }
    sort(v.begin(),v.end(), byIndex);
    //for(auto a:v) cout<<a<<" ";
    //cout<<endl;
    //cout<<"COUNT: ";
    //for(auto a:count) cout<<a<<" ";
    //cout<<endl;
    cout<<ans<<endl;
    for(int a=0; a<v.size(); a++){
        cout<<v[a].n<<" ";
    }
    cout<<endl;
    return 0;
}
