T = int(input())

for _ in range(T):
    n, m = list(map(int, input().split()))
    updates = {}
    for _ in range(m):
        line = list(input().split())
        if line[0] == "UPDATE":
            x, y, z, W = map(int, line[1:])
            updates[(x, y, z)] = W
        else:
            x1, y1, z1, x2, y2, z2 = map(int, line[1:])
            total = 0
            for k, v in updates.items():
                if k[0] >= x1 and k[0] <= x2 and k[1] >= y1 and k[1] <= y2 and k[2] >= z1 and k[2] <= z2:
                    total += v
            print(total)
