#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

bool myFunction(string a, string b){
    if(a.size()>=b.size()) return false;
    if(b.find(a)!=std::string::npos) return true;
    else return false;
}

int main(){
    long long int n, i, ndeu=0;
    vector<string> a;
    cin>>n;
    for(i=0; i<n; i++){
        string temp;
        //cout<<temp.capacity()<<endl;
        cin>>temp;
        //cout<<temp.capacity()<<endl;
        a.push_back(temp);
    }
    //fprintf(stderr, "errou?\n");
    sort(a.begin(), a.end(), myFunction);
    //cout<<"B";
    for(i=1; i<a.size(); i++){
        if(a[i].find(a[i-1])==std::string::npos){
            cout<<"NO"<<endl;
            ndeu=1;
            break;
        }
    }
    if(ndeu==0)cout<<"YES"<<endl;
    for(i=0; i<a.size() && ndeu==0; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
