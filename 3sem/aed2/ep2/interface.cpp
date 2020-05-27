#include <util.hpp>
#include <vector>

//k definido como no enunciado será passado como argumento de linha de comando
class Grafo{
  private:
    //k dado no enunciado
    int minSize;
    
    //lista de adjacência
    vector<vector<pair<wstring, int>>> adj;
    vector<wstring> words;

  public:
    Grafo(int k){
        /* Inicializa um grafo com parâmetro k */
        minSize = k;
    }

    int insere(wstring palavra){
        /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
        retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
        if(palavra.size() <= minSize) return -1;
        

    }

    int vertices(){
        /* Retorna o número de vértices do grafo*/
    }

    int arestas(){
        /* Retorna o número de vértices do grafo*/
    }

    int componentes(){
        /* Retorna o número de componentes do grafo */
    }

    bool conexo(){
        /* Retorna se o grafo é ou não conexo */
    }

    int tamComp(string palavra){
        /* Retorna o tamanha da componente conexa onde está a palavra
        ou -1 caso ela não se encontre no grafo */
    }

    int dist(string a, string b){
        /* Retorna a menor distância entre as palavras a e b ou -1
        caso elas estejam desconexas ou não estejam no grafo */
    }

    bool emCiclo(string a){
        /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
        falso caso contrário */
    }

    bool emCiclo(string a, string b){
        /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
        falso caso contrário */
    }

};
