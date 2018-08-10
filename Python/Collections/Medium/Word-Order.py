from collections import OrderedDict

od = OrderedDict()

n = int(input())

for _ in range(n):
    word = input()
    if (od.get(word)):
        od[word] += 1
    else:
        od[word] = 1
        
print(len(od))
for key, value in od.items():
    print(value, end=' ')
