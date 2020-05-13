#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb push_back;

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 4002;

int s[MAX];

int n, r1, r2, r3, a, b, c;

void solve(int n){
    for(int i=0; i<=n; i++){
        if (i<a) s[i] = -1;
        else{
            if(i-c >= 0) s[i] = max(1+s[i-c], max(1+s[i-b], 1+s[i-a]));
            else if(i-b >= 0) s[i] = max(1+s[i-b], 1+s[i-a]);
            else s[i] = 1+s[i-a];
        }
        if(s[i] == 0) s[i] = -1;
        if((i == a || i == b || i == c) && s[i] == -1) s[i] = 1;  
    }

}

int main(){
    
    si(n);si(r1);si(r2);si(r3);

    a = min(min(r1, r2), r3);
    c = max(max(r1, r2), r3);
    b = r1+r2+r3-a-c;
    
    solve(n);

    pi(s[n]);
    return 0;
    
}
