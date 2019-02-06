# -*- coding: utf-8 -*-
"""
Created on Fri Sep 21 08:48:18 2018

"""

import numpy as np
import scipy as sp
import matplotlib as matplt
import matplotlib.pyplot as plt

fname = "Mapa_Logisitico.txt"

from numpy import *
data = loadtxt(fname)
for m in range(10000):
    for n in range(10000):
        plt.scatter(data[m][0], data[m][n+1], s=7)
plt.show()
plt.close()