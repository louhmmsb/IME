#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

struct tetra{
    int x, y, dir, peso, prov;

    tetra(int X, int Y, int DIR, int nDIR){
        x = X;
        y = Y;
        dir = DIR;
        peso = (DIR != nDIR)? 1 : 0;
    }
    bool operator<(const tetra &a) const{
        if(peso != a.peso) return !(peso < a.peso);
        else if(x != a.x) return (x < a.x);
        else if(y != a.y) return (y < a.y);
        else if(dir != a.dir) return (dir < a.dir);
    }
};

char tab[1123][1123];
int moves[1123][1123];
int hDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int vDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int code[] = {7, 4, 1, 8, 2, 9, 6, 3};

int n, m;

bool inside(pair<int, int> a){
    return (a.first>=0 && a.first<n && a.second>=0 && a.second<m);
}

void solve(){
    pair<int, int> ini, end;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            moves[i][j] = 0x3f3f3f3f;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &tab[i][j]);
            if(tab[i][j] == 'S') ini = mp(i, j);
            else if(tab[i][j] == 'F') end = mp(i, j);
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<tab[i][j]<<" ";   
    //     }
    //     cout<<endl;
    // }
    
    priority_queue<tetra> q;
    tetra a(ini.first, ini.second, 0, 0);
    a.prov = 0;
    q.push(a);
    
    while(!q.empty()){
        tetra at = q.top();
        q.pop();
        if(moves[at.x][at.y] != 0x3f3f3f3f) continue;
        moves[at.x][at.y] = at.prov;
        
        if(at.x == end.first && at.y == end.second) break;
        
        for(int i=0; i<8; i++){
            pair<int, int> n = mp(at.x+vDir[i], at.y+hDir[i]);
            if(inside(n) && tab[n.first][n.second] != 'X'){
                int plus = (at.dir == code[i])? 0 : 1;
                tetra prox(n.first, n.second, code[i], at.dir);
                prox.prov = min(moves[n.first][n.second], moves[at.x][at.y]+plus);
                q.push(prox);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<((moves[i][j] != 0x3f3f3f3f)? moves[i][j] : 9)<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
    printf("%d\n", ((moves[end.first][end.second] != 0x3f3f3f3f)? moves[end.first][end.second] : -1));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}
