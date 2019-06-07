a, b = list(map(int, input().split()))
n = int(input())

p = a/b
q = 1-p

print(round(1 - (q**n), 3))
