#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(0);

    for(int i=0; i<n-1; i++){
        int aux;
        cin>>aux;

        v.push_back(aux);
    }

    int a, b, sum = 0;
    cin>>a>>b;
    for(int i=a; i<b; i++){
        sum+=v[i];
    }

    cout<<sum<<endl;
    return 0;
}
