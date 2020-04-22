#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    int n, cont, max=0;
    string s, part, partmax;
    cin>>n>>s;
    for(int i=0; i<n-1; i++){
        cont = 0;
        part = s.substr(i, 2);
        for(int j=0; j<n-1; j++){
            if(part==s.substr(j, 2)){
                cont ++;
            }
        }
        if(cont>max){
            max = cont;
            partmax = part;
        }
    }
    cout<<partmax<<endl;
    return 0;
}
