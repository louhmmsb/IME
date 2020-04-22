#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
    int h, l;
    vector<int> v;
    char c;
    bool trocou = true;
    cin>>h>>l;
    for(int i=0; i<h*l; i++){
        cin>>c;
        switch(c){
        case 'N':
            v.push_back(i-l);
            break;
        case 'S':
            v.push_back(i+l);
            break;
        case 'W':
            v.push_back(i-1);
            break;
        case 'E':
            v.push_back(i+1);
            break;
        default:
            break;
        }
    }
    /*for(int i=0; i<l*h; i++){
        printf("%2d ",v[i]);
        }*/
    //cout<<endl;
    for(int i=0; i<h*l && trocou == true; i++){
        trocou = false;
        for(int j=0; j<h*l; j++){
            if(v[j] != v[v[j]]){
                trocou = true;
                v[j] = v[v[j]];
            }
            //printf("%2d ", v[j]);
        }
        //cout<<endl;
    }
    sort(v.begin(), v.end());
    //cout<<"SORT"<<endl;
    /*for(int i=0; i<l*h; i++){
        printf("%2d ",v[i]);
        }*/
    int cont = 1;
    for(int i=1; i<l*h; i++){
        if(v[i] != v[i-1]) cont++;
    }
    //cout<<endl;
    cout<<cont<<endl;
    return 0;
}
