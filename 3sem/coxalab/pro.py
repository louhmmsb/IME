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
    respPos = []
    respVel = []
    atualPos = d0
    atualVel = v0[1]
    for i in range(1000000):
        if atualPos[1] < 0:
            break
        respPos.append(atualPos)
        respVel.append(atualVel)
        atualPos, atualVel = calcula(atualPos, atualVel, 1e-3)
        

    respXpos = []
    respYpos = []
    respXvel = []
    respYvel = []
    for i in range(len(respPos)):
        respXpos.append(respPos[i][0])
        respYpos.append(respPos[i][1])
        respXvel.append(v0[0])
        respYvel.append(respVel)

        
    plt.title("Trajetória da Partícula")
    plt.xlabel("Pos X")
    plt.ylabel("Pos Y")
    plt.xlim(0, 10)
    plt.ylim(0, 10)
    plt.plot(respXpos, respYpos, color="k")
    plt.show()


main()
