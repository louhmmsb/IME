#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

string s;
ll n, k;

ll solve(char c){
    ll i, j, count, r;
    i = j = count = r = 0;

    while(i < n){
        while(j < n && (count < k || s[j] != c)){
            if(s[j] == c){
                count++;
            }
            j++;
        }
        
        if(s[i] == c) count--;
        if(r < (j-i)) r = j-i;
        i++;
    }

    return r;
}

int main(){
    cin>>n>>k;
    cin>>s;

    cout<<max(solve('a'), solve('b'))<<endl;

    return 0;
}
