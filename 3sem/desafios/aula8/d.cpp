#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int keys[112345];
bool visitado[112345];
bool trancado[112345];
bool nafila[112345];
queue<int> q;

bool bfs(int ini, int end, vector<int> chambers[]){
    visitado[ini] = 1;
    if(end == ini) return true;
    if(keys[ini] != 0) trancado[keys[ini]] = false;
    for(auto a:chambers[ini]){
        if(visitado[a] == false && nafila[a] == false){
            q.push(a);
            nafila[a] = true;
        }
    }
    int counter = q.size();
    int aux;
    while(trancado[q.front()] == true && counter){
        aux = q.front();
        q.pop();
        q.push(aux);
        counter--;
    }
    if(counter == 0) return false;
    aux = q.front();
    q.pop();
    return bfs(aux, end, chambers);
}




int main(){
    int n, k, m, aux, index;
    while(1){
        cin>>n>>k>>m;
        if(n == -1) break;
        vector<int> chambers[n+1];
        memset(visitado, 0, sizeof(visitado));
        memset(keys, 0, sizeof(keys));
        memset(trancado, 0, sizeof(trancado));
        memset(nafila, 0, sizeof(nafila));
        while(!q.empty()) q.pop();
        for(int i=0; i<k; i++){
            cin>>index;
            cin>>aux;
            keys[index] = aux;
            trancado[aux] = true;
        }
        for(int i=0; i<m; i++){
            cin>>aux;
            cin>>index;
            chambers[aux].push_back(index);
            chambers[index].push_back(aux);
        }
        if(bfs(1, n, chambers)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}
