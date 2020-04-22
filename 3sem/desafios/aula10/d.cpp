#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;


int tabuleiro[27123];
int l, r, c, start;
queue<int> q;


void bfs(int ini, int end){
    
    if(ini-r*c >= 0){

        if(tabuleiro[ini-r*c] > tabuleiro[ini]+1 || tabuleiro[ini-r*c] == 0 && ini-r*c != start){

            tabuleiro[ini-r*c] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini-r*c], end);
            q.push(ini-r*c);

        }
        
    }

    if(ini+r*c <= l*r*c - 1){

        if(tabuleiro[ini+r*c] > tabuleiro[ini]+1 || tabuleiro[ini+r*c] == 0 && ini+r*c != start){

            tabuleiro[ini+r*c] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini+r*c], end);
            q.push(ini+r*c);

        }
            
    }

    if(ini-c >= 0 && ini/(r*c) == (ini-c)/(r*c)){

        if(tabuleiro[ini-c] > tabuleiro[ini]+1 || tabuleiro[ini-c] == 0 && ini-c != start){

            tabuleiro[ini-c] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini-c], end);
            q.push(ini-c);

        }
        
    }

    if(ini+c <= l*r*c - 1 && ini/(r*c) == (ini+c)/(r*c)){

        if(tabuleiro[ini+c] > tabuleiro[ini]+1 || tabuleiro[ini+c] == 0 && ini+c != start){

            tabuleiro[ini+c] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini+c], end);
            q.push(ini+c);

        }
        
    }

    if(ini-1 >= 0 && ini/c == (ini-1)/c){

        if(tabuleiro[ini-1] > tabuleiro[ini]+1 || tabuleiro[ini-1] == 0 && ini-1 != start){

            tabuleiro[ini-1] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini-1], end);
            q.push(ini-1);

        }
        
    }

    if(ini+1 <= l*r*c - 1 && ini/c == (ini+1)/c){

        if(tabuleiro[ini+1] > tabuleiro[ini]+1 || tabuleiro[ini+1] == 0 && ini+1 != start){

            tabuleiro[ini+1] = tabuleiro[ini]+1;
            //bfs(tabuleiro[ini+1], end);
            q.push(ini+1);

        }
            
    }

    
    if(!q.empty()){

        int aux = q.front();
        q.pop();
        bfs(aux, end);
        
    }
    
    
}


int main(){

    int ini, fim;
    char p;

    while(1){

        memset(tabuleiro, 0, sizeof(tabuleiro));
        cin>>l>>r>>c;
        //cout<<l<<r<<c<<endl;

        if(l == 0) break;
        
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    
                    while((p = getchar()) == '\n');
                    if(p == '#') tabuleiro[i*r*c + j*c + k] = -1;
                    else if(p == 'S') ini = i*r*c + j*c + k;
                    else if(p == 'E') fim = i*r*c + j*c + k;
                    //cout<<i*r*c+j*c+k<<": "<<p<<endl;
                
                }
            }
            
        }

        start = ini;
        bfs(ini, fim);

        /*
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    cout<<setw(2)<<tabuleiro[i*r*c+j*c+k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        */
        
        if(tabuleiro[fim] == 0)cout<<"Trapped!"<<endl;
        else cout<<"Escaped in "<<tabuleiro[fim]<<" minute(s)."<<endl;

    }
    
    return 0;
    
}
