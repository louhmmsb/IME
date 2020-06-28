#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    queue<int> q1, q2;
    int n, k1, k2;
    cin>>n;

    cin>>k1;
    
    for(int i=0; i<k1; i++){
        int aux;
        cin>>aux;
        q1.push(aux);
    }
    
    cin>>k2;
    for(int i=0; i<k2; i++){
        int aux;
        cin>>aux;
        q2.push(aux);
    }

    int i=0;
    while(!q1.empty() && !q2.empty() && i++<=1000){
        int a = q1.front();
        int b = q2.front();
        q1.pop();
        q2.pop();
        if(a > b){
            q1.push(b);
            q1.push(a);
        }
        else{
            q2.push(a);
            q2.push(b);
        }
    }
    if(q1.empty()) cout<<i<<" "<<"2"<<endl;
    else if(q2.empty()) cout<<i<<" "<<"1"<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
