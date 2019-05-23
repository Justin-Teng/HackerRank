import re

t = int(input())
for _ in range(t):
    s = input()
    
    m = re.match(r'^[+-]?[0-9]*\.[0-9]+$', s)
    if m:
        print('True')
    else:
        print('False')
