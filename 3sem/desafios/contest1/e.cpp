#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll inversions = 0;

void sort(vector<ll> &v);

void mergeSort(vector<ll> &esq, vector<ll> &dir, vector<ll> &v);



int main(){
    ll t, n, aux;
    vector<ll> ans;
    cin>>t;
    for(ll i=0; i<t; i++){
        cin>>n;
        vector<ll> v;
        for(int j=0; j<n; j++){
            cin>>aux;
            v.push_back(aux);
        }
        sort(v);
        //for(int i=0; i<n; i++){
            //cout<<v[i]<<" ";
            //}
        //cout<<endl;
        ans.push_back(inversions);
        inversions = 0;
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}



void sort(vector<ll> &v){
    if(v.size() <= 1) return;
    vector<ll> esq, dir;
    ll i;
    for(i=0; i<v.size()/2; i++){
        esq.push_back(v[i]);
    }
    for(; i<v.size(); i++){
        dir.push_back(v[i]);
    }
    sort(esq);
    sort(dir);
    mergeSort(esq, dir, v);
}

void mergeSort(vector<ll> &esq, vector<ll> &dir, vector<ll> &v){
    ll i=0, j=0, n = 0;
    while(i<esq.size() && j<dir.size()){
        if(esq[i]<=dir[j]){
            v[n++]=esq[i];
            i++;
        }
        else {
            v[n++]=dir[j];
            j++;
            inversions+=esq.size()-i;
        }
    }
    while(i<esq.size()){
        v[n++] = esq[i];
        i++;
    }
    while(j<dir.size()){
        v[n++] = dir[j];
        j++;
    }
}
