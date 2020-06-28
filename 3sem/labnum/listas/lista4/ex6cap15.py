#!/usr/bin/env python3

import numpy as np

n = 10
a = 0;
b = 1;
h = (b-a)/n

def nCorr(f, h, a, b):
    fS = 0
    for i in np.arange(a+h, b, h):
        fS += f(i)

    return h*(fS + (f(a)+f(b))/2)

def corr(f, df, h, a, b):
    resp = nCorr(f, h, a, b)
    resp += (h*h*(df(a)-df(b)))/12
    return resp
             
def g(x):
    return np.exp(-(x*x))

def dg(x):
    return -2*x*np.exp(-(x*x))

print(f"Valor dado    = 0.746824133")
print(f"Não corrigida = {nCorr(g, h, a, b)}")
print(f"Corrigida     = {corr(g, dg, h, a, b)}")
