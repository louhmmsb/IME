#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

vector<int> v;

int main(){
    int n, m;
    si(n);si(m);

    for(int i=0; i<m; i++){
        int aux;
        si(aux);
        v.pb(aux);
    }

    sort(v.begin(), v.end());

    int mm = 0x3f3f3f3f;
    for(int i=0; i+n-1 < v.size(); i++){
        int aux = v[i+n-1]-v[i];
        mm = min(mm, aux);
    }

    pi(mm);
    return 0;
}
