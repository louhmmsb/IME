#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

string remove(string str, long long int k){
    if(str.size()<=1) return "";
    char c = 97;
    long long int found, ind=0;
    for(c, k; k>0; c++){
        found = str.find(c, ind);
        if(found!=string::npos){
            ind = found;
            str[found] = 40;
            //str.erase(str.begin()+found);
            c=96;
            k--;
        }
        else {
            ind = 0;
            continue;
        };
    }
    return str;
}

int main(){
    long long int n, k;
    string str;
    scanf("%lld%lld", &n, &k);
    cin>>str;
    str = remove(str, k);
    for(int i=0; i<str.size(); i++){
        if(str[i]!=40) cout<<str[i];
    }
    cout<<endl;
    //cout<<str<<endl;
    return 0;
}

