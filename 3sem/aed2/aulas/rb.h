#include <iostream>


No *putRB(No *root, Chave ch, Item val){

    if(raiz == nullptr){

        raiz = new No;
        raiz->chave = ch;
        raiz->valor = val;
        raiz->cor = vermelho;
        return raiz;
        
    }

    No *p = raiz;
    bool achou = false;
    
    while(!achou){

        if(p->chave > ch && p->esq != nullptr) p = p->esp;
        
        else if(p->chave > ch && p->esq == nullptr) achou = true;

        
        if(p->chave < ch && p->dir != nullptr) p = p->dir;

        else if(p->chave < ch && p->dir == nullptr) achou = true;

        
        else achou = true

    }

    if(p->chave == ch){

        p->valor  = val;
        return raiz;
        
    }

    No *novo = new No;
    novo->chave = ch;
    novo->valor = val;
    novo->esq = nullptr;
    novo->dir = nullptr;
    novo->pai = p;
    novo->cor = vermelho;
    
    //agora faremos as mudanças para que a árvore continue sendo rubro negra

    while(true){
        
        //p é pai de um nó vermelho (filho)
        if(p->cor == preto) break;

        No *avo = p->pai;
        
        if(avo == nullptr){

            p->cor = preto;
            break;
            
        }

        No *tio = ;//outro filho do avo (precisa de um if)
        
        if(tio != nullptr && tio->cor == vermelho){

            avo->cor = vermelho;
            p->cor = tio->cor = preto;
            p = avo->pai;
            filho = avo;
            
        }

        else {//tio preto ou nullptr

            if(p == avo->esq && filho == p->esq){//os dois estão do mesmo lado

                avo->esq = p->dir;
                
                if(p->dir != nullptr) p->dir->pai = avo;
                
                p->dir = avo;
                p->pai = avo->pai;
                avo->pai = p;
                p->cor = preto;
                avo->cor = vermelho;
                if(avo == raiz);
                raiz = p;
                break;
                    
            }

            //tem o outro caso q é se p for filho x de avo e filho for filho y de p q é melhor colcoar antees, pq ele cai no caso anterior
            if(p->dir == filho && avo->esq == p){

                p->dir = filho->esq;

                if(filho->esq != nullptr) filho->esq->pai = p;

                filho->esq = p;
                p->pai = filho;
                filho->pai->avo;
                avo->esq = filho;
                
            }
            
        }
        
    }
    
}
