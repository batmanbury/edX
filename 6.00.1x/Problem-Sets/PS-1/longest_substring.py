# Prints the longest alphabetically sorted substring within string s

s = 'azcbobobegghakl'

def subcount(s):
    longest = ''
    current = ''
    for i in range(len(s)):
        for c in s[i:]:
            if current + c == ''.join(sorted(current + c)):
                current += c
            else:
                if len(current) > len(longest):
                    longest = current
                    current = ''
                    break
                else:
                    current = ''
                    break
    return longest


print 'Longest substring in alphabetical order is: ' + subcount(s)
