#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 2000002;

bool visitado[MAX];
int cores[MAX];
vector<int> v[MAX];
int t[MAX];

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    memset(visitado, false, sizeof(visitado));
    for(int i=1; i<=n; i++){
        cin>>cores[i];
    }

    for(int i=1; i<=m; i++){
        int l, r;
        cin>>l>>r;

        v[l].push_back(r);
        v[r].push_back(l);
    }

    int resp = 0;
    for(int i=1; i<=n; i++){
        if(!visitado[i] && v[i].size()>0){
            visitado[i] = true;
            queue<int> q;
            set<int> s;
            q.push(i);
            
            int cont = 0, qnt = 0;

            while(!q.empty()){
                cont++;
                int f = q.front();

                q.pop();

                t[cores[f]]++;

                s.insert(cores[f]);

                qnt = (t[cores[f]]>qnt)? t[cores[f]] : qnt;            
                for(int j=0; j<v[f].size(); j++){
                    if(!visitado[v[f][j]]){
                        q.push(v[f][j]);
                        visitado[v[f][j]] = true;
                    }
                }
            }
            resp+=(cont-qnt);
            for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
                int aux = *it;
                t[aux] = 0;
            }
        }
    }

    cout<<resp<<endl;
    return 0;
}
