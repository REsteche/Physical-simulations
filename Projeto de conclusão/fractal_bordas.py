# -*- coding: utf-8 -*-
"""
Created on Mon Nov 19 17:10:46 2018

@author: ruben
"""
# fractal bordas

from PIL import Image
import random
imgx = 100
imgy = 100
image = Image.new("L", (imgx, imgy))

# direção dos pixels vizinhos
nx = [-1, -1, 0, 1, 1, 1, 0, -1]
ny = [0, 1, 1, 1, 0, -1, -1, -1]

while True:
    # random walk
    x = imgx #/ 2
    y = imgy #/ 2
    steps = 0
    flag = False
    while True:
        if image.getpixel((x, y)) == 0:
            # checar vizinhança
            for k in range(8):
                xn = x + nx[k]
                yn = y + ny[k]
                if xn < 0 or xn > (imgx - 1) or yn < 0 or yn > (imgy - 1):
                    image.putpixel((x, y), 255)
                    flag = True
                    break
                if image.getpixel((xn, yn)) > 0:
                    image.putpixel((x, y), 255)
                    flag = True
                    break
        if flag == True:
            break
        a = random.randint(0, 7)
        x = x + nx[a]
        y = y + ny[a]
        steps += 1
    if steps < 2:
        break

image.save("DLA_.png", "PNG")
