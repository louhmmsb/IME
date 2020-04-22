#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

const int N=212345;

long long int digits(long long int x){
    long long int a=0;
    if(x==0) return 1;
    for(; x!=0; x/=10, a++);
    return a;
}

int powers[11];
int size[N];

int main(){
    long long int i, j, n, k, aux, points=0, d, v[N], aux2;
    vector<long long int> m[11];
    cin>>n>>k;
    powers[0] = 1;
    for(i=0; i<10; i++) powers[i+1] = powers[i]*10%k;
    for(i=0; i<n; i++){
        cin>>v[i];
        d=digits(v[i]);
        m[d].push_back(v[i]%k);
    }
    for(i=0; i<10; i++){
        sort(m[i].begin(), m[i].end());
    }
    //for(i=0; i<11; i++){
    //      cout<<"POWERS["<<i<<"]="<<powers[i]<<endl;
    //  for(j=0; j<m[i].size(); j++){
    //      cout<<m[i][j]<<" ";
    //  }
    //  cout<<endl;
    //}
    for(i=0; i<n; i++){
        for(j=1; j<11; j++){
            aux2 = (v[i]*powers[j])%k;
            //cout<<aux2<<endl;
            aux = (k-aux2)%k;
            points+=(upper_bound(m[j].begin(), m[j].end(), aux)-lower_bound(m[j].begin(), m[j].end(), aux));
            if(digits(v[i])==j && (aux2+v[i]%k)%k==0) points--;
        }
    }
    cout<<points<<endl;
    return 0;
}
