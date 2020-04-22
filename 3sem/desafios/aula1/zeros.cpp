#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, zeros = 0, tot = 0, j, i, ans[100];
    cin>>n;
    for(i=0; i<n; i++){
	cin>>s;
	j=0;
	while(j<s.size()){
	    if (s[j]=='1'){
		j++;
		while (s[j]=='0'){
		    zeros++;
		    j++;
		}
		if(j<=s.size() && s[j]=='1') tot+=zeros;
		zeros = 0;
	    }
	    else j++;
	}
	ans[i]=tot;
	tot = 0;
    }
    for(i=0; i<n; i++) cout<<ans[i]<<endl;
    return 0;
}
