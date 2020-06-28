#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 200005;

int n, m, cur, iden[MAX];

struct node{
    int pai, sz, id, activeSz;
    ll sum;
    node(int ID = 0, int PAI = 0, ll SZ = 0, int SUM = 0, int ACTIVESZ = 0){
        pai = PAI;
        sz = SZ;
        sum = SUM;
        id = ID;
        activeSz = ACTIVESZ;
    }
};

node v[MAX];

int raiz(node &n){
    if (n.pai == n.id) return n.id;
    return n.pai = raiz(v[n.pai]);
}

void une(int a, int b){
    int raizA = raiz(v[a]);
    int raizB = raiz(v[b]);

    if (v[raizA].id == v[raizB].id) return;
    if(v[raizB].sz > v[raizA].sz) swap(raizA, raizB);

    v[raizB].pai = v[raizA].id;
    v[raizA].sz += v[raizB].sz;
    v[raizA].sum += v[raizB].sum;
    v[raizA].activeSz += v[raizB].activeSz;
}

void move(int a, int b, int num){
    int raizA = raiz(v[a]);
    int raizB = raiz(v[b]);

    if(v[raizA].id == v[raizB].id) return;
    v[raizA].sum -= num;
    v[raizA].activeSz--;

    iden[num] = cur;
    v[cur] = node(cur, v[raizB].id, 1, num, 1);
    v[raizB].sum += num;
    v[raizB].sz++;
    v[raizB].activeSz++;
    cur++;
}

int main(){
    while(scanf("%d %d", &n, &m) == 2){
        cur = n+1;
        for(int i=1; i<=n; i++){
            v[i] = node(i, i, 1, i, 1);
            iden[i] = i;
        }

        for(int i=0; i<m; i++){
            int op, p, q;
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %d", &p, &q);
                une(iden[p], iden[q]);
            }
            else if(op == 2){
                scanf("%d %d", &p, &q);
                move(iden[p], iden[q], p);                
            }
            else if(op == 3){
                scanf("%d", &p);
                int r = raiz(v[iden[p]]);
                printf("%d %lld\n",  v[r].activeSz, v[r].sum);
            }
        }
        memset(v, 0, sizeof(v));
        memset(iden, 0, sizeof(iden));
    }
    return 0;
}
