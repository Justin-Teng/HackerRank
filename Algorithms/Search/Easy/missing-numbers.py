#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the missingNumbers function below.
def missingNumbers(arr, brr):
    x = brr[0]
    freq = [0 for _ in range(201)]
    
    for a in arr:
        freq[a - x + 100]-=1
    for b in brr:
        freq[b - x + 100]+=1
    
    result = []
    for i in range(len(freq)):
        if freq[i] > 0:
            result.append(x + i - 100)
    
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    m = int(input())

    brr = list(map(int, input().rstrip().split()))

    result = missingNumbers(arr, brr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
