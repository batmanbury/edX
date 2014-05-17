# MIT 6.00.2x
# Quiz
# Problem 5-1

"""
You are taking a class that plans to assign final grades based on two
midterm quizzes and a final exam. The final grade will be based on 25%
for each midterm, and 50% for the final. You are told that the grades
on the exams were each uniformly distributed integers:

Midterm 1: 50 <= grade <= 80
Midterm 2: 60 <= grade <= 90
Final Exam: 55 <= grade <= 95

Write a function called sampleQuizzes that implements a Monte Carlo
simulation that estimates the probability of a student having a final
score >= 70 and <= 75. Assume that 10,000 trials are sufficient to
provide an accurate answer.
"""

import random

def sampleQuizzes():
    def hitsGradeWindow():        
        mid1 = random.randint(50, 81)
        mid2 = random.randint(60, 91)
        exam = random.randint(55, 96)
        g = mid1*0.25 + mid2*0.25 + exam*0.5
        if g >= 70 and g <= 75:
            return True
        return False

    trials = 10000.0
    hits = 0
    for __ in xrange(trials):
        if hitsGradeWindow():
            hits += 1

    probability = hits / trials
    return probability


#sampleQuizzes()

def generateScores(numTrials):
    """
    Runs numTrials trials of score-generation for each of
    three exams (Midterm 1, Midterm 2, and Final Exam).
    Generates uniformly distributed scores for each of 
    the three exams, then calculates the mean score and
    appends it to a list of scores.
    
    Returns: A list of numTrials scores.
    """
    #PROVIDED BY GRADER#

def plotQuizzes():
    scores = generateScores(10000)
    pylab.hist(scores, bins=7)
    pylab.title('Distribution of Scores')
    pylab.xlabel('Final Score')
    pylab.ylabel('Number of Trials')
    pylab.show()


#plotQuizzes()
