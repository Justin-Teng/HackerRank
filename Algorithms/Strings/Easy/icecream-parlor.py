#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the icecreamParlor function below.
def icecreamParlor(m, arr):
    result = [-1, -1]
    s = set()
    
    for i in range(len(arr)):
        if m-arr[i] in s:
            result[0] = i+1
            result[1] = arr.index(m-arr[i])+1
            if result[0] > result[1]:
                result[0], result[1] = result[1], result[0]
            return result
        s.add(arr[i])
    
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        m = int(input())

        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = icecreamParlor(m, arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
