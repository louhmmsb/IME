#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int jooj[107];

int main(){
    int n, k;
    string s;
    cin>>n>>k;
    memset(jooj, 0, sizeof(jooj));
    for(int i=0; i<n; i++){
        cin>>s;
        jooj[s.size()]++;
    }
    cin>>s;

    int time = 0;
    for(int i=0; i<s.size(); i++){
        time+=jooj[i];
    }

    int aux = time%k;
    time = time+1+5*(time/k);
    cout<<time<<" ";

    cout<<time + 5*((jooj[s.size()]+aux-1)/k) + jooj[s.size()] - 1<<endl;
    
    return 0;
}
