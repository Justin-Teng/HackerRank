from collections import Counter

input()
C = Counter(map(int, input().split()))

N = int(input())

sum = 0
for i in range(N):
    size, price = map(int, input().split())
    if C[size] != 0:
        sum += price
        C[size] -= 1
        
print(sum)
