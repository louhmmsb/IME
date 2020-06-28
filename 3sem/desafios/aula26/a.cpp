#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int check(int a, int b, int c){
    if(a+b>c && a+c>b && b+c>a) return 1;
    else if(a+b==c || a+c==b || b+c==a) return 0;
    else return -1;
}

int solve(int *lados){
    int a;
    a = check(lados[0], lados[1], lados[2]);
    a = max(check(lados[0], lados[1], lados[3]), a);
    a = max(check(lados[0], lados[2], lados[3]), a);
    a = max(check(lados[1], lados[2], lados[3]), a);
    return a;
}

int main(){
    int lados[4];
    for(int i=0; i<4; i++) cin>>lados[i];

    int a = solve(lados);
    if(a == 1)cout<<"TRIANGLE\n";
    if(a == 0)cout<<"SEGMENT\n";
    if(a == -1)cout<<"IMPOSSIBLE\n";

    return 0;
}
