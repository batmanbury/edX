# MIT 6.00.2x
# Quiz
# Problem 6-1

"""
You observe that the probability of first seeing a 1 on the n-th die roll
decreases as n increases. You would like to know the smallest number of
rolls such that this probability is less than some limit. Complete the
Python procedure, probTest, to compute this.
"""

def probTest(limit):
    rolls = 1
    n = 1.0/6
    while n > limit:
        n *= 5.0/6
        rolls += 1
    return rolls

print probTest(5/36.0)
