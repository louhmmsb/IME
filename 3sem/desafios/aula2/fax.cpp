#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    string s;
    ull k, n;
    cin>>s>>k;
    n = s.size();
    n = n/k;
    if(s.size()%k!=0){
	cout<<"NO";
	return 0;
    }
    for(int i=0; i<k; i++){
	int a = (i*n)+n-1;
	for(int j=(i*n); j<a && j<=a; j++){
	    if (s[j] != s[a]){
		cout<<"NO"<<endl;
		return 0;

	    }
	    else a--;
	}
    }
    cout<<"YES"<<endl;
    return 0;
}
