#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

vector<int> printa;

int resolve(vector<int> v, int size){
    if(size == 0){
        return 0;
    }
    else if(size == 1){
        printa.push_back(v[0]);
        return v[0];
    }
    else if(size == 2){
        printa.push_back(v[0]);
        printa.push_back(v[1]);
        return v[1];
    }
    else if(size == 3){
        printa.push_back(v[0]);
        printa.push_back(v[1]);
        printa.push_back(v[0]);
        printa.push_back(v[0]);
        printa.push_back(v[2]);
        return v[0]+v[1]+v[2];
    }
    else{
        if(2*v[1]>v[0]+v[size-2]){
            printa.push_back(v[0]);
            printa.push_back(v[size-2]);
            printa.push_back(v[0]);
            printa.push_back(v[0]);
            printa.push_back(v[size-1]);
            printa.push_back(v[0]);
            return 2*v[0]+v[size-2]+v[size-1] + resolve(v, size-2);
        }
        else{
            printa.push_back(v[0]);
            printa.push_back(v[1]);
            printa.push_back(v[0]);
            printa.push_back(v[size-2]);
            printa.push_back(v[size-1]);
            printa.push_back(v[1]);
            return 2*v[1]+v[0]+v[size-1] + resolve(v, size-2);
        }
    }
}

int main(){
    int resp, n, q;
    bool printa2;
    cin>>q;
    for(int j=0; j<q; j++){
        printa.clear();
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        resp = resolve(v, v.size());
        cout<<resp<<endl;
        printa2 = true;
        //for(auto i:printa) cout<<i<<" ";
        //cout<<endl;
        if(printa.size() == 1) printf("%d\n", v[0]);
        else{
            for(int i=0; i<printa.size(); i++){
                if(printa2 == true){
                    printf("%d ", printa[i]);
                    i++;
                    printf("%d\n", printa[i]);
                    printa2 = false;
                }
                else{
                    printf("%d\n", printa[i]);
                    printa2 = true;
                }
            }
        }
        if(j != q-1)
            cout<<endl;
    }
    return 0;
}
