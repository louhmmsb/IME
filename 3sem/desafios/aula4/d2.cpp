#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    long long int n, i, min[312345], max[312345], maxmin=-1, minmax=1000000010, infi, supi, max2=-1, min2=1000000010, supi2, infi2;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>min[i]>>max[i];
    }
    for(i=0; i<n; i++){
        if(min[i]>maxmin){
            maxmin = min[i];
            infi = i;
        }
        if(max[i]<minmax){
            minmax = max[i];
            supi = i;
        }
    }
    for(i=0; i<n; i++){
        if(min[i]>max2 && i!=infi){
            max2 = min[i];
            infi2 = i;
        }
        if(max[i]<min2 && i!=supi){
            min2 = max[i];
            supi2 = i;
        }
    }
    if(maxmin>minmax){
        cout<<"0";
        return 0;
    }
    if(supi2==infi2) cout<<abs(min2-max2)<<endl;
    else if(abs(maxmin-max2)>abs(minmax-min2)) cout<<abs(minmax-max2)<<endl;
    else cout<<abs(maxmin-min2)<<endl;
    return 0;
}
