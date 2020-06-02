#include "util.hpp"
#include <vector>
#include "hash.hpp"

//k definido como no enunciado será passado como argumento de linha de comando
class Grafo{
  private:
    //k dado no enunciado
    int minSize;
    //número de arestas
    int nArestas;
    //lista de adjacência
    vector<vector<pair<wstring, int>>> adj;
    //para descobrir qual palavra está em qual vértice
    vector<wstring> words;
    //para descobrir se uma palavra já está no grafo com rapidez
    hashTable table(23);
    //vetor auxiliar para fazer as buscas
    vector<bool> vis;
    //int auxiliar para contar tamanho de componentes
    int compSize;

  public:
    Grafo(int k){
        /* Inicializa um grafo com parâmetro k */
        minSize = k;
        nArestas = 0;
    }

    int insere(wstring palavra){
        /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
        retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
        if(palavra.size() < minSize) return -1;
        if(table.find(palavra)) return -1;
        words.push_back(palavra);
        int index = words.size()-1;
        int p = pair(palavra, index);
        int arestas = 0;
        table.insert(p);
        vector<pair<wstring, int>> novo;
        for(int i=0; i<adj.size(); i++){
            if(isNear(words[i], palavra)){
                adj[i].push_back(p);
                novo.push_back(pair(words[i], i));
                arestas++;
            }
        }
        adj.push_back(novo);
        nArestas += arestas;
        vis.push_back(false);
        return arestas;
    }

    int vertices(){
        /* Retorna o número de vértices do grafo*/
        return adj.size();
    }

    int arestas(){
        /* Retorna o número de vértices do grafo*/
        return nArestas;
    }

    int componentes(){
        /* Retorna o número de componentes do grafo */
        int c = 0;
        int compSize = 0;
        memset(vis, false, sizeof(vis));ww
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == true) continue;
            else if(vis[i] == false){
                int x = dfs(i);
                c++;
            }
        }
        return c;
    }

    bool conexo(){
        /* Retorna se o grafo é ou não conexo */
        memset(vis, false, sizeof(vis));
        int x = dfs(0);
        for(auto a : vis){
            if(a == false) return false;
        }
        return true;
    }

    int tamComp(wstring palavra){
        /* Retorna o tamanha da componente conexa onde está a palavra
        ou -1 caso ela não se encontre no grafo */
        int n = table.getNode(palavra);
        memset(vis, false, sizeof(vis));
        return dfs(n);
    }

    int dist(wstring a, wstring b){
        /* Retorna a menor distância entre as palavras a e b ou -1
        caso elas estejam desconexas ou não estejam no grafo */
        if(!table.find(a) || !table.find(b)) return -1;
        memset(vis, false, sizeof(vis));
        queue<int> q;
        dist[sizeof(vis)];
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        int aux = table.getNode(a);
        q.push_back(aux);
        dist[aux] = 0;
        int res = table.getNode(b);
        while(!q.empty()){
            int x = q.front();
            q.pop_front();
            for(auto y : adj[x]){
                if(!vis[y.second]){
                    visited[y.second] = true;
                    dist[y.second] = dist[x]+1;
                }
            }
        }
    }

    bool emCiclo(wstring a){
        /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
        falso caso contrário */
    }

    bool emCiclo(wstring a, wstring b){
        /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
        falso caso contrário */
    }
    
    int dfs(int ini){
        vis[ini] = true;
        compSize++;
        for(auto a : adj[ini]){
            if(vis[a.second]) continue;
            else dfs(a.second);
        }
        return compSize;
    }

};
