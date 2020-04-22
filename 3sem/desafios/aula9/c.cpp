#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n, max = 1, cont = 1, aux;
    scanf("%d", &n);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        scanf("%d", &v[i]);
    }
    for(int i=1; i<=n; i++){
        cont = 1;
        for(int j=v[i]; j != -1; j = v[j]) cont++;
        if(cont>max) max = cont;
    }
    printf("%d\n", max);
    return 0;
}
