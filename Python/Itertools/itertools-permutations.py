from itertools import permutations

S, k = input().split()
print(*map(''.join, permutations(sorted(S), int(k))), sep='\n')
