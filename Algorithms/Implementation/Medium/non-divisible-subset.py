#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the nonDivisibleSubset function below.
def nonDivisibleSubset(k, S):
    d = {}
    
    for s in S:
        rem = s % k
        if rem in d:
            d[rem] += 1
        else:
            d[rem] = 1
    
    total = 0
    for s in S:
        rem = s%k
        complement = k - rem

        if d[rem] == -1:
            continue

        if rem == 0 or rem == complement:
            total += 1
            d[rem] = -1
            continue
        
        total += max(d.get(rem, 0), d.get(complement, 0))
        d[rem] = -1
        d[complement] = -1
    
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    S = list(map(int, input().rstrip().split()))

    result = nonDivisibleSubset(k, S)

    fptr.write(str(result) + '\n')

    fptr.close()
