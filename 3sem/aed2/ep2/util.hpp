#include <string>
#include <wchar.h>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

//classe para guardar pares de dados
template<class A, class B>
class pair{
  public:
    A first;
    B second;
}

//retorna o mínimo entre dois números
int min(int a, int b);

//função principal para checar se duas palavras estão próximas segundo o pedido no enunciado
bool isNear(const wstring &r, const wstring &t);

