#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

bool comp(pair<int, int> a, pair<int, int> b){

    if (a.first < b.first)  return true;
    else if(a.first == b.first) return (a.second > b.second);
    else return false;
    
}

int main(){

    ll s, n, x, y;

    vector<pair<int, int> > v;

    cin>>s>>n;

    for(int i=0; i<n; i++){

        cin>>x>>y;

        v.push_back(make_pair(x, y));
        
    }

    sort(v.begin(), v.end(), comp);

    for(int i=0; i<n; i++){

        if(s>v[i].first) s += v[i].second;

        else {

            cout<<"NO\n";
            return 0;
            
        }
        
    }

    cout<<"YES\n";
    return 0;
    
}
