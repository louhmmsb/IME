#!/usr/bin/env python3

import numpy as np

'''Função que calcula a regra pedida no enunciado para a 
função f de derivada df'''
def trap(f, df, a, b):
    c = b-a
    return (c/2)*(f(a)+f(b))+((c*c)/12)*(df(a)-df(b))

'''Função dada no enunciado (e^x)'''
def g(x):
    return np.exp(x)


'''Apenas cálculo do erro'''
res1 = np.e - 1
res2 = np.e - np.e**(.9)

aprox1 = trap(g, g, 0, 1)
aprox2 = trap(g, g, 0.9, 1)

err1 = abs(res1 - aprox1)
err2 = abs(res2 - aprox2)

print(err1)
print(err2)
