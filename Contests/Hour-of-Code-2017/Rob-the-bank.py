N, M = list(map(int, input().split()))

grid = [['@' for x in range(M)] for y in range(N)]

for i in range(N):
    line = input()
    for j in range(M):
        grid[i][j] = line[j]
alreadySeen = False
jr = jc = -1
for i in range(N):
    if alreadySeen:
        break
    for j in range(M):
        if (alreadySeen):
            break
        ch = grid[i][j]
        if ch == 'N':
            for k in range(i-1, -1, -1):
                if grid[k][j] == '.':
                    grid[k][j] = '*'
                elif grid[k][j] == 'J':
                    alreadySeen = True
                    break
                elif grid[k][j] == 'M':
                    alreadySeen = True
                    break
                elif grid[k][j] == '#':
                    break
        elif (ch == 'S'):
            for k in range(i+1, N):
                if grid[k][j] == '.':
                    grid[k][j] = '*'
                elif (grid[k][j] == 'J'):
                    alreadySeen = True
                    break;
                elif grid[k][j] == 'M':
                    alreadySeen = True
                    break
                elif grid[k][j] == '#':
                    break
        elif (ch == 'W'):
            for k in range(j-1, -1, -1):
                if grid[i][k] == '.':
                    grid[i][k] = '*'
                elif grid[i][k] == 'J':
                    alreadySeen = True
                    break;
                elif grid[i][k] == 'M':
                    alreadySeen = True
                    break
                elif grid[i][k] == '#':
                    break;
        elif (ch == 'E'):
            for k in range(j+1, M):
                if grid[i][k] == '.':
                    grid[i][k] = '*'
                elif grid[i][k] == 'J':
                    alreadySeen = True
                    break;
                elif grid[i][k] == 'M':
                    alreadySeen = True
                    break
                elif grid[i][k] == '#':
                    break;
        elif (ch == 'J'):
            jr = i
            jc = j
            
possible = False
if not alreadySeen:
    stack = []
    
    grid[jr][jc] = '+'
    if grid[jr][jc+1] == '.':
        stack.append((jr, jc+1))
    elif grid[jr][jc+1] == 'M':
        possible = True
    if grid[jr][jc-1] == '.':
        stack.append((jr, jc-1))
    elif grid[jr][jc-1] == 'M':
        possible = True
    if grid[jr-1][jc] == '.':
        stack.append((jr-1, jc))
    elif grid[jr-1][jc] == 'M':
        possible = True
    if grid[jr+1][jc] == '.':
        stack.append((jr+1, jc))
    elif grid[jr+1][jc] == 'M':
        possible = True
    
    while not possible and stack:
        r, c = stack.pop()
        grid[r][c] = '+'
        if grid[r][c+1] == '.':
            stack.append((r, c+1))
        elif grid[r][c+1] == 'M':
            possible = True
        if grid[r][c-1] == '.':
            stack.append((r, c-1))
        elif grid[r][c-1] == 'M':
            possible = True
        if grid[r-1][c] == '.':
            stack.append((r-1, c))
        elif grid[r-1][c] == 'M':
            possible = True
        if grid[r+1][c] == '.':
            stack.append((r+1, c))
        elif grid[r+1][c] == 'M':
            possible = True

if possible:
    print("YES")
else:
    print("NO")
