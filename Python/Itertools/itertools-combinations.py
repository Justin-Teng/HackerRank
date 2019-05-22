from itertools import combinations

S, k = input().split()
S = sorted(S)
k = int(k)

for i in range(k):
    for c in combinations(S, i+1):
        print(''.join(c))
