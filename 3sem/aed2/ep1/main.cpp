#include <ctime>
#include <iomanip>
#include <wchar.h>
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

using namespace std;

void testa(st<wstring, int> *a, string nomedoarquivo);

wstring parser(wstring s){

    if(s.back() == L'!' || s.back() == L'?' || s.back() == L';' || s.back() == L':' || s.back() == L'.' || s.back() == L',') s.pop_back();

    for(unsigned int i = 0; i<s.size(); i++){

        s[i] = towlower(s[i]);
        
    }

    return s;
    
}

st<wstring, int>* setType(string type);

void loadF(st<wstring, int> *ST, string nomeArquivo, bool show, bool testaTempo);

    

    

int main(int argc, char** argv){

    locale localPadrao("");
    setlocale(LC_CTYPE, "");
    
    srand(0);

    if(argc < 3){

        wcout<<"Para usar a tabela passe o nome do arquivo de texto, e depois passe alguma das seguintes opções: \n";
        wcout<<"Para vetor desordenado use: VD\n";
        wcout<<"Para vetor ordenado use: VO\n";
        wcout<<"Para lista ligada desordenado use: LD\n";
        wcout<<"Para lista ligada ordenada use: LO\n";
        wcout<<"Para Árvore. de Busca Binária use: AB\n";
        wcout<<"Para Treap use: TR\n";
        wcout<<"Para Árvore 2-3 use: A23\n";
        wcout<<"Para Rubro Negra use: RN\n";
        wcout<<"Para Hash Table use: HS\n";
        return 0;
        
    }

    string arg1 = "", arg2 = "";
    bool show = false, testaTempo = false, exhaust = false;

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

    if(argc > 3){

        for(int i = 3; i < argc; i++){

            if(argv[i][0] == 's') show = true;
            else if(argv[i][0] == 't') testaTempo = true;
            else if(argv[i][0] == 'e') exhaust = true;
            
        }
        
    }

    st<wstring, int> *ST = nullptr;

    ST = setType(arg2);

    loadF(ST, arg1, show, testaTempo);

    if(exhaust)testa(ST, arg1);

    wcout<<L"\n\n\n\nEntrando na prompt de testes, possíveis ações: \n";
    wcout<<L"insere [chave]\n";
    wcout<<L"devolve [chave]\n";
    wcout<<L"remove [chave]\n";
    wcout<<L"rank [chave]\n";
    wcout<<L"seleciona [rank]\n";
    wcout<<L"clean (limpa a st)\n";
    wcout<<L"q (para sair da promp do jeito correto, sem memory leak)\n\n";

    while(true){

        clock_t tIni, tFim;
        wstring args, opc;
        int argi;

        wcout.flush();
        wcout.flush();
        wcout<<L">>>  ";
        wcout.flush();
        wcout.flush();
        wcin>>opc;

        if(opc == L"insere"){
            
            wcin>>args;
            args = parser(args);
            tIni = clock();
            ST->insere(args, 1);
            tFim = clock();
            wcout<<L"Inserido o "<<args<<L" na tabela.\n";
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"devolve"){

            wcin>>args;
            args = parser(args);
            tIni = clock();
            wcout<<ST->devolve(args)<<endl;
            tFim = clock();
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"remove"){

            wcin>>args;
            args = parser(args);
            tIni = clock();
            ST->remove(args);
            tFim = clock();
            wcout<<L"Removido o "<<args<<L" da tabela.\n";
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"rank"){

            wcin>>args;
            args = parser(args);
            tIni = clock();
            wcout<<ST->rank(args)<<endl;
            tFim = clock();
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"seleciona"){

            wcin>>argi;
            tIni = clock();
            wcout<<ST->seleciona(argi)<<endl;
            tFim = clock();
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"clean"){

            tIni  = clock();
            delete ST;
            ST = setType(arg2);
            tFim = clock();
            wcout<<L"A tabela foi limpa\n";
            if(testaTempo) wcout<<L"A operação demorou "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
            
        }

        else if(opc == L"q"){

            break;
            
        }

        else {

            wcout<<L"Digite uma opção válida\n";
            wchar_t c;
            while((c = getwchar()) != L'\n');

        }
        
    }
    
    delete ST;
    return 0;
    
}


//funções auxiliares

