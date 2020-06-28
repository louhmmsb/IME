#!/usr/bin/env python3

import matplotlib.pyplot as plt

d0 = [0, 0]
v0 = [1000, 0]
a0 = [-3, 8]

def calcula(oldPos, oldVel, deltaT):
    newPos = []
    newVel = []
    newVel.append(oldVel[0]+a0[0]*deltaT)
    newVel.append(oldVel[1]+a0[1]*deltaT)
    newPos.append(oldPos[0]+newVel[0]*deltaT)
    newPos.append(oldPos[1]+newVel[1]*deltaT)
    return newPos, newVel

def main():
    X = []
    Y = []
    atualPos = d0
    atualVel = v0
    for i in range(1000000):
        X.append(atualPos[0])
        Y.append(atualPos[1])
        atualPos, atualVel = calcula(atualPos, atualVel, 1e-3)

    plt.title("Trajetória da Partícula")
    plt.xlabel("Pos X")
    plt.ylabel("Pos Y")
#    plt.xlim(0, 100000)
#    plt.ylim(0, 100000)
    plt.plot(X, Y, color="k")
    plt.show()


main()
