import re

S = input()
k = input()

m = list(re.finditer(r'(?={})'.format(k), S))
if m:
    for match in m:
        print('({}, {})'.format(match.start(), match.start()+len(k)-1))
else:
    print('(-1, -1)')
