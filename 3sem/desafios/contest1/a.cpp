#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    int n, k, i, aux, j, cont = 0;;
    vector<int> v;
    cin>>n>>k;
    for(i=0; i<n; i++){
        cin>>aux;
        v.push_back(aux);
    }
    //for(i=0; i<n; i++){
    //    cout<<v[i]<<" ";
    //}
    //cout<<endl;
    for(i=0, j=n-1; i<=j;){
        if(k>=v[i]){
            i++;
            cont++;
            continue;
        }
        else if(k>=v[j]){
            j--;
            cont++;
            continue;
        }
        else {
            break;
        }
    }
    cout<<cont<<endl;
    return 0;
}
