#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    string s;
    bool sussu = false;

    while(cin>>s){

        if(s == "Sussu" || s == "Sussu." || s == "Sussu!"){

            sussu = true;
            
        }

        if(s[s.size()-1] == '?'){

            cout<<"7"<<endl;
            return 0;
            
        }

        else if(s[s.size()-1] == '.' || s[s.size()-1] == '!'){

            if(sussu == true) cout<<"AI SUSSU!"<<endl;
            else cout<<"O cara é bom!"<<endl;
            return 0;
            
        }
        
    }
    
}
