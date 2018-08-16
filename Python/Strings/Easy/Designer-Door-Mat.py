N, M = map(int, input().split(' '))

# top half
for i in range(N//2):
    temp = ['.|.']
    for _ in range(i):
        temp += '.|..|.'
    str = ''.join(temp)
    print(str.center(M, '-'))

# WELCOME message
print('WELCOME'.center(M, '-'))

# bottom half
for i in range(N//2-1, -1, -1):
    temp = ['.|.']
    for _ in range(i):
        temp += '.|..|.'
    str = ''.join(temp)
    print(str.center(M, '-'))
