from math import factorial

def b(x,n,p):
    return factorial(n) / (factorial(x) * factorial(n-x)) * p**x * (1-p)**(n-x)

x, y = list(map(int, input().split()))

ans = 0
for i in range(0, 3):
    ans += b(i, y, x/100)
print(round(ans, 3))

ans = 0
for i in range(2, y+1):
    ans += b(i, y, x/100)

print(round(ans, 3))
