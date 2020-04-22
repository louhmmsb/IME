#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    int n, k, j;
    string s;
    cin>>n>>k;
    cin>>s;
    for(j=1; j<s.size(); j++){
        int a = 0;
        int b = j;
        if(s[a] == s[b]){
            while(s[a] == s[b] && b<s.size()){
                a++;
                b++;
            }
            if(b == s.size()){
                break;
            }
        }
    }
    for(int i = 0; i<k-1; i++){
        cout<<s.substr(0, j);
    }
    cout<<s<<endl;
    return 0;
}
