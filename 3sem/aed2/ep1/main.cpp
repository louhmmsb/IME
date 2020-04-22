#include "st.h"

int att(int antigo, int novo){

    return ++antigo;
    
}

#include "V.h"
#include "LL.h"
#include "BST.h"
#include "TREAP.h"

using namespace std;

void testa(st<string, int> *a);


int main(){

    srand(0);
    st<string, int> *a = new TREAP<string, int>();
    testa(a);
    //a->show();
    delete a;
    return 0;
    
}

void testa(st<string, int> *a){

    int n=0;
    string s;
    ifstream arq("teste.txt");

    while(arq>>s){

        cout<<s<<" ";
        n++;
        a->insere(s, 1);
        
    }
    
    cout<<endl;

    arq.close();
    arq.open("teste.txt");
    while(arq>>s){

        int r = a->rank(s);
        cout<<"Rank "<<r<<" -> "<<a->seleciona(r)<<": "<<a->devolve(s)<<'\n';
        
    }
    
}
