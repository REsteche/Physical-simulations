# -*- coding: utf-8 -*-
"""
Created on Fri Nov 16 08:17:58 2018

@author: ruben
"""

import numpy as np
import matplotlib.pyplot as plt
import scipy as sp

a = input ("escolha o número de osciladores:")

N = int (a)

b= input ("Quanto as condições de contorno, escolha\n\n 1.Extremidades fixas;\n 2.Condições de contorno periódicas;\n 3.Extremidades livres;\n\n Sua opção:" )

M = int (b)

T = np.zeros((N,N))

#os termos comentados (com dependência de de n) fazem com que as massas/k's das molas variem ;)
for n in range (1,N-1):
    T[n][n] = 2#/(1.5 + 0.5*(-1)**n)
    T[n][n-1] = -1#/(1.5 + 0.5*(-1)**n) 
    T[n][n+1] = -1#/(1.5 + 0.5*(-1)**n)

if M == 1:
    T[0][0] = 2
    T[0][1] = -1
    T[N-1][N-1] = 2
    T[N-1][N-2] = -1

if M == 2:
    T[0][0] = 2
    T[0][1] = -1
    T[N-1][N-1] = 2
    T[N-1][N-2] = -1
    T[0][N-1] = -1
    T[N-1][0] = -1

if M == 3:
    T[0][1] = -1
    T[N-1][N-2] = -1
    T[0][0] = 1
    T[N-1][N-1] = 1
    
print("\nMatriz com condições de contorno:\n",T)    
  
u,v = np.linalg.eigh(T)

x = range(N)

for i in range (N):
    plt.plot(x, v[:, i], ".-")
    titulo = r"$\omega^2 = %.3f$" %(u[i])
    plt.title(titulo,fontsize=16)
    plt.show()
    #plt.savefig()
    