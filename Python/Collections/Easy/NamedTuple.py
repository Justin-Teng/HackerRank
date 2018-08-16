from collections import namedtuple
N = int(input())
names = input().split()
mark_index = names.index("MARKS")
sum = 0
for i in range(N):
    sum += int(input().split()[mark_index])
print (sum / N)
