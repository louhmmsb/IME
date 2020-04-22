#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    ll n, tant, tat;
    double vant, vat, soma = 0;
    cin>>n;
    cin>>tat>>vat;
    for(int i=1; i<n; i++){
        tant = tat;
        vant = vat;
        cin>>tat>>vat;
        soma += (double)(tat-tant)/1000.0*(vat+vant)/2;
    }
    printf("%.5lf\n", soma);
    return 0;
}
