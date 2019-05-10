#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the stringConstruction function below.
def stringConstruction(s):
    uniqueletters = [False for _ in range(26)]
    uniquecount = 0
    for c in s:
        if not uniqueletters[ord(c)-ord('a')]:
            uniqueletters[ord(c)-ord('a')] = True
            uniquecount+=1
    return uniquecount

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = stringConstruction(s)

        fptr.write(str(result) + '\n')

    fptr.close()
