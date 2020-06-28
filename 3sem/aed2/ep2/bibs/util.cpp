/* Funções auxiliares do EP2 de Algoritmos e Estruturas de Dados 2 */

#include "util.hpp"

using namespace std;

int min(int a, int b){
    return (a<b)? a : b;
}

bool isNear(const wstring &r, const wstring &t){
    int diff = r.size() - t.size();
    diff = (diff>0)? diff : -diff;
    
    if(diff>1) return false;
    
    wstring maior = L" ", menor = L" ";

    if(r.size() > t.size()){
        maior += r;
        menor += t;
    }
    else{
        maior += t;
        menor += r;
    }
    if(diff == 0){
        int aux = 0;
        wchar_t b, s;
        for(size_t i=0; i<maior.size(); i++){
            if(maior[i] == menor[i]) continue;
            if(aux == 0){
                aux++;
                b = maior[i];
                s = menor[i];
            }
            else if(aux == 1){
                if(maior[i] == s && menor[i] == b) aux++;
                else return false;
            }
            else return false;
        }
    }
    else if(diff == 1){
        int aux = 0;
        for(size_t i=0, j=0; j<maior.size(); i++, j++){
            if(maior[j] == menor[i]) continue;
            if(aux == 0){
                aux++;
                i--;
            }
            else return false;
        }
    }

    return true;
}

wstring parser(wstring s){
    wstring res = L"";
    for(auto a : s) if(iswalnum(a)) res += towlower(a);
    return res;
}

wstring parseCommand(wstring bruteCommand){
    wstring refinedCommand = L"";
    for(auto a : bruteCommand) refinedCommand.push_back(towlower(a));
    return refinedCommand;
}
