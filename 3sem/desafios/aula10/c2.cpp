#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;


vector<vector<int> > q1;
vector<vector<int> > q2;
vector<vector<int> > q3;
vector<int> adj[50];
vector<bool> visitado(50);


int dfs(int i, vector<int> &aux){
    visitado[i] = true;
    aux.push_back(i);
    int retorno = 1;
    for(auto a:adj[i]){
        if(visitado[a] == false){
            retorno += dfs(a, aux);
        }
    }
    return retorno;
}


int main(){
    int n, m;
    cin>>n>>m;
    if(m == 0){
        for(int i=0, j=1; i<n/3; i++){
            cout<<j++<<" "<<j++<<" "<<j++<<endl;
        }
        return 0;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        int a;
        vector<int> times;
        if(visitado[i] == false){
            a = dfs(i, times);
            if(times.size()>3){
                cout<<"-1"<<endl;
                return 0;
            }
            if(times.size() == 3){
                //cout<<"Tripla: "<<times[0]<<" "<<times[1]<<" "<<times[2]<<endl;
                q3.push_back(times);
            }
            if(times.size() == 2){
                //cout<<"Duplinha: "<<times[0]<<" "<<times[1]<<endl;
                q2.push_back(times);
            }
            if(times.size() == 1){
                //cout<<"Simples: "<<times[0]<<endl;
                q1.push_back(times);
            }
        }
    }
    //for(int i=0; i<q1.size(); i++){
    //cout<<q1[i][0]<<" ";
    //}
    //cout<<endl;
    if(q2.size() > q1.size()){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0; i<q2.size(); i++){
        q2[i].push_back(q1[q1.size()-1][0]);
        q1.pop_back();
        q3.push_back(q2[i]);
    }
    if(q1.size()%3 != 0){
        cout<<"-1"<<endl;
        return 0;
    }
    else{
        for(int i=0; i<q3.size(); i++){
            cout<<q3[i][0]<<" "<<q3[i][1]<<" "<<q3[i][2]<<endl;
        }
        for(int i=0; i<q1.size();){
            cout<<q1[i++][0]<<" "<<q1[i++][0]<<" "<<q1[i++][0]<<endl;
        }
    }
    return 0;
}
