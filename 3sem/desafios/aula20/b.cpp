#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(ll n){
    ll resp = 0, i = 0, a;

    while(true){
        if(n == resp){
            break;
        }
        n = resp+n;
        resp = 0;
        a = n;
        while(a!=0){
            resp = resp*10+(a%10);
            a/=10;
        }
        i++;
        //cout<<n<<" "<<resp<<endl;
    }
    cout<<i-1<<" "<<resp<<endl;
}

int main(){
    int x;
    si(x);
    while(x--){
        ll aux;
        scanf("%lli", &aux);
        solve(aux);
    }
    return 0;
}
