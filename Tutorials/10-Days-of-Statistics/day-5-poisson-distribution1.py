import math

X = float(input())
k = int(input())

print(round(X**k * math.exp(-X) / (math.factorial(k)), 3))
