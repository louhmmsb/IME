#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, pos, l, r, sec=0;
    bool cr=0, cl=0;
    cin>>n>>pos>>l>>r;
    if (l==1) cl=1;
    if (r==n) cr=1;
    if(pos>=l && pos<=r){
	if(cl==0 && cr==0) sec=min(pos-l+r-l+2, r-pos+r-l+2);
	else if(cl==1 && cr==0) sec=r-pos+1;
	else if(cl==0 && cr==1) sec=pos-l+1;
	else sec=0;
    }
    if(pos<=l && pos<=r){
	if(cl==0 && cr==0) sec=-pos+r+2;
	else if(cl==1 && cr==0) sec=r-pos+1;
	else if(cl==0 && cr==1) sec=l-pos+1;
	else sec=0;
    }
    if(pos>=l && pos>=r){
	if(cl==0 && cr==0) sec=pos-l+2;
	else if(cl==1 && cr==0) sec=pos-r+1;
	else if(cl==0 && cr==1) sec=pos-l+1;
	else sec=0;
    }
    cout<<sec<<endl;
    return 0;
}
