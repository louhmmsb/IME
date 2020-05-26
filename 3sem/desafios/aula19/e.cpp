#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 1000;

struct triple{
    int w, s, i;

    triple(){}
    
    triple(int nI, int nW, int nS){
        i = nI;w = nW; s = nS;
    }

    bool operator <(triple a){
        if(w != a.w) return w<a.w;
        return a.s>s;
    }
};



int l[MAX], p[MAX];
triple v[MAX];

void imp(int s){
    if(p[s]!=-1)
        imp(p[s]);
    printf("%d\n", v[s].i);
}

int solve(int n){
    int j=0, i=0, s=0, x=0;
    
    for(i=0; i<n; i++){
        l[i]=1;
        p[i]=-1;
    }
    for(i=0; i<n; i++){
        for(j = i-1; j>=0; j--){
            if(v[i].s < v[j].s && v[i].w != v[j].w && l[i] < l[j]+1){
                l[i] = l[j]+1;
                p[i] = j;
            }
        }
    }

    for(i=0; i<n; i++){
        if(l[i]>s) s = l[i], x = i;
    }
    printf("%d\n", s);
    imp(x);

    return 0;
}

int main(){
    
    int a, b, n=0;
    for(; (scanf("%d %d", &a, &b)!=EOF); n++){
        v[n].w = a;
        v[n].s = b;
        v[n].i = n+1;
    }

    sort(v, v+n);

    solve(n);
    
    return 0;
}
