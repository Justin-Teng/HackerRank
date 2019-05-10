#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the closestNumbers function below.
def closestNumbers(arr):
    arr.sort()
    mindiff = 20000000
    for i in range(len(arr)-1):
        mindiff = min(mindiff, arr[i+1]-arr[i])
    
    result = []
    for i in range(len(arr)-1):
        if arr[i+1]-arr[i] == mindiff:
            result.append(arr[i])
            result.append(arr[i+1])
    
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = closestNumbers(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
