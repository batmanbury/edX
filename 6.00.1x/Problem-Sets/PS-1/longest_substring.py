# Prints the longest alphabetically sorted substring within string s

s = 'azcbobobegghakl'

strings = []
alphas = []

for j in range(len(s)+1):
    for i in range(len(s)):
        if s[i:j] != '':
            strings.append(s[i:j])

for substring in strings:
    if substring == ''.join(sorted(substring)):
        alphas.append(substring)

print max(alphas, key=len)
