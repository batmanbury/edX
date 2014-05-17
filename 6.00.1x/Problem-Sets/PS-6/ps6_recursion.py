# 6.00x Problem Set 6
#
# Part 2 - RECURSION

#
# Problem 3: Recursive String Reversal
#
def reverseString(aStr):
    """
    Given a string, recursively returns a reversed copy of the string.
    For example, if the string is 'abc', the function returns 'cba'.
    The only string operations you are allowed to use are indexing,
    slicing, and concatenation.
    
    aStr: a string
    returns: a reversed string
    """
    if len(aStr) == 0:
        return ''
    else:
        return aStr[-1] + reverseString(aStr[:-1])

print 'racecar' + ' = ' + reverseString('racecar')
print 'devil' + ' = ' + reverseString('devil')
print 'emordnilap' + ' = ' + reverseString('emordnilap')
print ''

#
# Problem 4: X-ian
#
def x_ian(x, word):
    """
    Given a string x, returns True if all the letters in x are
    contained in word in the same order as they appear in x.

    >>> x_ian('eric', 'meritocracy')
    True
    >>> x_ian('eric', 'cerium')
    False
    >>> x_ian('john', 'mahjong')
    False
    
    x: a string
    word: a string
    returns: True if word is x_ian, False otherwise
    """
    if len(word) == 1:
        return word in x
    if word[0] in x:
        return x_ian(x[x.index(word[0]) + 1:], word[1:])
    else:
        return False

print 'eric' + ' contained in ' + 'meritocracy' + ' = ' + str(x_ian('eric', 'meritocracy'))
print 'john' + ' contained in ' + 'mahjong' + ' = ' + str(x_ian('john', 'mahjong'))
print ''

#
# Problem 5: Typewriter
#
def insertNewlines(text, lineLength):
    """
    Given text and a desired line length, wrap the text as a typewriter would.
    Insert a newline character ("\n") after each word that reaches or exceeds
    the desired line length.

    text: a string containing the text to wrap.
    line_length: the number of characters to include on a line before wrapping
        the next word.
    returns: a string, with newline characters inserted appropriately. 
    """
    assert lineLength > len(max(text.split(), key = len))
    
    if len(text) < lineLength:
        return text
    
    elif text[lineLength] == ' ':
        return text[:lineLength + 1] + '\n' + insertNewlines(text[lineLength + 1:], lineLength)
    
    else:
        return text[:lineLength] + text[lineLength:text.find(' ',lineLength) + 1] + '\n' + insertNewlines(text[text.find(' ',lineLength) + 1:], lineLength)

text = 'Given text and a desired line length, wrap the text as a typewriter would. Insert a newline character after each word that reaches or exceeds the desired line length.'
print insertNewlines(text, 20)
