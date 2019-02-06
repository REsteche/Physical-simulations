# -*- coding: utf-8 -*-
"""
Created on Fri Sep 14 13:23:36 2018

@author: ruben
"""

import numpy as np
import matplotlib as matplt
import matplotlib.pyplot as plt 
import scipy as sp 

fname = 'posição (oscilador).txt'

from numpy import*
data = loadtxt(fname)
for m in range(30) :
     for n in range(100):
         plt.xlim(-5,5)
         plt.ylim(-5,5)
         plt.scatter(data[m*100][2*n+1])
     plt.savefig("OHS t="+str(m/10)+".png")
     plt.show()
     plt.close()








