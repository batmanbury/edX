# Unacceptable solution for using recursion

s = 'bobobobobosdgsdgbobobobobob'
def get_bobs(s):
    if s.find('bob') == -1:
        return 0
    elif s.find('bob') == 0:
        return 1 + get_bobs(s[2:])
    else:
        return 0 + get_bobs(s[1:])
print "Number of times bob occurs is: " + str(get_bobs(s))
