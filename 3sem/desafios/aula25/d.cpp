#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

vector<int> rangers;
int conta[1012345];

vector<int> corte(vector<int> v, int mex){
    memset(conta, 0, (mex+2)*sizeof(int));
    for(int a : v) conta[a]++;

    for(int i=1; i<mex+2; i++) conta[i] += conta[i-1];
                                                
    vector<int> resp(v.size());
    for(auto a : v){
        resp[--conta[a]] = a;
    }
    return resp;
}

vector<int> merge(vector<int> a, vector<int> b){
    int i=0, j=0;
    vector<int> resp;
    while(i<a.size() && j<b.size()){
        if(a[i] == -1){
            i++;
            continue;
        }
        if(b[j] == -1){
            j++;
            continue;
        }
        if(a[i] < b[j]) resp.pb(a[i++]);
        else resp.pb(b[j++]);
    }
    if(i == a.size()){
        while(j < b.size()){
            if(b[j] != -1)resp.pb(b[j]);
            j++;
        }
    }
    else{
        while(i < a.size()){
            if(a[i] != -1)resp.pb(a[i]);
            i++;
        }
    }
    return resp;
}

int main(){
    int n, k, x, mex = 0;
    cin>>n>>k>>x;

    for(int i=0; i<n; i++){
        int aux; cin>>aux;
        rangers.pb(aux);
        if(aux > mex) mex = aux;
    }

    rangers = corte(rangers, mex);
    vector<int> aux;
    int j=0;
    for(int i=0; i<k; i++){
        aux.clear();
        mex = 0;
        j=0;
        
        for(j=0; j<rangers.size(); j++){
            if(!(j & 1)){
                rangers[j] = rangers[j]^x;
                aux.pb(rangers[j]);
                if(rangers[j] > mex) mex = rangers[j];
                rangers[j] = -1;
            }
        }
        //cout<<aux.size()<<endl;
        aux = corte(aux, mex);
        //for(auto a : rangers) cout<<a<<" "; cout<<endl;
        //cout<<"ANTES: "<<rangers.size()<<endl;
        rangers = merge(rangers, aux);
        //cout<<"DEPOIS: "<<rangers.size()<<endl;
        //for(auto a : rangers) cout<<a<<" "; cout<<endl;
    }

    //cout<<endl<<endl;

    sort(rangers.begin(), rangers.end());

    cout<<rangers.back()<<" "<<rangers[0]<<'\n';
    return 0;
}
