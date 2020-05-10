#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 4002;
class triple{
  public:
    int i, j, k, r;
};

int main(){
    int n, a, b, c, x=0, y=0, z=0;
    si(n);si(x);si(y);si(z);

    c = max(max(x, y), z);
    a = min(min(x, y), z);
    b = x+y+z-a-c;
    triple resp;
    resp.i = 0;
    resp.j = 0;
    resp.k = 0;
    resp.r = n;
    while(resp.r != 0){
        if(resp.r%a != 0){
            if(resp.r%b != 0 && (resp.r-b)%a != 0) resp.k++;
            else resp.j++;
        }
        else resp.i++;
        resp.r = n - (resp.i*a+resp.j*b+resp.k*c);
    }
    pi(resp.i+resp.j+resp.k);
    return 0;
}
