#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

string remove(string str){
    if(str.size()<=1) return "";
    char c = 97;
    long long int found;
    for(c; c<=122; c++){
        found = str.find(c);
        if(found!=string::npos){
            str.erase(str.begin()+found);
            break;
        }
        else continue;
    }
    return str;
}

int main(){
    long long int n, k;
    string str;
    cin>>n>>k;
    cin>>str;
    for(long long int i=0; i<k; i++){
        str = remove(str);
    }
    cout<<str<<endl;
    return 0;
}
