from sys import stdin

n = int(input())
d = {}
for _ in range(n):
    k, v = input().split()
    d[k] = v

for line in stdin:
    name = line.strip()
    item = d.get(name)
    if item:
        print("{}={}".format(name, item))
    else:
        print("Not found")
