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
    respPos = []
    respVel = []
    atualPos = d0
    atualVel = v0
    for i in range(1000000):
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
        respXvel.append(respVel[i][0])
        respYvel.append(respVel[i][1])

        
    plt.title("Trajetória da Partícula")
    plt.xlabel("Pos X")
    plt.ylabel("Pos Y")
#    plt.xlim(0, 100000)
#    plt.ylim(0, 100000)
    plt.plot(respXpos, respYpos, color="k")
    plt.show()


main()
