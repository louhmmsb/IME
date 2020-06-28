#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    int v, k;
    cin>>v>>k;
    vector<pair<int, int> > adj[v+100];
    int dist[v+100];

    memset(dist, 0x3f3f3f3f, sizeof(dist));

    for(int i=0; i<k; i++){
        int a, b, c;
        cin>>a>>b>>c;
        
        adj[a].pb(mp(b, c));   
    }
    int ini, end;
    cin>>ini>>end;

    set<pair<int, int> > q;

    dist[ini] = 0;
    q.insert(mp(ini, 0));

    while(!q.empty()){
        int at = q.begin()->first;
        q.erase(q.begin());

        for(auto a : adj[at]){
            if(dist[at] + a.second < dist[a.first]){
                if(q.find(mp(a.first, dist[a.first])) != q.end())
                    q.erase(mp(a.first, dist[a.first]));
                dist[a.first] = dist[at] + a.second;
                q.insert(mp(a.first, dist[a.first]));
            }
        }
        
    }
    if(dist[end] != 0x3f3f3f3f)cout<<dist[end];
    else cout<<"NO";
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    
    while(t--) solve();

    return 0;
}
