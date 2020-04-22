#include "aviao.h"
#include "queue.h"
#include <iostream>

using namespace std;


//essa função calcula o tempo de espera dos aviões e em qual fila o avião deve pousar/decolar.
int waitTime(int cd[], int cdprioridade[], int *qualFila, int emerg, int tempo){
    
    int a;
    
    if(emerg != 0){
        
        if(cdprioridade[0] <= cdprioridade[1] && cdprioridade[0] <= cdprioridade[2]){
            
            *qualFila = 0;
            a = cdprioridade[0];
            cdprioridade[0] += 2;
            
        }
        
        else if(cdprioridade[1]<=cdprioridade[2]){
            
            *qualFila = 1;
            a = cdprioridade[1];
            cdprioridade[1] += 2;
            
        }
        
        else {
            
            *qualFila = 2;
            a = cdprioridade[2];
            cdprioridade[2] += 2;
            
        }
        
    }
    
    else{
        
        if(tempo > 0){
            
            if(cd[0] <= cd[1] && cd[0] <= cd[2]){
                
                *qualFila = 3;
                a = cd[0];
                //a += cdprioridade[0];
                cd[0] += 2;
                
            }
            
            else if(cd[1] <= cd[2]){
                
                *qualFila = 4;
                a = cd[1];
                //a += cdprioridade[1];
                cd[1] += 2;
                
            }
            
            else {
                
                *qualFila = 5;
                a = cd[2];
                //a += cdprioridade[2];
                cd[2] += 2;
                
            }
            
        }
        
        else {
            
            if(cd[0] <= cd[1]){
                
                *qualFila = 3;
                a = cd[0];
                //a += cdprioridade[0];
                cd[0] += 2;
                
            }
            
            else {
                
                *qualFila = 4;
                a = cd[1];
                //a += cdprioridade[1];
                cd[1] += 2;
                
            }
            
        }
        
    }
    
    return a;
    
}



