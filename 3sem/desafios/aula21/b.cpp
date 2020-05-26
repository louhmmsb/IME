#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll n, m;
    ll q;

    cin>>n>>m>>q;

    for(int i=0; i<q; i++){
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        int sd = sy*360/n;
        int ed = ey*360/m;

        if(sx == 1 && ex == 1){
            int aux = 360/n;
            if(sd/aux == ed/aux) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(sx == 2 && ex == 2){
            int aux = 360/m;
            if(sd/aux == ed/aux) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int aux = __gcd(n, m);
            aux = 360/aux;

            if(sd/aux == ed/aux) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
