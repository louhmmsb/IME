#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 200001;

int c[MAX];
int t[MAX];
int cores[MAX];
map<int, int> vals;
vector<int> adj[MAX];

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        cin>>cores[i];
        c[i] = i;
        t[i] = 1;
        adj[i].push_back(i);
    }
    for(int i=0; i<m; i++){
        int l, r;
        cin>>l>>r;

        int cl = c[l], cr=c[r];

        if(cl != cr){
            if(t[cl]>=t[cr]){
                t[cl]+=t[cr];
                for(auto a : adj[cr]){
                    adj[cl].push_back(a);
                    c[a] = c[l];
                }
            }
            else if(t[cr]>t[cl]){
                t[cr]+=t[cl];
                for(auto a : adj[cl]){
                    adj[cr].push_back(a);
                    c[a] = c[r];
                }
            }
        }
    }

    int resp = 0;
    for(int i=1; i<=n; i++){
        int x = c[i];
        if(x!=i) continue;

        int max_c = 1;
        int ant = 0;
        int j = 0;
        vals.clear();
        while(j<adj[x].size()){
            ant = ++vals[cores[adj[x][j]]];
            max_c = (ant>max_c)? ant : max_c;
            //vals[cores[adj[x][j]]] = ant;
            j++;
        }
        resp +=((adj[x].size()) - max_c);
    }

    cout<<resp<<'\n';
    return 0;
}
