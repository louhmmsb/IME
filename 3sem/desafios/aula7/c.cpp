#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

class level{
  public:
    int pack;
    int ammo;
    int enemies;
    level(int p=0, int e=0, int a=0){
        pack = p;
        enemies = e;
        ammo = a;
    }
    bool operator<(level const &a) const{
        if(pack!=a.pack) return pack>a.pack;
        else if(enemies!=a.enemies) return enemies<a.enemies;
        else return ammo>a.ammo;
    }
    int index;
};


int main(){
    int n;
    level aux;
    cin>>n;
    vector<level> v(n);
    for(int i=0; i<n; i++){
        cin>>aux.pack;
        cin>>aux.enemies;
        cin>>aux.ammo;
        aux.index = i+1;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    if(n==1) cout<<"Easiest and Hardest is level 1";
    else{
        cout<<"Easiest is level "<<v[0].index<<endl;
        cout<<"Hardest is level "<<v[n-1].index<<endl;
    }
    return 0;
}
