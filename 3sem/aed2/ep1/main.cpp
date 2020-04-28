#include "st.h"

int att(int antigo, int novo){

    return ++antigo;
    
}

#include "V.h"
#include "BST.h"
#include "TREAP.h"
#include "BRT.h"
#include "A23.h"
#include "HASH.h"
#include <wchar.h>

using namespace std;

void testa(st<string, int> *a, string nomedoarquivo);

wstring parser(wstring s){

    if(s.back() == '!' || s.back() == '?' || s.back() == ';' || s.back() == ':' || s.back() == '.' || s.back() == ',') s.pop_back();

    for(unsigned int i = 0; i<s.size(); i++){

        s[i] = towlower(s[i]);
        
    }

    return s;
    
}


int main(int argc, char** argv){

    srand(0);

    if(argc != 3){

        cout<<"Para usar a tabela passe o nome do arrquivo de texto, e depois passe alguma das seguintes opções: \n";
        cout<<"Para vetor desordenado use: VD\n";
        cout<<"Para vetor ordenado use: VO\n";
        cout<<"Para lista ligada desordenado use: LD\n";
        cout<<"Para lista ligada ordenada use: LO\n";
        cout<<"Para Árvore. de Busca Binária use: AB\n";
        cout<<"Para Treap use: TR\n";
        cout<<"Para Árvore 2-3 use: A23\n";
        cout<<"Para Rubro Negra use: RN\n";
        cout<<"Para hash table use: HS\n";
        return 0;
        
    }

    string arg1 = "", arg2 = "";

    int i = 0;
    char c;
    while((c = argv[1][i]) != '\0'){

        arg1.push_back(c);
        i++;
        
    }

    i = 0;
    while((c = argv[2][i]) != '\0'){

        arg2.push_back(c);
        i++;
        
    }

    st<string, int> *ST = nullptr;

    if(arg2 == "VD") ST = new VD<string, int>();
    else if(arg2 == "VO")ST = new VO<string, int>();
    else if(arg2 == "LD")ST = new LD<string, int>();
    else if(arg2 == "LO")ST = new LO<string, int>();
    else if(arg2 == "AB")ST = new BST<string, int>();
    else if(arg2 == "TR")ST = new TREAP<string, int>();
    else if(arg2 == "A23")ST = new A23<string, int>();
    else if(arg2 == "RN")ST = new BRT<string, int>();
    else if(arg2 == "HS")ST = new HASH<string, int>();
    else {

        cout<<"Passe uma opção válida D:\n";
        return 0;
        
    }
    
    testa(ST, arg1);

    while(true){

        string opc, args;
        int argi;

        cout.flush();
        cout<<"O que você quer fazer?\n";
        cout.flush();
        cin>>opc;

        if(opc == "insere"){
            
            cin>>args;
            ST->insere(args, 1);
            
        }

        else if(opc == "devolve"){

            cin>>args;
            cout<<ST->devolve(args)<<endl;
            
        }

        else if(opc == "remove"){

            cin>>args;
            ST->remove(args);
            
        }

        else if(opc == "rank"){

            cin>>args;
            cout<<ST->rank(args)<<endl;
            
            
        }

        else if(opc == "seleciona"){

            cin>>argi;
            cout<<ST->seleciona(argi)<<endl;
            
        }

        else cout<<"Digite uma opção válida\n";
        
        
    }
    
    delete ST;
    return 0;
    
}

void testa(st<string, int> *a, string nomedoarquivo){

    int n=0;
    string s;
    ifstream arq(nomedoarquivo);

    while(arq>>s){

        cout<<s<<" ";
        n++;
        a->insere(s, 1);
        
    }
    
    cout<<endl;

    arq.close();
    arq.open(nomedoarquivo);
    while(arq>>s){

        int r = a->rank(s);
        cout<<"Rank "<<r<<" -> "<<a->seleciona(r)<<": "<<a->devolve(s)<<'\n';
        
    }

    arq.close();
    arq.open(nomedoarquivo);
    while(arq>>s){
        
        cout<<"Removendo "<<s<<endl;
        a->remove(s);
        cout<<a->devolve(s)<<endl;
        cout<<"Acabei de remover "<<s<<endl;
        
    }
    
}