//função para testar os empos médios da st
void testa(st<wstring, int> *ST, string nomeArquivo){

    locale localPadrao("");
    setlocale(LC_CTYPE, "");
    double tot = 0;
    int n = 0;
    wstring s;
    wifstream arq(nomeArquivo);
    arq.imbue(localPadrao);
    clock_t tIni, tFim;

    //testando devolve
    wcout<<L"\n--------------------------------------------------------------------------------\nTESTANDO O DEVOLVE\n";
    tIni = clock();
    
    while(arq>>s){

        s = parser(s);
        ST->devolve(s);
        n++;
        
    }
    
    tFim = clock();
    tot = (double)(tFim - tIni)/CLOCKS_PER_SEC;
    
    wcout<<L"Tempo total para devolver todas as chaves foi de "<<setw(20)<<tot<<'\n';
    wcout<<L"Tempo médio para devolver cada chave foi de "<<setw(25)<<tot/n<<'\n';

    arq.close();
    arq.open(nomeArquivo);

    //testando rank
    wcout<<L"--------------------------------------------------------------------------------\nTESTANDO O RANK\n";
    tIni = clock();
    
    while(arq>>s){

        s = parser(s);
        ST->rank(s);
        
    }
    
    tFim = clock();
    tot = (double)(tFim - tIni)/CLOCKS_PER_SEC;
    
    wcout<<L"Tempo total para rankear todas as chaves foi de "<<setw(21)<<tot<<'\n';
    wcout<<L"Tempo médio para rankear cada chave foi de "<<setw(26)<<tot/n<<'\n';

    //testando seleciona
    wcout<<L"--------------------------------------------------------------------------------\nTESTANDO O SELECIONA\n";
    tIni = clock();

    int aux = 0;
    while((ST->seleciona(aux++)) != L"")
    
    tFim = clock();
    tot = (double)(tFim - tIni)/CLOCKS_PER_SEC;
    
    wcout<<L"Tempo total para selecionar todas as chaves foi de "<<setw(18)<<tot<<'\n';
    wcout<<L"Tempo médio para selecionar cada chave foi de "<<setw(23)<<tot/aux<<'\n';

    arq.close();
    arq.open(nomeArquivo);

    //testando remove
    wcout<<L"--------------------------------------------------------------------------------\nTESTANDO O REMOVE\n";
    tIni = clock();
    
    while(arq>>s){

        s = parser(s);
        ST->remove(s);
        
    }
    
    tFim = clock();
    tot = (double)(tFim - tIni)/CLOCKS_PER_SEC;
    
    wcout<<L"Tempo total para remover todas as chaves foi de "<<setw(21)<<tot<<'\n';
    wcout<<L"Tempo médio para remover cada chave foi de "<<setw(26)<<tot/n<<'\n';

    arq.close();
    delete ST;
    exit(0);
    
}

//função para setar a estrutura da st
st<wstring, int>* setType(string type){

    locale localPadrao("");
    setlocale(LC_CTYPE, "");
    if(type == "VD") return new VD<wstring, int>();
    else if(type == "VO") return new VO<wstring, int>();
    else if(type == "LD") return new LD<wstring, int>();
    else if(type == "LO") return new LO<wstring, int>();
    else if(type == "AB") return new BST<wstring, int>();
    else if(type == "TR") return new TREAP<wstring, int>();
    else if(type == "A23") return new A23<wstring, int>();
    else if(type == "RN") return new BRT<wstring, int>();
    else if(type == "HS") return new HASH<wstring, int>();
    else {

        wcout<<L"Passe uma opção válida D:\n";
        exit(0);
        
    }
    
}

//função para carregar um arquivo de texto na st
void loadF(st<wstring, int> *ST, string nomeArquivo, bool show, bool testaTempo){

    locale localPadrao("");
    setlocale(LC_CTYPE, "");
    wifstream arq(nomeArquivo);
    arq.imbue(localPadrao);
    wstring s;
    int n = 0;
    clock_t tIni, tFim;

    wcout<<L"Carregando arquivo...\n";

    tIni = clock();
    while(arq>>s){

        if(show) wcout<<L"Inserindo "<<s<<L"\n";
        n++;
        ST->insere(s, 1);
        
    }
    
    tFim = clock();

    wcout<<L"Foram inseridas "<<n<<L" palavras.\n";
    if(testaTempo) wcout<<L"O tempo para carregar o arquivo foi de "<<(double)(tFim - tIni)/CLOCKS_PER_SEC<<L" segundos\n";
    
}
