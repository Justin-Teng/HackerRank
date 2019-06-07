N = int(input())
X = list(map(int, input().split()))
W = list(map(int, input().split()))

sumW = 0
for i in range(N):
    X[i] *= W[i]
    sumW += W[i]

print("{:.1f}".format(sum(X) / sumW))
