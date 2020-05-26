#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

void solve(){
    string s;
    cin>>s;
    bool bob = true;
    vector<char> v;
    for(int i=0; s[i]; i++){
        char aux = s[i];
        if(bob == false) continue;
        if(aux == '[' || aux == '{' || aux == '(') v.pb(aux);
        else if(aux == ']'){
            if(v.empty() || v.back() != '[') cout<<"NO\n", bob = false;
            else v.pop_back();
        }
        else if(aux == '}'){
            if(v.empty() || v.back() != '{') cout<<"NO\n", bob = false;
            else v.pop_back();
        }
        else if(aux == ')'){
            if(v.empty() || v.back() != '(') cout<<"NO\n", bob = false;
            else v.pop_back();
        }
    }
    
    if(bob == true){
        if(v.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main(){
    int n;
    cin>>n;
    //char aux = getchar();

    while(n--) solve();

    return 0;
}
