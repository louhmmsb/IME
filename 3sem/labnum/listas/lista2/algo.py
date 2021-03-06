#! /usr/bin/env python3

import matplotlib.pyplot as plt
import math
import numpy as np

EPS = 1e-3

#x = list(map(float, input("Digite o x: ").split(" ")))
#y = list(map(float, input("Digite o y: ").split(" ")))
x = [x for x in np.arange(0, 4*np.pi, np.pi/50)]
y = [np.sin(t) for t in x]

z = [1]
#z.append(float(input("Digite a derivada em a: ")))

for i in range(len(x)-1):
    z.append(-z[i] + 2*(y[i+1]-y[i])/(x[i+1]-x[i]))

x_plota = []
y_plota = []

for i in range(len(x)-1):
    a = (z[i+1]-z[i])/(2*(x[i+1]-x[i]))
    b = (z[i])
    c = y[i]
    for j in np.arange(x[i], x[i+1], EPS):
        t = j-x[i]
        x_plota.append(j)
        y_plota.append(a*t*t + b*t + c)


seno = [np.sin(x) for x in x_plota]

err = 0
x = 0
for i in range(len(x_plota)):
    err += abs(y_plota[i]-seno[i])
    x += 1
    
err = err/x

plt.plot(x_plota, y_plota, color="green", label="Interpolado")
plt.plot(x_plota, seno, label="sin(x)", linestyle=":", color="red")
plt.title("Comparação do seno")
plt.text(0, -1, "Erro = " + str(err))

plt.legend()
plt.savefig("graf.png", dpi=1000)
