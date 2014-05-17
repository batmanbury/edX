# MITPY Problem Set 3: Radiation Exposure

def f(x):
    import math
    return 10*math.e**(math.log(0.5)/5.27 * x)

def radiationExposure(start, stop, step):
    '''
    Computes and returns the amount of radiation exposed
    to between the start and stop times. Calls the 
    function f (defined for you in the grading script)
    to obtain the value of the function at any point.
 
    start: integer, the time at which exposure begins
    stop: integer, the time at which exposure ends
    step: float, the width of each rectangle. You can assume that
      the step size will always partition the space evenly.

    returns: float, the amount of radiation exposed to 
      between start and stop times.
    '''
    # FILL IN YOUR CODE HERE...

    total = 0
    i = start
    while i < stop:
        total += f(i) * step
        i += step
    return total


print radiationExposure(40, 100, 1.5)


'''
Test case 1:
>>> radiationExposure(0, 5, 1)
39.10318784326239

Test case 2:
>>> radiationExposure(5, 11, 1)
22.94241041057671

Test case 3:
>>> radiationExposure(0, 11, 1)
62.0455982538

Test case 4:
>>> radiationExposure(40, 100, 1.5)
0.434612356115
'''
