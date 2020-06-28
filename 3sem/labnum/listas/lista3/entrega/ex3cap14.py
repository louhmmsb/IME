#!/usr/bin/env python3

import numpy as np

def f(x):
    return np.exp(x)*np.sin(3*x) 

def second_der(g, x0, h):
    return (2*g(x0-3*h)-27*g(x0-2*h)+270*g(x0-h)-490*g(x0)+270*g(x0+h)-27*g(x0+2*h)+2*g(x0+3*h))/(180*h*h)

print(f"Valor da segunda derivada para k = .1:                {second_der(f, 0.4, .1)}")
print(f"Valor da segunda derivada para k = .05:               {second_der(f, 0.4, .05)}")
print(f"Valor da segunda derivada para k = 0.25:              {second_der(f, 0.4, .025)}")
print(f"Valor da segunda derivada usando a solução analítica: {-8*np.exp(0.4)*np.sin(1.2)+6*np.exp(0.4)*np.cos(1.2)}")
