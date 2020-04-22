#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    int l, h, x, y, loops = 0;
    char m[1000][1000];
    int q[1000][1000];
    cin>>h>>l;
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            cin>>m[i][j];
            q[i][j] = 0;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(visitado[i][j] == 0){
                for(x=i, y=j; visitado[x][y] == 0;){
                    visitado[x][y] = true;
                    if(m[x][y]=='N') x--;
                    else if(m[x][y]=='S')x++;
                    else if(m[x][y]=='E')y++;
                    else if(m[x][y]=='W')y--;
                }
                if(x == i && y == j) loops++;
            }
        }
    }
    cout<<loops<<endl;
    return 0;
}
