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
            if(q[i][j] == 0){
                loops++;
                q[i][j] = loops;
            }
            if(i>0 && m[i-1][j]=='S') q[i-1][j] = q[i][j];
            if(i<h-1 && m[i+1][j]=='N') q[i+1][j] = q[i][j];
            if(j>0 && m[i][j-1]=='E') q[i][j-1] = q[i][j];
            if(j<l-1 && m[i][j+1]=='W') q[i][j+1] = q[i][j];
            if(m[i][j]=='N') q[i-1][j] = q[i][j];
            else if(m[i][j]=='S') q[i+1][j] = q[i][j];
            else if(m[i][j]=='W') q[i][j-1] = q[i][j];
            else if(m[i][j]=='E') q[i][j+1] = q[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            if(m[i][j]=='N' && q[i-1][j] != q[i][j]);
            else if(m[i][j]=='S' && q[i+1][j] != q[i][j]) loops--;
            else if(m[i][j]=='W' && q[i][j-1] != q[i][j]) loops--;
            else if(m[i][j]=='E' && q[i][j+1] != q[i][j]) loops--;;
        }
    }
    /*for(int i=0; i<h; i++){
        for(int j=0; j<l; j++){
            printf("%2d ", q[i][j]);
        }
        cout<<endl;
        }*/
    cout<<loops<<endl;
    return 0;
}
