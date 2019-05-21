#!/bin/python3

import os

# Complete the balancedSums function below.
def balancedSums(arr):
    left = 0
    right = sum(arr)
    right -= arr[0]

    if left == right:
        return 'YES'

    for i in range(len(arr)-1):
        left += arr[i]
        right -= arr[i+1]
        if left == right:
            return 'YES'
        
    return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = balancedSums(arr)

        fptr.write(result + '\n')

    fptr.close()
