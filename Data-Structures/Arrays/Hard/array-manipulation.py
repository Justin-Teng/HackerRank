#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    arr = [0 for _ in range(n+1)]
    
    for a, b, k in queries:
        arr[a] += k
        if b != n:
            arr[b+1] -= k
    
    currvalue = 0
    maxvalue = 0
    for x in arr:
        currvalue += x
        maxvalue = max(maxvalue, currvalue)
    
    return maxvalue

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
