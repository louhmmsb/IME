#ifndef UTIL_H
#define UTIL_H

#include <cstring>
#include <wchar.h>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

//classe para guardar pares de dados
template<class A, class B>
class Pair{
  public:
    A first;
    B second;
    Pair(){};
    Pair(A, B);
};

template<class A, class B>
Pair<A, B>::Pair(A a, B b){
    first = a;
    second = b;
}

//retorna o mínimo entre dois números
int min(int a, int b);

//função principal para checar se duas palavras estão próximas segundo o pedido no enunciado
bool isNear(const wstring &r, const wstring &t);

wstring parser(wstring a);

wstring parseCommand(wstring bruteCommand);

#endif
