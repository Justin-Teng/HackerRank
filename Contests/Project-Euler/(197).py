import math

u, b = map(float, input().split())

for _ in range(10000000):
    u = math.floor(2**(b-u*u)) * 0.000000001

fu = math.floor(2**(b-u*u)) * 0.000000001
print(u+fu)
