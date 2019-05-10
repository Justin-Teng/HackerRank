#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the palindromeIndex function below.
def palindromeIndex(s):
    i, j = 0, len(s)-1
    removedLeft = -1
    while True:
        if i >= j:
            return removedLeft
        if s[i] != s[j]:
            if removedLeft != -1:
                break
            removedLeft = i
            i+=1
        else:
            i+=1
            j-=1

    i, j = 0, len(s)-1
    removedRight = -1
    while True:
        if i >= j:
            return removedRight
        if s[i] != s[j]:
            if removedRight != -1:
                break
            removedRight = j
            j-=1
        else:
            i+=1
            j-=1

    return -1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()
