from collections import deque

N = int(input())

d = deque()

for _ in range(N):
    line = input().split()
    if (len(line) == 1):
        if (line[0] == 'pop'):
            d.pop()
        else:
            d.popleft()
    else:
        if (line[0] == 'append'):
            d.append(line[1])
        else:
            d.appendleft(line[1])
            
print(*d)
