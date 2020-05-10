#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

set<int> s;

int vxcavalo[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int vycavalo[] = {2, 2, 1, -1, -2, -2, -1, 1};

int main(){
    char ty, tx, cy, cx;
    cin>>ty>>tx>>cy>>cx;

    ty = ty-'a'+1;
    cy = cy-'a'+1;
    tx -='0';
    cx -='0';
    //cout<<(int)ty<<(int)tx<<" "<<(int)cy<<(int)cx<<endl;

    for(int i=0; i<8; i++){
        if(cx + vxcavalo[i] >= 1 && cx + vxcavalo[i] <= 8 && cy + vycavalo[i] >= 1 && cy + vycavalo[i] <= 8){
            s.insert((cy+vycavalo[i])*10+(cx+vxcavalo[i]));
        }
    }

    for(int i=1; i<=8; i++){
        s.insert((i)*10+(tx));
        s.insert((ty)*10+(i));
    }

    for(int i=0; i<8; i++){
        if(tx + vxcavalo[i] >= 1 && tx + vxcavalo[i] <= 8 && ty + vycavalo[i] >= 1 && ty + vycavalo[i] <= 8){
            s.insert((ty+vycavalo[i])*10+(tx+vxcavalo[i]));
        }
    }

    //set<int>::iterator i;for(i = s.begin(); i != s.end(); i++) cout<<*i<<" ";cout<<endl;

    cout<<64-s.size()-1<<endl;

    return 0;
}
