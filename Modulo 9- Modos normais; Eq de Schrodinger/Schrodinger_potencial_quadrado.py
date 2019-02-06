# -*- coding: utf-8 -*-
"""
Created on Fri Nov 16 11:30:53 2018

@author: ruben
"""

import numpy as np
import matplotlib.pyplot as plt
import scipy as sp


H = np.zeros((1000,1000))

for n in range (400,600):
    H[n][n] = 2 + 0.01
    H[n][n-1] = -1
    H[n][n+1] = -1
    
for n in range (600,999):
    H[n][n] = 2 
    H[n][n-1] = -1
    H[n][n+1] = -1

for n in range (1,400):
    H[n][n] = 2 
    H[n][n-1] = -1
    H[n][n+1] = -1    
    
H[0][0] = 2 + 0.01
H[0][1] = -1
H[999][999] = 2 + 0.01
H[999][998] = -1

u,v = np.linalg.eigh(H)

x = range(1000)

for i in range (25):
        plt.plot(x, v[:, i], ".-")
        titulo = "Energia = %.3f" %(u[i])
        plt.title(titulo,fontsize=16)
        plt.show()
        #plt.savefig()
    
plt.plot(u)
plt.axis([0,25,0,0.01])
plt.show()