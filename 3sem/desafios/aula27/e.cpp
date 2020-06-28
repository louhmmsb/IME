#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAXN = 101234;
int N;

char bin[MAXN];
unsigned int seg[4*MAXN];
char que[MAXN];

void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = bin[tl] - '0';
    }
    else{
        int tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        seg[v] = 0;
    }
}

void update(int no, int tl, int tr, int l, int r){
    if(l > r) return;
    if(l == tl && r == tr){
        seg[no] ^= 1;
    }
    else{
        int tm = (tl + tr)/2;
        update(no*2, tl, tm, l, min(r, tm));
        update(no*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

unsigned int query(int no, int l, int r, int p){
    if(l == r) return seg[no];
    int m = (l+r)/2;
    if(p <= m) return seg[no] ^ query(no*2, l, m, p);
    else return seg[no] ^ query(no*2+1, m+1, r, p);
}

void solve(){
    static int caso = 0;
    fgets(bin, MAXN, stdin);
    N = strlen(bin) - 1;
    bin[N] = '\0';
    int q;
    scanf("%d\n", &q);
    cout<<"Case "<<++caso<<":\n";
    build(1, 0, N-1);
    while(q--){
        char c;
        int a, b;
        fgets(que, MAXN, stdin);
        if(que[0] == 'Q'){
            sscanf(que, "%c %d", &c, &a);
            printf("%u\n", query(1, 1, N, a));
        }
        else if(que[0] == 'I'){
            sscanf(que, "%c %d %d", &c, &a, &b);
            update(1, 1, N, a, b);
        }
    }
}

int main(){
    int t;
    scanf("%d\n", &t);
    while(t--) solve();

    return 0;
}
