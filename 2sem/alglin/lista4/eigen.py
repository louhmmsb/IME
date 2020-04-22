import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg as la

A = np.array([[1, 3],[4, 5]])
B = A.T
print(A)

eigenA = la.eig(A)
print("Eigenvalues = ", eigenA[0])
print("Eigenvectors = ",  eigenA[1], "\n")

print(B)

eigenB = la.eig(B)
print("Eigenvalues = ", eigenB[0])
print("Eigenvectors = ", eigenB[1])
