#ifndef GRAFO_H
#define GRAFO_H

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
    std::vector<vector<Pair<std::wstring, int>>> adj;
    //para descobrir qual palavra está em qual vértice
    std::vector<std::wstring> words;
    //para descobrir se uma palavra já está no grafo com rapidez
    hashTable table;
    //vetor auxiliar para fazer as buscas
    std::vector<bool> vis;
    //int auxiliar para contar tamanho de componentes
    int compSize;
    //
    bool achei;
    //para guardar a maior componente
    int maxComp;
    //para guardar a menor componentes
    int minComp;
    
  public:
    Grafo(int k){
        /* Inicializa um grafo com parâmetro k */
        minSize = k;
        nArestas = 0;
    }

    int insere(std::wstring palavra){
        /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
        retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
        if((int)palavra.size() < minSize) return -1;
        if(table.find(palavra)) return -1;
        words.push_back(palavra);
        int index = words.size()-1;
        Pair<wstring, int> p(palavra, index);
        int arestas = 0;
        table.insert(p);
        std::vector<Pair<std::wstring, int>> novo;
        for(int i=0; i<(int)adj.size(); i++){
            if(isNear(words[i], palavra)){
                adj[i].push_back(p);
                Pair<wstring, int> _p(words[i], i);
                novo.push_back(_p);
                arestas++;
            }
        }
        adj.push_back(novo);
        nArestas += arestas;
        vis.push_back(false);
        maxComp = -1;
        minComp = -1;
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
        maxComp = 0;
        std::fill(vis.begin(), vis.end(), false);
        for(int i=0; i<(int)vis.size(); i++){
            if(vis[i] == true) continue;
            compSize = 0;
            int aux = dfs(i);
            maxComp = (maxComp > aux)? maxComp : aux;
            minComp = (minComp == -1 || minComp > aux)? aux : minComp;
            c++;
        }
        return c;
    }

    bool conexo(){
        /* Retorna se o grafo é ou não conexo */
        if(words.size() == 0) return false;
        std::fill(vis.begin(), vis.end(), false);
        compSize = 0;        
        dfs(0);
        for(auto a : vis){
            if(a == false) return false;
        }
        return true;
    }

    int tamComp(std::wstring palavra){
        /* Retorna o tamanha da componente conexa onde está a palavra
        ou -1 caso ela não se encontre no grafo */
        compSize = 0;
        int n = table.getNode(palavra);
        if(n == -1) return -1;
        std::fill(vis.begin(), vis.end(), false);
        return dfs(n);
    }

    int dist(std::wstring a, std::wstring b){
        /* Retorna a menor distância entre as palavras a e b ou -1
        caso elas estejam desconexas ou não estejam no grafo */
        if(!table.find(a) || !table.find(b)) return -1;
        std::fill(vis.begin(), vis.end(), false);
        queue<int> q;
        int dist[sizeof(vis)];
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        int aux = table.getNode(a);
        q.push_back(aux);
        dist[aux] = 0;
        int res = table.getNode(b);
        
        while(!q.empty()){
            int x = q.front();
            q.pop_front();
            if(x == res) return dist[x];
            for(auto y : adj[x]){
                if(!vis[y.second]){
                    vis[y.second] = true;
                    dist[y.second] = dist[x]+1;
                    q.push_back(y.second);
                }
            }
        }
        return -1;
    }

    bool emCiclo(std::wstring a){
        /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
        falso caso contrário */
        achei = false;
        std::fill(vis.begin(), vis.end(), false);
        int x = table.getNode(a);
        if(x == -1) return false;
        dfsC(x, x, -1);
        return achei;
    }

    bool emCiclo(std::wstring a, std::wstring b){
        /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
        falso caso contrário */
        achei = false;
        std::fill(vis.begin(), vis.end(), false);
        int x = table.getNode(a);
        int y = table.getNode(b);
        if(x == -1 || y == -1) return false;
        dfsC(x, x, -1, false, y);
        return achei;
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

    void dfsC(int ini, int start, int pai, bool acheiB= true, int b = 0){
        vis[ini] = true;
        for(auto a : adj[ini]){
            if(acheiB == false && a.second == b) acheiB = true;
            if(achei && acheiB) break;
            if(vis[a.second]){
                if(a.second == start && a.second != pai && acheiB) achei = true;
                continue;
            }
            dfsC(a.second, start, ini, acheiB, b);
        }
    }

    int maiorComp(){
        if(maxComp == -1) componentes();
        return maxComp;
    }

    int menorComp(){
        if(minComp == -1) componentes();
        return minComp;
    }

};

#endif
