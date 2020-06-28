#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

def second_der(f, x, h):
    return (f(x-h)-2*f(x)+f(x+h))/(h*h)


x = np.arange(0, 8.5, .5)

dif = [abs(second_der(np.sin, 1.2, 10**(-i))-(-np.sin(1.2))) for i in x]

x = [10**(-i) for i in x]

plt.loglog(x, dif)
plt.savefig("graph.png", dpi=1000)
#plt.show()
