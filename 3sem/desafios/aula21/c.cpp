#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

struct frac{
    ll num, den;
    frac(ll _num = 0, ll _den = 0): num(_num), den(_den){}
    frac operator+(const frac& a){
        frac res;
        res.num = num + a.num;
        res.den = den + a.den;
        return res;
    }
    bool  operator==(const frac& a) const{
        return (num == a.num && den == a.den);
    }
    void operator=(const frac& a){
        num = a.num;
        den = a.den;
    }
    bool operator<(const frac& a) const{
        return (num*a.den < den*a.num);
    }
    bool operator>(const frac& a) const{
        return (num*a.den > den*a.num);
    }
};

frac esq(0, 1), dir(1, 0), meio(1, 1);

int main(){
    ll a, b;
    while((scanf("%lld %lld", &a, &b) != EOF)){
        string resp = "";
        meio = {1, 1};
        esq = {0, 1};
        dir = {1, 0};
        while(1){
            frac x(a, b);
            if(x == frac(1, 1)) return 0;
            if(meio < x){
                esq = meio;
                meio = meio+dir;
                resp+='R';
            }
            else if(meio > x){
                dir = meio;
                meio = meio+esq;
                resp+='L';
            }
            else if(meio == x){
                break;
            }
        }
        cout<<resp<<endl;
    }
    return 0;
}