int main(){
    
    int semente, C, V, T, K, cd[3] = {0, 0, 0}, cdprioridade[3] = {0, 0, 0}, qualPista, cont = 0, navioes = 0;
    Node<Aviao> *percorre, *att;
    Queue<Aviao> priority, normal;
    bool deuruim = false, random = true;
    char decide;
    int tpousocounter = 0, tpousosoma = 0, tdecolcounter = 0, tdecolsoma = 0, combsoma = 0, combjasoma = 0, combjacounter = 0;
    int ntpousocounter = 0, ntpousosoma = 0, ntdecolcounter = 0, ntdecolsoma = 0, ncombsoma = 0;
    
    //o int qualPista indicará em qual pista o avião será enviado quando chegar a sua vez, ele é usado na função waitTime.

    //entrada
    cout<<"Você quer que a simulação seja aleatória?(Responda com S para sim e N para não) ";
    cin>>decide;

    if(decide == 'S') random = true;
    
    else random = false;
    
    if(random == true){
        
        cout<<"Qual semente você quer usar para gerar os aviões: ";
        cin>>semente;
        
        cout<<"Qual C você quer? (C é a quantidade máxima de combustível que um avião pode ter quando gerado aleatoriamente) ";
        cin>>C;
        
        cout<<"Qual V você quer? (V é a quantidade máxima de tempo de voo que um avião pode ter quando gerado aleatoriamente) ";
        cin>>V;
        
        cout<<"Digite o número máximo de aviões que podem ser gerados a cada T: ";
        cin>>K;

    }
        
        cout<<"Você quer que a simulação dure quanto tempo: ";
        cin>>T;

    //seta a semente para gerar as coisas
    srand(semente);

    
    while(cont < T){

        att = priority.head->next;
        
        while(att != nullptr){
            
            att->data->atualiza();
            att = att->next;
            
        }

        att = normal.head->next;
        
        while(att != nullptr){
            
            att->data->atualiza();
            att = att->next;
            
        }
        
        Aviao *p;
        
        if(random == false){
            
            cout<<"Quantos aviões você quer gerar nesse T";
            cin>>navioes;
            
        }
        
        else navioes = rand()%(K+1);
        
        cout<<"--------------------"<<cont<<"--------------------"<<endl;
        
        for(int i=0; i<navioes; i++){
            
            if(random == true) p = new Aviao(C, V);
            
            else {
                
                p = new Aviao();
                
            }
            
            p->setEspera(waitTime(cd, cdprioridade, &qualPista, p->emerg(), p->tempo()));
            p->setFila(qualPista%3);
            
            if(p->emerg() == 1) deuruim = true;

            if(deuruim == false && p->tempo() == -1 && p->espera() - cont > p->comb()){
                
                p->setEmerg(2);
                p->setEspera(waitTime(cd, cdprioridade, &qualPista, p->emerg(), p->tempo()));
                p->setFila(qualPista%3);
                
                if(p->espera() - cont > p->comb()){
                    
                    cout<<*p<<endl;
                    cout<<"Este avião não conseguirá pousar, nem se for tratado como avião de emergência, logo será mandando para outro aeroporto"<<endl;
                    delete p;
                    p = nullptr;
                    continue;
                    
                }
                
                else {
                    
                    cout<<*p<<endl;
                    cout<<"Esse avião só conseguirá pousar caso seja tratado como um de emergência, logo será enviado para a fila de emergência"<<endl;
                    deuruim = true;
                    
                }
                
            }
            
            if(deuruim == true){
                
                priority.insere(p);
                for(int a=0; i<3; i++){
                    
                    cd[a] = cdprioridade[a];
                    
                }
                
                percorre = normal.head->next;
                
                while(percorre != nullptr){
                    
                    percorre->data->setEspera(waitTime(cd, cdprioridade, &qualPista, percorre->data->emerg(), percorre->data->tempo()));
                    percorre->data->setFila(qualPista%3);
                    
                    if(percorre->data->tempo() != -1 && (float)(percorre->data->espera() - cont) > (float)(0.1*(percorre->data->tempo()))){
                        
                        percorre->data->setEmerg(3);
                        Aviao *pInsere;
                        pInsere = normal.remove(percorre);
                        pInsere->setEspera(waitTime(cd, cdprioridade, &qualPista, pInsere->emerg(), pInsere->tempo()));
                        pInsere->setFila(qualPista%3);
                        priority.insere(pInsere);
                        
                        for(int a=0; a<3; a++){
                            
                            cd[a] = cdprioridade[a];
                            
                        }
                        
                        percorre = normal.head->next;
                        
                    }
                    
                    else if(percorre->data->tempo() == -1 && percorre->data->espera() - cont > percorre->data->comb()){
                        
                        percorre->data->setEmerg(2);
                        percorre->data->setEspera(waitTime(cd, cdprioridade, &qualPista, percorre->data->emerg(), percorre->data->tempo()));
                        percorre->data->setFila(qualPista%3);
                        
                        if(percorre->data->espera() - cont > percorre->data->comb()){
                            
                            cout<<*(percorre->data)<<endl<<"O avião a cima foi mandando embora pois não conseguiria pousar com a sua quantidade de combustível"<<endl;
                            
                            delete normal.remove(percorre);
                            percorre = nullptr;
                            
                        }
                        
                        else {
                            
                            Aviao *pInsere = normal.remove(percorre);
                            priority.insere(pInsere);
                            
                            for(int a=0; a<3; a++){
                                
                                cd[a] = cdprioridade[a];
                                
                            }
                            
                            percorre = normal.head->next;
                            
                        }
                        
                    }
                    
                }
                
                deuruim = false;
                
            }
            
            else normal.insere(p);
            
        }
        
        percorre = priority.head->next;
        
        while(percorre != nullptr){
            
            cout<<*(percorre->data);
            percorre = percorre->next;
            
        }
        
        /*cout<<"Prioridade (Antes): ";
        
        for(int i=0; i<3; i++){
            
            cout<<cdprioridade[i]<<" ";
            
            }*/
        
        cout<<endl;
        percorre = normal.head->next;
        
        while(percorre != nullptr){
            
            cout<<*(percorre->data);
            percorre = percorre->next;
            
        }
        
        /*cout<<"Normal (Antes): ";
        
        for(int i=0; i<3; i++){
            
            cout<<cd[i]<<" ";
            
            }*/
        
            cout<<endl;
        /*for(int i=0; i<3; i++){
            if(priority.nElem()>0 && (priority.top())->espera() == cont)
                delete priority.remove();
                }*/
        percorre = priority.head->next;
        
        while(percorre != nullptr && priority.nElem()>0){
            
            if(percorre->data->espera() == cont){

                if(percorre->data->tempo() == -1){

                    combjasoma = percorre->data->comb();
                    combjacounter++;
                    
                }
                
                Node<Aviao> *aux = percorre->next;
                delete priority.remove(percorre);
                percorre = aux;
                
            }

            else {

                if(percorre->data->tempo() == -1){

                    tpousosoma += percorre->data->espera();
                    combsoma += percorre->data->comb(); 
                    tpousocounter++;
                    
                }

                else {

                    tdecolsoma += percorre->data->espera();
                    tdecolcounter++;
                    
                }

                percorre = percorre->next;
                
            }
            
        }
        
        /*for(int i=0; priority.nElem() == 0 && normal.nElem() > 0 && i<3; i++){
            if(normal.nElem()>0 && (normal.top())->espera() == cont){
                cdprioridade[(normal.top())->fila()] = (normal.top())->espera() + 2;
                delete normal.remove();
            }
            }*/
        
        percorre = normal.head->next;
        while(/*priority.nElem() == 0 &&*/ percorre != nullptr && normal.nElem()>0){
            
            if(percorre->data->espera() == cont){
                
                cdprioridade[percorre->data->fila()] = percorre->data->espera() + 2;
                
                if(percorre->data->tempo() == -1){

                    combjasoma += percorre->data->comb();
                    combjacounter++;
                    
                }
                
                Node<Aviao> *aux = percorre->next;
                delete normal.remove(percorre);
                percorre = aux;
                
            }
            
            else {

                if(percorre->data->tempo() == -1){

                    ntpousosoma += percorre->data->espera();
                    ncombsoma += percorre->data->comb(); 
                    ntpousocounter++;
                    
                }

                else {
                    
                    ntdecolsoma += percorre->data->espera();
                    ntdecolcounter++;
                    
                }
                
                percorre = percorre->next;
                
            }
        }
        
        for(int i=0; i<3; i++){
            
            if(cd[i] <= cont) cd[i] = cont+1;
            
            if(cdprioridade[i] <= cont) cdprioridade[i] = cont+1;
            
            //if(cdprioridade[i] <= cd[i]) cdprioridade[i] =  cd[i]+1;
            //if(cd[i] <= cont) cd[i] = cont+1;
            //if(cd[i] <= cdprioridade[i]) cd[i] = cdprioridade[i]+1;
        }
        
        /*cout<<"Prioridade (Depois): ";
        
        for(int i=0; i<3; i++){
            
            cout<<cdprioridade[i]<<" ";
            
        }
        
        cout<<endl;
        cout<<"Normal (Depois): ";
        
        for(int i=0; i<3; i++){
            
            cout<<cd[i]<<" ";
            
            }*/
        
        cout<<endl;
        cont++;

        cout<<"ESTATÍSTICAS NO T ATUAL: "<<endl;
        
        cout<<"Fila de Emergência: "<<endl;
        
        if(tpousocounter != 0){
            
            cout<<"Tempo médio de espera para pouso: "<<(((float)tpousosoma)/tpousocounter)<<endl;
            cout<<"Comb médio dos que estão esperando para pousar: "<<(((float)combsoma)/tpousocounter)<<endl;
            
        }
        
        if(tdecolcounter != 0){
            
            cout<<"Tempo médio de espera para decolar: "<<(((float)tdecolsoma)/tdecolcounter)<<endl;
            
        }
        
        cout<<"Fila de Normal: "<<endl;

        if(ntpousocounter != 0){
            
            cout<<"Tempo médio de espera para pouso: "<<(((float)ntpousosoma)/ntpousocounter)<<endl;
            cout<<"Comb médio dos que estão esperando para pousar: "<<(((float)ncombsoma)/ntpousocounter)<<endl;
            
        }

        if(ntdecolcounter != 0){
            
            cout<<"Tempo médio de espera para decolar: "<<(((float)ntdecolsoma)/ntdecolcounter)<<endl;
            
        }
        
        
        cout<<"Total: "<<endl;

        if(tpousocounter+ntpousocounter != 0){
            
            cout<<"Tempo médio de espera para pouso: "<<(((float)(tpousosoma+ntpousosoma))/(tpousocounter+ntpousocounter))<<endl;
            cout<<"Comb médio dos que estão esperando para pousar: "<<(((float)(combsoma+ncombsoma))/(tpousocounter+ntpousocounter))<<endl;
            
        }

        if(tdecolcounter+ntdecolcounter != 0){
            
            cout<<"Tempo médio de espera para decolar: "<<(((float)(tdecolsoma+ntdecolsoma))/(tdecolcounter+ntdecolcounter))<<endl;
            
        }
        
        if(combjacounter != 0){
            
            cout<<"Comb médio dos que já pousaram: "<<(((float)combjasoma)/combjacounter)<<endl;
            
        }

        tpousocounter = 0, tpousosoma = 0, tdecolcounter = 0, tdecolsoma = 0, combsoma = 0;
        ntpousocounter = 0, ntpousosoma = 0, ntdecolcounter = 0, ntdecolsoma = 0, ncombsoma = 0;
        
    }
    
    return 0;
    
}
