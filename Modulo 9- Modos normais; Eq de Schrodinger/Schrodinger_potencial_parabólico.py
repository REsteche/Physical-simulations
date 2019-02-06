# -*- coding: utf-8 -*-
"""
Created on Fri Nov 16 11:30:53 2018

@author: ruben
"""

import numpy as np
import matplotlib.pyplot as plt
import scipy as sp

N = 1000
dx = 1.0/N
H = np.zeros((N,N))

for n in range (1,N-1):
    H[n][n] = 2 + 0.01*((2*n/1000. - 1)**2)
    H[n][n-1] = -1
    H[n][n+1] = -1
    
    
H[0][0] = 2 + 0.01*((2*n/1000. - 1)**2)
H[0][1] = -1
H[N-1][N-1] = 2 + 0.01*((2*n/1000. - 1)**2)
H[N-1][N-2] = -1

u,v = np.linalg.eigh(H)


x = range(N)

for i in range (25):
        plt.plot(x, v[:, i], ".-")
        titulo = "Energia = %.3f" %(u[i])
        plt.title(titulo,fontsize=16)
        plt.show()
        #plt.savefig()

plt.plot(u)
plt.axis([0,25,0,0.01])
plt.show()