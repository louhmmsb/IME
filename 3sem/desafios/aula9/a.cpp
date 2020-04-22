#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

char tab[512][512];

int main(){
    int r, c;
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>tab[i][j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(tab[i][j] == '.'){
                tab[i][j] = 'D';
                continue;
            }
            if(tab[i][j] ==  'W'){
                if(i != 0 && tab[i-1][j] == 'S'){
                    cout<<"No"<<endl;
                    return 0;
                }
                if(i != r-1 && tab[i+1][j] == 'S'){
                    cout<<"No"<<endl;
                    return 0;
                }
                if(j != 0 && tab[i][j-1] == 'S'){
                    cout<<"No"<<endl;
                    return 0;
                }
                if(i != c-1 && tab[i][j+1] == 'S'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<tab[i][j];
        }
        cout<<endl;
    }
    return 0;
}
