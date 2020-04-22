#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 1001;
pair<int, int> fim;
int vx[] = {-1, 0, 1, 0};
int vy[] = {0, -1, 0, 1};
int tab[MAX][MAX];
int n, m;

queue<pair<int, int>> atual, ant;
queue<int> viradas, dir;

bool dentro(pair<int, int> casa){

    return(casa.first >= 0 && casa.first < n && casa.second >= 0 && casa.second < m);
    
}

int main(){
    cin>>n>>m;
    char c;
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin>>c;
            if(c == '.') tab[i][j] = 0;
            else if(c == '*') tab[i][j] = -1;
            else if(c == 'S'){

                tab[i][j] = 1;
                atual.push(make_pair(i, j));
                ant.push(make_pair(i, j));
                viradas.push(1);
                dir.push(0);
                
            }

            else{

                tab[i][j] = 0;
                fim = make_pair(i, j);
                
            }
            
        }
        
    }

    bool deu = false;
    pair<int, int> to, vim;
    int vta;
    int dirant;

    while(!atual.empty()){

        to = atual.front();
        vim = ant.front();
        vta = viradas.front();
        dirant = dir.front();
        //cout<<to.first<<" "<<to.second<<endl;
        if(to.first == fim.first && to.second == fim.second && vta <= 3){

            tab[fim.first][fim.second] = vta;
            deu = true;
            break;
            
        }
        
        atual.pop();
        ant.pop();
        viradas.pop();
        dir.pop();

        for(int i=0; i<4; i++){

            bool turn = false;

            pair<int, int> next = make_pair(to.first + vx[i], to.second + vy[i]);
            int nextdir;

            if(vx[i] == 0) nextdir = 10*vy[i];
            else nextdir = vx[i];

            if(dirant*(-1) == nextdir) continue;

            if(dirant != 0 && dirant != nextdir) turn = true;
            if((vta + turn) > 3) continue;

            if(dentro(next) && ((tab[next.first][next.second] > (vta+turn)) || tab[next.first][next.second] == 0)){
            
                tab[next.first][next.second] = vta+turn;
                atual.push(next);
                ant.push(to);
                viradas.push(vta+turn);
                dir.push(nextdir);
            
            }
        
        }

    }

    // for(int i=0; i<n; i++){

    //     for(int j=0; j<m; j++){

    //         cout<<setw(2)<<tab[i][j];
            
    //     }

    //     cout<<'\n';
        
    // }

    if(deu) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
    
}
