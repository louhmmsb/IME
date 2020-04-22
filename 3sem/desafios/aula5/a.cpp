#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int n, k, i, j, v[123];
    vector<long long int> ans, ans2;
    cin>>n>>k;
    for(i=0; i<n; i++){
        cin>>v[i];
    }
    for(i=0; i<n; i++){
        if(find(ans2.begin(), ans2.end(), v[i])==ans2.end()){
            ans.push_back(i+1);
            ans2.push_back(v[i]);
        }
    }
    if(ans.size()<k) cout<<"NO";
    else {
        cout<<"YES"<<endl;
        for(i=0; i<k; i++){
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
