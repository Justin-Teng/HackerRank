#!/bin/python3

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))

totalswaps = 0

for _ in range(n):
    numswaps = 0
    
    for j in range(n-1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            numswaps+=1
    
    totalswaps += numswaps
    
    if numswaps == 0:
        break

print('Array is sorted in {} swaps.'.format(totalswaps))
print('First Element: {}'.format(a[0]))
print('Last Element: {}'.format(a[-1]))
