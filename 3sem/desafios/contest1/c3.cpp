#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int n, k;
    string s;
    char c = 97;
    cin>>n>>k;
    cin>>s;
    for(c; c<123; c++){
        for(long long int i=0; i<s.size() && k>0; i++){
            if(s[i]==c && k>0){
                s.erase(s.begin()+i);
                i--;
                k--;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
