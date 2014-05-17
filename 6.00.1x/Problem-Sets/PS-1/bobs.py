s = 'azcbobobeggbobobhakl'
bobs = 0
for i in range(len(s)):
    if s[i:i+3] == 'bob':
        bobs += 1
print "Number of times bob occurs is: " + str(bobs)
