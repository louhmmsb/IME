#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

bool ja[50];
bool outroja[50];

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> v[20];
    for(int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        ja[a] = true;
        ja[b] = true;
        for(auto j:v[a]){
            v[j].push_back(b);
            v[b].push_back(j);
            if(v[j].size()>2){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        v[a].push_back(b);
        if(v[a].size()>2){
            cout<<"-1"<<endl;
            return 0;
        }
        for(auto j:v[b]){
            v[j].push_back(a);
            v[a].push_back(j);
            if(v[j].size()>2){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        v[b].push_back(a);
        if(v[b].size()>2){
            cout<<"-1"<<endl;
            return 0;
        }
        //
        for(int i=1; i<=n; i++){
            cout<<"Time do "<<i<<": ";
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        //
    }
    for(int i=0; i<n; i++){
        int j;
        if(ja[i] == false){
            for(j=0; v[j].size() == 3; j++);
        }
        v[j].push_back(i);
    }
    for(int i=1; i<=n; i++){
        if(outroja[i] == false){
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j]<<" ";
                outroja[j] = true;
            }
            cout<<endl;
        }
    }
    return 0;
}
