#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int tab[1000005];

queue<int> q;
queue<int> p;
queue<int> casasant; 

int main(){

    int n, m, ini, end;

    char aux;
    
    cin>>n>>m;

    int dir[2] = {1, m};

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin>>aux;

            if(aux == '*') tab[i*m+j] = -1;

            if(aux == '.') tab[i*m+j] = 0;

            else if(aux == 'S') ini = i*m+j;

            else if(aux == 'T') end = i*m+j;

        }
        
    }

    int atual, dirant = 0, casaant;

    tab[ini] = 1;
    tab[end] = -2;

    q.push(ini);
    p.push(0);
    casasant.push(-1);
    
    while(!q.empty()){

        atual = q.front();
        dirant = p.front();
        casaant = casasant.front();
        q.pop();
        p.pop();
        casasant.pop();
        if(atual == end && tab[end] <= 3){

            cout<<"YES"<<'\n';
            return 0;
            
        }
        //cout<<"TAMANHO ="<<q.size()<<endl;

        for(int i=0; i<2; i++){

            if(atual - dir[i] >= 0 && tab[atual - dir[i]] != -1 && (m == 1 || dir[i] != 1 || atual%m != 0)){

                if(atual - dir[i] != casaant && (tab[atual - dir[i]] <= 0 || (dirant != dir[i] && dirant != 0 && tab[atual]+1 <= tab[atual - dir[i]]) || (dirant == dir[i] && tab[atual] < tab[atual - dir[i]]))){

                    if(dirant != dir[i] && dirant != 0)
                        tab[atual - dir[i]] = tab[atual] + 1;
                    else
                        tab[atual - dir[i]] = tab[atual];
                    
                    q.push(atual - dir[i]);
                    p.push(dir[i]);
                    casasant.push(atual);
                    
                }
                
            }

            if(atual + dir[i] <= m*n-1 && tab[atual + dir[i]] != -1 && (m == 1 || dir[i] != 1 || atual%m != m-1)){

                if(atual + dir[i] != casaant && (tab[atual + dir[i]] <= 0 || (dirant != dir[i] && dirant != 0 && tab[atual]+1 <= tab[atual + dir[i]]) || (dirant == dir[i] && tab[atual] < tab[atual + dir[i]]))){

                    if(dirant != dir[i] && dirant != 0)
                        tab[atual + dir[i]] = tab[atual] + 1;
                    else
                        tab[atual + dir[i]] = tab[atual];
                    
                    q.push(atual + dir[i]);
                    p.push(dir[i]);
                    casasant.push(atual);
                    
                }
                
            }

        }

        //cout<<q.front()<<" "<<p.front()<<endl;
        
    }
    
    // for(int i=0; i<n; i++){
        
    //     for(int j=0; j<m; j++){

    //         cout<<setw(2)<<tab[i*m+j]<<" ";
            
    //     }

    //     cout<<endl;
        
    // }
    
    if(tab[end] <= 3 && tab[end] != -2){

        cout<<"YES"<<'\n';
        return 0;
        
    }
    
    cout<<"NO"<<'\n';
    return 0;
    
}
