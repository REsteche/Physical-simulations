# -*- coding: utf-8 -*-
"""
Created on Tue Apr 19 11:42:43 2022

@author: ruben
"""
import random
import numpy
import matplotlib.pyplot as plt
import os
from matplotlib import colors


def checkAround(location,squareSize,matrix):
	foundFriend = False #found another particle
	exitCircle = False #reached the required radius
	nearEdge=False #near the edge of the field
	
	
    # Check if a walker is near the edge
	if (location[1] + 1) > squareSize - 1 or (location[1] - 1) < 1 or (location[0] + 1) > squareSize - 1 or (location[0] - 1) < 1:
		nearEdge = True

    # If not near the edge, check if the walker is near a neighbor or reached the required radius
    # location[1]=row, location[2]=column
	if not nearEdge:
		neighborDown = matrix[location[1]+1,location[0]]
		if neighborDown == 1:
			foundFriend = True
		if neighborDown == 2:
			exitCircle = True

		neighborUp=matrix[location[1]-1,location[0]]
		if neighborUp==1:
			foundFriend=True
		if neighborUp==2:
			exitCircle=True

		neighborRight=matrix[location[1],location[0]+1]
		if neighborRight==1:
			foundFriend=True
		if neighborRight==2:
			exitCircle=True

		neighborLeft=matrix[location[1],location[0]-1]
		if neighborLeft==1:
			foundFriend=True
		if neighborLeft==2:
			exitCircle=True

    # After checking locations, if locations are good, start the random walk
	if not foundFriend and not nearEdge:
		decide = random.random()
		if decide<0.25:
			location = [location[0] - 1,location[1]]
		elif decide<0.5:
			location = [location[0] + 1,location[1]]
		elif decide<0.75:
			location = [location[0],location[1] + 1]
		else:
			location = [location[0],location[1] - 1]

	return (location, foundFriend, nearEdge, exitCircle)

def randomAtRadius(radius, seedX, seedY):
    theta = 2*numpy.pi*random.random() #generate random theta
    x=int(radius*numpy.cos(theta))+seedX #use trig to transfer into X
    y=int(radius*numpy.sin(theta))+seedY #find Y coordinate
    location=[x, y] #save locaction
    return location


def DLAcluster(radius, needGif):
    
    #check if folder "images" exists, and if not - create it
    if not os.path.isdir("images"):
        os.mkdir("images")
    
    if needGif:
        #Import there libraries if intend to save gif
        #NOTE: need imageio package, and ffmpeg. Refer to readme for more info
        import imageio

    
    #initialize variables that are dependent upon the radius
    # note - we add 2 to the parameters to get a thick broder between the edges of the disk and square
    # x coordinate of a seed particle
    seedX = radius+2 
    # y coordinate of a seed
    seedY = radius+2 
    # size of the grid to account for field of wandering around
    squareSize = radius*2+5

    matrix=numpy.zeros((squareSize, squareSize))

    for row in range (0,squareSize):
        for col in range (0,squareSize):
            #put a seed particle
            if row==seedY and col==seedX: 
                matrix[row][col]=1
            #define field outside of circle
            elif numpy.sqrt((seedX-col)**2+(seedY-row)**2)>radius:
                matrix[row][col]=2
    cmap = colors.ListedColormap(['navy','white', 'navy'])

    # Initialize the random walker counter
    randomWalkersCount = 0

    # Set the cluster to NOT be complete
    completeCluster = False

    # Start running random walkers
    addedCount=0 #keep track of number added

    # initialize array for the used interval for graphing
    usedInterval=[]

    while not completeCluster:
        # Release a walker
        randomWalkersCount += 1
        random.seed()

        # Generate a (Xstart, Ystart) for walker, need within radius
        location=randomAtRadius(radius, seedX, seedY)

        # Initialize variables, like Friend tag and near edge identifier
        foundFriend = False #not near other particle
        nearEdge=False #not near the edge of the field


        # Set an individual walker out, stop if found a 'friend', give up if it reached the edge of the board
        while not foundFriend and not nearEdge:
            # Run the checking/walking function
            locationNew,foundFriend, nearEdge, exitCircle = checkAround(location,squareSize,matrix)

            # Add to the cluster if near a friend
            if foundFriend:
                # current location, replace with 1 and stop
                matrix[location[1]][location[0]] = 1
                addedCount+=1

            # Otherwise, save the location
            else:
                location = locationNew
        
        #print update 
        intervalSavePic=range(2,400000,500)
        if randomWalkersCount in intervalSavePic:
            print("still working, have added ", randomWalkersCount, " random walkers.", " Added to cluster: ", addedCount)
        if needGif:
            if randomWalkersCount in intervalSavePic:
                print("save picture")
                usedInterval.append(randomWalkersCount) #append to the used count
                label=str(randomWalkersCount)
                plt.title("DLA Cluster", fontsize=20)
                plt.matshow(matrix, interpolation='nearest',cmap=cmap)#plt.cm.Blues) #ocean, Paired
                plt.xlabel("direction, $x$", fontsize=15)
                plt.ylabel("direction, $y$", fontsize=15)
                plt.savefig("images/cluster{}.png".format(label), dpi=200)
                plt.close()
       
        if randomWalkersCount==400000:
            print("CAUTION: had to break the cycle, taking too many iterations")
            completeCluster = True

        # Once it finds a friend and leaves the previous loop, we must check if it
        # is also touching a circular wall. If so, we have a complete cluster
        if foundFriend and exitCircle:
            print("Random walkers in the cluster: ",addedCount)
            completeCluster = True
    
    plt.title("DLA Cluster", fontsize=20)
    plt.matshow(matrix, interpolation='nearest',cmap=cmap)#plt.cm.Blues) #ocean, Paired
    plt.xlabel("direction, $x$", fontsize=15)
    plt.ylabel("direction, $y$", fontsize=15)
    plt.savefig("images/cluster.png", dpi=200)
    plt.close()

    print(usedInterval)

    if needGif:
        with imageio.get_writer('images/movie.gif', mode='I') as writer:
            for i in usedInterval:
                filename="images/cluster"+str(i)+".png"
                image = imageio.imread(filename)
                writer.append_data(image)
                os.remove(filename)
            image = imageio.imread("images/cluster.png")
            writer.append_data(image)

    return addedCount, matrix


#### NOTE: input to the function is (RADIUS, needGif), where 
# need gif defines whether the .gif for the cluster is created

#### NOTE 2: .gif creation takes a lot of space: first images are saved one by one, 
# then collapsed into the .gif, and intermediate files are deleted.
# Large radius results in large .gif file 

#### NOTE 3: folder "/images" is created if not present, and final cluster image is always saved

#### NOTE 4: radius>100 takes some time to run. Gif files are relatively large in this case

mass,matrix=DLAcluster(100,True) #import radius and True/False for GIF