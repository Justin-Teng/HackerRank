a, b = list(map(int, input().split()))
c = int(input())
p = a/b
q = 1-p

print(round(q**(c-1) * p, 3))
