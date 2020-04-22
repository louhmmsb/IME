#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    string t;
    ull n, a=0, cont=0;
    cin>>t;
    for(int i=0; i<t.size(); i++){
	if(t[i]=='a') a++;
    }
    if((t.size()-a)%2!=0){
	cout<<":("<<endl;
	return 0;
    }
    n=(t.size()-a)/2;
    for(int i=0; i<n+a; i++){
	if(t[i]=='a') continue;
	else if(t[i]==t[n+a+cont]){
	    cont++;
	    continue;
	}
	else{
	    cout<<":("<<endl;
	    return 0;
	}
    }
    for(int i=0; i<n+a; i++) cout<<t[i];
    cout<<endl;
    return 0;
}
