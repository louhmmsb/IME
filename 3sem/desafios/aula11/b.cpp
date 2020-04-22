#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

class plate{

  public:
    int x;
    int y;
    int r;
    int operator-(plate &a){

        return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
        
    }
    bool operator==(plate &a){

        return (x == a.x && y == a.y && r == a.r);
        
    }
    void operator=(plate &a){

        x = a.x;
        y = a.y;
        r = a.r;
        
    }
    
};

int main(){
    vector<plate> v;
    int q;
    char a;
    plate p;
    bool deu;
    cin>>q;
    for(int i=0; i<q; i++){

        cin>>a;
        cin>>p.x>>p.y>>p.r;
        deu = false;
        
        if(a == 'R'){

            for(int j=0; j<v.size(); j++){

                if(p == v[j]){

                    v[j] = v[v.size()-1];
                    v.pop_back();
                    deu = true;
                    break;
                    
                }
                
            }
            
            if(deu == true) cout<<"Ok"<<endl;
            else cout<<"No"<<endl;
            
        }

        if(a == 'A'){

            deu = true;

            if(p.x>1000 || p.x<0 || p.y>1000 || p.y<0){

                deu = false;
                    
            }

            for(int j=0; j<v.size() && deu == true; j++){
                
                if(v[j]-p < (v[j].r+p.r)*(v[j].r+p.r)){

                    deu = false;
                    break;
                    
                }
                
            }

            if(deu == true){
                
                cout<<"Ok"<<endl;
                v.push_back(p);

            }
            
            else cout<<"No"<<endl;
            
        }

    }

    return 0;
    
}
