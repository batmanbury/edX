# MIT 6.00.2x
# Random Drunk Walks
# Location, Field, and Drunk classes

import math
import pylab
import random


# Location and Field classes
class Location(object):
    def __init__(self, x, y):
        """x and y are floats"""
        self.x = x
        self.y = y
        
    def move(self, deltaX, deltaY):
        """deltaX and deltaY are floats"""
        return Location(self.x + deltaX, self.y + deltaY)
    
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
    def distFrom(self, other):
        ox = other.x
        oy = other.y
        xDist = self.x - ox
        yDist = self.y - oy
        return (xDist**2 + yDist**2)**0.5
    
    def __str__(self):
        return '<' + str(self.x) + ', ' + str(self.y) + '>'

class Field(object):
    def __init__(self):
        self.drunks = {}
        
    def addDrunk(self, drunk, loc):
        if drunk in self.drunks:
            raise ValueError('Duplicate drunk')
        else:
            self.drunks[drunk] = loc
            
    def moveDrunk(self, drunk):
        if not drunk in self.drunks:
            raise ValueError('Drunk not in field')
        xDist, yDist = drunk.takeStep()
        currentLocation = self.drunks[drunk]
        #use move method of Location to get new location
        self.drunks[drunk] = currentLocation.move(xDist, yDist)
        
    def getLoc(self, drunk):
        if not drunk in self.drunks:
            raise ValueError('Drunk not in field')
        return self.drunks[drunk]

# Drunk classes
class Drunk(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'This drunk is named ' + self.name

class UsualDrunk(Drunk):
    def takeStep(self):
        stepChoices =\
            [(0.0,1.0), (0.0,-1.0), (1.0, 0.0), (-1.0, 0.0)]
        return random.choice(stepChoices)

class ColdDrunk(Drunk):
    def takeStep(self):
        stepChoices =\
            [(0.0,0.9), (0.0,-1.03), (1.03, 0.0), (-1.03, 0.0)]
        return random.choice(stepChoices)

class EDrunk(Drunk):
    def takeStep(self):
        ang = 2 * math.pi * random.random()
        length = 0.5 + 0.5 * random.random()
        return (length * math.sin(ang), length * math.cos(ang))

class PhotoDrunk(Drunk):
    def takeStep(self):
        stepChoices =\
                    [(0.0, 0.5),(0.0, -0.5),
                     (1.5, 0.0),(-1.5, 0.0)]
        return random.choice(stepChoices)

class DDrunk(Drunk):
    def takeStep(self):
        stepChoices =\
                    [(0.85, 0.85), (-0.85, -0.85),
                     (-0.56, 0.56), (0.56, -0.56)] 
        return random.choice(stepChoices)

"""
Returns the actual x and y distance from the start point to the
end point of a random walk.
"""
def walkVector(f, d, numSteps):
    start = f.getLoc(d)
    for s in range(numSteps):
        f.moveDrunk(d)
    return(f.getLoc(d).getX() - start.getX(),
           f.getLoc(d).getY() - start.getY())

#
# Simulations
#

# Drunks
u = UsualDrunk('UsualDrunk')
c = ColdDrunk('ColdDrunk')
e = EDrunk('EDrunk')
p = PhotoDrunk('PhotoDrunk')
d = DDrunk('DDrunk')

# Fields
uF = Field()
cF = Field()
eF = Field()
pF = Field()
dF = Field()

drunks = [u, c, e, p, d]
fields = [uF,cF,eF,pF,dF]

# Add drunks to fields
for i in range(5):
    fields[i].addDrunk(drunks[i], Location(0,0))

# Move the drunks and record their steps
numTrials = 500
numSteps = 1000

for f in range(len(fields)):
    destX = []
    destY = []
    for __ in range(numTrials):
        v = walkVector(fields[f], drunks[f], numSteps)
        destX.append(v[0])
        destY.append(v[1])
    pylab.figure(f)
    pylab.title(drunks[f].name)
    pylab.scatter(destX, destY)

# Display scatter plot for each Drunk
pylab.show()
