#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int v[1234567];

vector<int> corte(vector<int> v){
    int a[100007];
    memset(a, 0, sizeof(a));

    for(auto i : v) a[i]++;

    vector<int> resp(v.size());

    for(int i=1; i<=100005; i++) a[i] = a[i]+a[i-1];
    
    for(auto i : v){
        resp[a[i]-1] = i;
        a[i]--;
    }

    return resp;
}

int fibo(int n){
    if(v[n] != -1) return v[n];
    v[n] = (fibo(n-1)+fibo(n-2))%100000;
    return v[n];
}

void solve(){
    int a, b;
    static int caso = 0;
    vector<int> printa;
    cin>>a>>b;

    //b = min(b, 99);
    cout<<"Case "<<++caso<<": ";
    for(int i=a; i<=a+b; i++){
        printa.pb(fibo(i));
    }
    //cout<<'\n';
    //cout<<"Antes = ";
    //for(auto a : printa) cout<<a<<" ";cout<<endl;
    printa = corte(printa);
    //cout<<"Depois = ";
    //for(auto a : printa) cout<<a<<" ";cout<<endl;
    b = min(b, 99);
    for(int i=0; i<=b; i++) cout<<printa[i]<<" ";
    cout<<'\n';
}

int main(){
    int t;
    
    memset(v, -1, sizeof(v));
    v[0] = 0;
    v[1] = 0;
    v[2] = 1;
    
    cin>>t;
    while(t--) solve();

    return 0;
}
