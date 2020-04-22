#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

long long int myPow(long long int x, long long int p){
    if(p==0) return 1;
    if(p==1) return x;
    int aux = myPow(x, p/2);
    if(p%2==0) return aux*aux;
    else return x*aux*aux;
}

//long long int myPow2(long long int x, long long int p){
//if(p==0) return 1;
//  if(p==1) return x;
//  if(x/2)
//}

class dlong{
  public:
    long long int digits;
    long long int orig;
    long long int modulado;
    long long int n;
    dlong operator+(const dlong& a){
        dlong result;
        result.modulado = (this->modulado)*myPow((long long int)10, a.digits)+a.modulado;
        //result.modulado = stoi(to_string(this->modulado) + to_string(a.modulado));
        return result;
    }
    dlong(){}
};



long long int digits(long long int x){
    //if(x==0) return 1;
    //long long int a=0;
    //for(; x!=0; x = x/10, a++);
    //return a;
    return ((long long int)log10(x))+1;
}

bool myfunc(dlong a, dlong b){
    if(a.modulado==b.modulado) return (a.digits<b.digits);
    return (a.modulado<b.modulado);
}

dlong v[212345];
dlong w[212345];

int main(){
    long long int n, k, i, j, wtam=0, pontos=0;
    dlong aux;
    cin>>n>>k;
    for(i=0; i<n; i++){
        cin>>(v[i].orig);
        v[i].modulado = (v[i].orig)%k;
        v[i].digits = digits(v[i].orig);
    }
    sort(v, v+n, myfunc);
    //for(i=0; i<n; i++){
    //cout<<v[i].modulado<<" ,d="<<v[i].digits<<endl;
    //}
    //w[0].modulado = v[0].modulado;
    //w[0].digits = v[0].digits;
    //w[0].n = 1;
    //wtam++;
    w[0].modulado = -1;
    j = -1;
    for(i=0; i<n; i++){
        if(w[j].modulado != v[i].modulado || w[j].digits!=v[i].digits){
            j++;
            w[j].modulado=v[i].modulado;
            w[j].digits=v[i].digits;
            w[j].n = 1;
            wtam++;
        }
        else w[j].n++;
    }
    // for(i=0; i<wtam; i++){
    //cout<<w[i].modulado<<" ,n="<<w[i].n<<endl;
    //}
    for(i=0; i<wtam; i++){
        for(j=0; j<wtam; j++){
            if((w[i]+w[j]).modulado%k==0){
                if(i==j) pontos+= w[i].n*(w[i].n-1);
                else pontos+= w[i].n*w[j].n;
            }
        }
    }
    cout<<pontos<<endl;
    return 0;
}
