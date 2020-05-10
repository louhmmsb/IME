#include<bits/stdc++.h>

#define ci(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int n, x, y, z, r=0, i=0, j=0, k=0;
    ci(n);ci(x);ci(y);ci(z);

    int a, b, c;
    a = min(min(x, y), z);
    c = max(max(x, y), z);
    b = x+y+z-a-c;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(n%a == 0){pi(n/a);return 0;}
    for(i=0; k*a+j*b+i*c<=n; i++){
        for(j=0; k*a+j*b+i*c<=n; j++){
            for(k=0; k*a+j*b+i*c<=n; k++){
                if(k*a+j*b+i*c==n) r = max(i+k+j, r);
            }
            if(k*a+j*b+i*c==n) r = max(i+k+j, r);
            k=0;
            if(a == b) break;
        }
        if(k*a+j*b+i*c==n) r = max(i+k+j, r);
        j=0;
        k=0;
        if(b == c) break;
    }

    pi(r);
    return 0;
}
