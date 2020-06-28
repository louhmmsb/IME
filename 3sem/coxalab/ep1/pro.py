#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

d0 = [0, 0]
vi = 10
theta = np.pi/4
v0 = [vi*np.cos(theta), vi*np.sin(theta)]
g0 = 10

def calcula(oldPos, oldVel, deltaT):
    newPos = []
    newVel = oldVel-g0*deltaT
    newPos.append(oldPos[0]+v0[0]*deltaT)
    newPos.append(oldPos[1]+newVel*deltaT)
    return newPos, newVel

def main():
    X = []
    Y = []
    atualPos = d0
    atualVel = v0[1]
    for i in range(1000000):
        if atualPos[1] < 0:
            break
        X.append(atualPos[0])
        Y.append(atualPos[1])
        atualPos, atualVel = calcula(atualPos, atualVel, 1e-3)

    plt.title("Trajetória da Partícula")
    plt.xlabel("Pos X")
    plt.ylabel("Pos Y")
    plt.xlim(0, 10)
    plt.ylim(0, 10)
    plt.plot(X, Y, color="k")
    plt.show()


main()
