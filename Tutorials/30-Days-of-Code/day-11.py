#!/bin/python3

if __name__ == '__main__':
    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    max_sum = -63
    
    for i in range(4):
        for j in range(4):
            s = sum(arr[i][j:j+3]) + arr[i+1][j+1] + sum(arr[i+2][j:j+3])
            max_sum = max(s, max_sum)
    
    print(max_sum)
