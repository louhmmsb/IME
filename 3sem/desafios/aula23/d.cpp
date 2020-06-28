#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int v, e;
    si(v);si(e);
    vector<set<int> > adj(v+1);
    for(int i=0; i<e; i++){
        int a1 ,a2;
        si(a1);si(a2);
        adj[a1].insert(a2);
        adj[a2].insert(a1);
    }
    vector<int> grupo(v+1, -1);

    for(int g=0; g<3; g++){
        int p;
        for(p=1; p<=v; p++) if(grupo[p] == -1) break;
        if(p == v+1){cout<<"-1"<<endl; return 0;}

        grupo[p] = g;
        for(int s = 1; s<=v; s++) if(grupo[s] == -1 && adj[p].find(s) == adj[p].end()) grupo[s] = g;
    }

    vector<vector<int> > grupos(3);
    for(int i=1; i<=v; i++){
        if(grupo[i] == -1){cout<<"-1"<<endl; return 0;}
        else grupos[grupo[i]].pb(i);
    }
    int n = 0;
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            for(int v1 : grupos[i]){
                for(int v2 : grupos[j]){
                    if(adj[v1].find(v2) == adj[v1].end()){cout<<"-1"<<endl; return 0;}
                    else n++;
                }
            }
        }
    }
    if(n != e){cout<<"-1"<<endl; return 0;}
    for(int i=1; i<=v; i++)cout<<grupo[i]+1<<" ";
    cout<<endl;
    return 0;
}
