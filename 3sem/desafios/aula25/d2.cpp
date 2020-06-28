#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 1 << 10;
int count[2][MAXC];

int main(){
    memset(count, 0, sizeof(count));
    
    int n, k, x;
    si(n);si(k);si(x);

    for(int i=0, aux; i<n; i++){
        cin>>aux;
        count[0][aux]++;
    }
    for(int i=0, sas=0; i<k; i++, sas=0){
        for(int j=0; j<MAX; j++){
            count[!(i & 1)][j^x] = count[i & 1][j]/2;
            count[!(i & 1)][j^0] = count[i & 1][j]/2;        
            (count[(i & 1)][j] & 1)? (sas & 1? (count[!(i & 1)][j]++) : (c[!(i & 1)])): (count[!(i & 1)][j^((sas & 1)*x)]++);
            sas += count[(i & 1)][j];
            count[(i & 1)][j] = 0;
        }
    }
    int joao, zezinho;
    
    for(int i = MAX-1; i >= 0; i--)
        (count[k & 1][i] ? {zezinho = i; break;} : (){continue;});
    
    cout<<
    
    return 0;
}
