#!/usr/bin/env python3

import matplotlib.pyplot as plt

d0 = [0, 0]
v0 = [1, 10]

#v0 = constante->x'(t) = vx = x((t+delta(t))-x(t))/delta(t)->
#x(t+delta(t)) = x'(t)*delta(t)+x(t)

def calcula(oldPos, deltaT):
    newPos = []
    newPos.append(oldPos[0]+v0[0]*deltaT)
    newPos.append(oldPos[1]+v0[1]*deltaT)
    return newPos

def main():
    resp = []
    atual = d0
    for i in range(10):
        resp.append(atual)
        atual = calcula(atual, 0.1)

    respX = []
    respY = []
    for pos in resp:
        respX.append(pos[0])
        respY.append(pos[1])


    plt.title("Trajetória da Partícula")
    plt.xlabel("Pos X")
    plt.ylabel("Pos Y")
    plt.xlim(0, 10)
    plt.ylim(0, 10)
    plt.plot(respX, respY, color="k")
    plt.show()


main()
