#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int count = 0, resultado, size;
    cin>>s;
    size = s.size();
    for(int i=0; i<s.size(); i++){
	if(s[i]=='a') count++;
    }
    resultado = count+min(count-1,size-count);
    cout<< resultado<<endl;
    return 0;
}
