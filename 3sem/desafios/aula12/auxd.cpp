#include <bits/stdc++.h>


using namespace std;


int main(){

    cout<<"{2, ";
    
    for(int i=3; i<1000; i+=2){

        bool aux = true;

        for(int j=2; j<(int)(sqrt(i)+1); j++){

            if(i%j == 0){

                aux = false;
                break;
                
            }
            
        }

        if(aux) cout<<i<<", ";
        
    }

    cout<<" }";
    return 0;
    
}
