#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;


int main(){
    int n, aux;
    vector<int> v;
    string t;
    cin>>n>>t;
    for(int i=1; i<=n; i++){
        if(n%i==0) v.push_back(i);
    }
    for(int i=1; i<v.size(); i++){
        aux = v[i]-1;
        for(int j=0; j<v[i]/2; j++, aux--){
            swap(t[j], t[aux]);
        }
        //cout<<t<<endl;
    }
    cout<<t<<endl;
    return 0;
}



//10
//rocesfedoc
//rocesfedoc
//orcesfedoc
//secrofedoc
//codeforces


