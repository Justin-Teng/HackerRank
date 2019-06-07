import math

def b(x, n, p):
    return math.factorial(n) / (math.factorial(x) * math.factorial(n-x)) * p**x * (1-p)**(n-x)

p, q = list(map(float, input().split()))
boy = p / (p+q)

ans = 0
for i in range(3, 7):
    ans += b(i, 6, boy)

print(round(ans, 3))
