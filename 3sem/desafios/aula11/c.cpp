#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int swapcount = 0;

void bubblesort(vector<int> &v, int n){

    if(n < 1) return;
    
    for(int i=0; i<n-1; i++){

        if(v[i]>v[i+1]){
            
            int aux;
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            swapcount++;
            
        }
        
    }

    bubblesort(v, n-1);
    
}

int main(){

    vector<int> v;
    int n, aux;

    while(1){

        v.clear();
        
        if(scanf("%d", &n) == EOF) break;
        
        for(int i=0; i<n; i++){

            cin>>aux;
            v.push_back(aux);
        
        }

        bubblesort(v, v.size());

        //for(auto x:v) cout<<x<<" ";
        //cout<<endl;

        cout<<"Minimum exchange operations : "<<swapcount<<endl;
        swapcount = 0;
        
    }
    
    return 0;
    
}
