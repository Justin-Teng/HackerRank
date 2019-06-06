import math

t = int(input())
for _ in range(t):
    n = int(input())
    
    if n == 2:
        print('Prime')
        continue

    if n == 1 or n % 2 == 0:
        print('Not prime')
        continue
    
    flag = False
    for i in range(3, math.floor(math.sqrt(n))+1, 2):
        if n % i == 0:
            print('Not prime')
            flag = True
            break
    
    if not flag:
        print('Prime')
