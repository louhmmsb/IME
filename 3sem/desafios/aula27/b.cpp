#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

char tab[1123][1123];
int moves[1123][1123][2];
int hDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int vDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int code[] = {7, 4, 1, 8, 2, 9, 6, 3};

int n, m;

bool inside(pair<int, int> a, int i){
    return (tab[a.first+vDir[i]][a.second+hDir[i]] != 'X' && a.first+vDir[i]>=0 && a.first+vDir[i]<n && a.second+hDir[i]>=0 && a.second+hDir[i]<m);
}

void solve(){
    pair<int, int> ini, end;
    scanf("%d %d\n", &n, &m);
    
    for(int i=0; i<n; i++){
        fgets(tab[i], 1123, stdin);
        for(int j=0; j<m; j++){
            moves[i][j][0] = 0;
            moves[i][j][1] = 0;
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
    queue<pair<int, int> > q;
    int pDir;
    q.push(ini);
    moves[ini.first][ini.second][0] = 1;
    moves[ini.first][ini.second][1] = 0xff;
    
    while(!q.empty()){
        pair<int, int> at = q.front();
        q.pop();
        if(at.first == end.first && at.second == end.second){
            printf("%d\n", ((moves[end.first][end.second][0])));
            return;
        }
        for(int i=0; i<8; i++){
            int vir = 0;
            if(!(moves[at.first][at.second][1] & (1<<i))){
                vir++;
                moves[at.first][at.second][1] |= (1<<i);
            }
            pair<int, int> n = at;
            while(inside(n, i)){
                pair<int, int> jooj;
                jooj.first = n.first + vDir[i];
                jooj.second = n.second + hDir[i];
                if(moves[jooj.first][jooj.second][1] & (1<<i)) break;
                if(moves[jooj.first][jooj.second][1] != 0){
                    moves[jooj.first][jooj.second][1] |= (1<<i);
                    n = jooj;
                    continue;
                }
                else{
                    q.push(jooj);
                    moves[jooj.first][jooj.second][1] |= (1<<i);
                    moves[jooj.first][jooj.second][0] = moves[at.first][at.second][0] + vir;
                    n = jooj;
                    if(jooj.first == end.first && jooj.second == end.second){
                        printf("%d\n", ((moves[end.first][end.second][0])));
                        return;
                    }
                    continue;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<moves[i][j][1]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"----------------------------"<<endl;
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}
