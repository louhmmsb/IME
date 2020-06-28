#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

deque<deque<int> > qissocara;
vector<pair<int, int> >  adj[507];
set<int> pais[507];
bool vis[507];
int dist[507];

int n, m;

struct comp{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

void djikstra(int ini, int end){
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp > pq;

    for(int i=0; i<n; i++){
        dist[i] = 0x3f3f3f3f;
        vis[i] = false;
        pais[i].clear();
    }
    
    dist[ini] = 0;
    pq.push(mp(ini, 0));

    while(!pq.empty()){
        int at = pq.top().first;
        pq.pop();
        vis[at] = true;
        
        for(auto a : adj[at]){
            int d, p, polones;
            d = a.first;
            p = a.second;
            polones = dist[at]+p;

            if(!vis[d] && dist[d] >= polones){
                if(dist[d] > polones){
                    pais[d].clear();
                    pais[d].insert(at);
                }
                else{
                    pais[d].insert(at);
                }
                dist[d] = polones;
                pq.push(mp(d, polones));
            }
        }
    }
}

void aOutra(int ini, int end, deque<int> &trajeto){
    trajeto.push_front(ini);
    if(ini == end){
        qissocara.pb(trajeto);
        trajeto.erase(trajeto.begin(), trajeto.end() - 1);
        return;
    }
    for(auto a : pais[ini]){
        aOutra(a, end, trajeto);
    }
}

void dfs(int ini, int end){
    qissocara.clear();
    deque<int> trajeto;

    aOutra(ini, end, trajeto);
}

void hakai(){
    for(int i = 0; i < qissocara.size(); i++){
        for(int j = 0; j < qissocara[i].size()-1; j++){
            int um = qissocara[i][j], dois = qissocara[i][j+1];
            for(auto it = adj[um].begin(); it != adj[um].end(); it++){
                if(it->first == dois) {adj[um].erase(it); break;}                
            }
        }
    }
}

void solve(){
    for(int i=0; i<=n+3; i++){
        adj[i].clear();
    }
    int s, d;
    cin>>s>>d;
    
    for(int i=0; i<m; i++){
        int u, v, p;
        cin>>u>>v>>p;
        adj[u].pb(mp(v, p));
    }
    
    djikstra(s, d);
    dfs(d, s);
    hakai();
    djikstra(s, d);

    cout<<((dist[d] == 0x3f3f3f3f)? -1 : dist[d])<<'\n';    
}

int main(){
    while(cin>>n>>m){
        if(n == 0 && m == 0) return 0;
        solve();
    }
}
