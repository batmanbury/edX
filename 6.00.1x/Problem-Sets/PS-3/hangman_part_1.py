# MITPY Problem Set 3: Hangman Part 1

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    secretClone = []
    for char in secretWord:
        secretClone.append(char)
        if char in lettersGuessed:
            for letter in secretClone:
                if char == letter:
                    secretClone.remove(letter)
    return len(secretClone) == 0


def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    secretClone = []
    for char in secretWord:
        secretClone.append(char)
    for i in range(len(secretClone)):
        if (secretClone[i] in lettersGuessed) == False:
            secretClone[i] = '_ '
    return ''.join(secretClone)


def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    import string
    available = list(string.ascii_lowercase)
    for letter in lettersGuessed:
        available.remove(letter)
    return ''.join(available)

