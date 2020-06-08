#include<iostream>
#include<string>
#include<wchar.h>
#include"grafo.hpp"
#include<set>

using namespace std;

int
main (int argc, char **argv)
{
    setlocale(LC_CTYPE, "");
    locale localPadrao("");

    wfstream arq(argv[1]);
    arq.imbue(localPadrao);
    
    wstring s;
    Grafo G(stoi(argv[2]));
    set<wstring> S;
    while (arq >> s) {
        if ((int) s.size() >= stoi(argv[2])) {
            G.insere(s);        
            S.insert(s);
        }
    }
    arq.close();

    int cnt = 0;
    for (auto x : S)
        if (G.emCiclo(x)) {
            wcout << x << "\n";
            cnt++;
        }
    wcout << "Total: " << cnt << "\n";
    return 0;
}
