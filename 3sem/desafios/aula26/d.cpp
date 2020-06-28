#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 200007;

int pais[MAX], cont[MAX], soma[MAX];

void start(int n){
    for(int i=1, j=n+1; i<=n; i++, j++){
        pais[i] = j;
        pais[j] = j;
        cont[j] = 1;
        soma[j] = i;
    }
}

int find(int x){
    if(pais[x] == x) return x;
    return pais[x] = find(pais[x]);
}

void une(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        cont[y] += cont[x];
        soma[y] += soma[x];
        pais[x] = y;
    }
}

void move(int x, int y){
    int raizx = find(x);
    int raizy = find(y);

    if(raizx != raizy){
        cont[raizy]++;
        cont[raizx]--;
        soma[raizy] += x;
        soma[raizx] -= x;
        pais[x] = raizy;
    }
}

int main(){
    int n, m, c, x, y;
    while(cin>>n>>m){
        start(n);
        for(int i=0; i<m; i++){
            cin>>c;
            if(c == 1){
                cin>>x>>y;
                une(x, y);
            }
            else if(c == 2){
                cin>>x>>y;
                move(x, y);
            }
            else{
                cin>>x;
                cout<<cont[find(x)]<<" "<<soma[find(x)]<<'\n';
            }
        }
    }
    return 0;
}
