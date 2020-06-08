#include "grafo.hpp"

using namespace std;

int main(int argc, char **argv){
    setlocale(LC_CTYPE, "");
    locale localPadrao("");

    if(argc != 2){
        cout<<"O programa deve ser chamado da seguinte maneira: ./main.out k, onde k é o tamanho mínimo das palavras que o grafo aceita. "<<endl;
        return 0;
    }
    
    int minSize = atoi(argv[1]);
    
    Grafo g(minSize);

    wstring comando = L"first";
    do{
        comando = parseCommand(comando);
        if(comando == L"insere"){
            wstring arg;
            wcin>>arg;

            arg = parser(arg);
            g.insere(arg);
        }
        else if(comando == L"vertices") wcout<<g.vertices()<<endl;
        else if(comando == L"arestas") wcout<<g.arestas()<<endl;
        else if(comando == L"componentes") wcout<<g.componentes()<<endl;
        else if(comando == L"conexo") wcout<<((g.conexo())? L"True" : L"False")<<endl;
        else if(comando == L"tamcomp"){
            wstring arg;
            wcin>>arg;

            wcout<<g.tamComp(arg)<<endl;
        }
        else if(comando == L"dist"){
            wstring arg1, arg2;
            wcin>>arg1>>arg2;

            wcout<<g.dist(arg1, arg2)<<endl;
        }
        else if(comando == L"emciclo1"){
            wstring arg;
            wcin>>arg;

            wcout<<g.emCiclo(arg)<<endl;
        }
        else if(comando == L"emciclo2"){
            wstring arg1, arg2;
            wcin>>arg1>>arg2;

            wcout<<g.emCiclo(arg1, arg2)<<endl;
        }
        else if(comando == L"load"){
            wstring nome;
            wcin>>nome;
            string nomeArq(nome.begin(), nome.end());
            
            wfstream arq(nomeArq);
            arq.imbue(localPadrao);
            wstring p;
                
            while(arq>>p){
                p = parser(p);
                g.insere(p);
            }

            wcout<<L"Arquivo carregado com sucesso!"<<endl;
        }
        else if(comando == L"maxcomp"){
            wcout<<g.maiorComp()<<endl;
        }
        else if(comando == L"mincomp"){
            wcout<<g.menorComp()<<endl;
        }
        else if(comando == L"mediaComp"){
            wcout<<g.mComp()<<endl;
        }
        else if(comando == L"distmedia"){
            wcout<<g.distMedia()<<endl;
        }
        else if(comando == L"denso"){
            wcout<<((g.arestas() > (g.vertices()*g.vertices()))? L"True" : L"False")<<endl;
        }
        else if(comando == L"graumedio"){
            wcout<<g.grauMedio()<<endl;
        }
        else if(comando == L"first") wcout<<"Ola, tudo bem?"<<endl;
        else if(comando == L"estat"){
            wcout<<L"Número de vértices = "<<g.vertices()<<endl;
            wcout<<L"Número de arestas = "<<g.arestas()<<endl;
            wcout<<L"Número de componentes = "<<g.componentes()<<endl;
            wcout<<L"Tamanho da maior componente = "<<g.maiorComp()<<endl;
            wcout<<L"Tamanho da menor componente = "<<g.menorComp()<<endl;
            wcout<<L"Tamanho médio das componentes = "<<g.mComp()<<endl;
            wcout<<L"Distância média entre as palavras = "<<g.distMedia()<<endl;
            wcout<<L"Grau médio dos vértices do grafo = "<<g.grauMedio()<<endl;
            wcout<<L"Conexo = "<<((g.conexo())? L"True" : L"False")<<endl;
            wcout<<L"Denso = "<<((g.arestas() > (g.vertices()*g.vertices()))? L"True" : L"False")<<endl;
        }
        else if(comando == L"help"){
            wcout<<L"---*---*---*---*---*---*---*---*---*---*---AJUDA---*---*---*---*---*---*---*---*---*---*---"<<endl;
            wcout<<L"Para descobrir o número de vertices, digite: vertices"<<endl;
            wcout<<L"Para descobrir o número de arestas, digite: arestas"<<endl;
            wcout<<L"Para descobrir o número de componentes, digite: componentes"<<endl;
            wcout<<L"Para descobrir se o grafo é conexo, digite: conexo"<<endl;
            wcout<<L"Para o tamanho da componente do grafo que contém uma certa string x, digite: tamcomp x"<<endl;
            wcout<<L"Para descobrir a distância entre duas strings x e y, digite: dist x y"<<endl;
            wcout<<L"Para descobrir se a string x está em um ciclo, digite: emciclo1 x"<<endl;
            wcout<<L"Para descobrir se as strings x e y estão em um mesmo ciclo, digite: emciclo2 x y"<<endl;
            wcout<<L"Para carregar um arquivo, digite: load nome_do_arquivo"<<endl;
            wcout<<L"Para descobrir o tamanho da maior componente do grafo, digite: maxcomp"<<endl;
            wcout<<L"Para descobrir o tamanho da menor componente do grafo, digite: mincomp"<<endl;
            wcout<<L"Para um resumo da estatísticas do grafo, digite: estat"<<endl;
            wcout<<L"Para fechar o programa corretamente sem memory leaks, use: ctrl d"<<endl;
        }
        else{
            while(getwchar() != '\n');
            wcout<<L"Não falo essa língua!"<<endl;
        }
        wcout<<L">>> ";
        
    }while(wcin>>comando);

    wcout<<L"Oba! Vou descansar."<<endl;
    
    return 0;
}

