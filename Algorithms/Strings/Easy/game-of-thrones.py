#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the gameOfThrones function below.
def gameOfThrones(s):
    evenfreq = [True for _ in range(26)]
    
    for c in s:
        i = ord(c) - ord('a')
        evenfreq[i] = not evenfreq[i]
    
    flag = False
    for p in evenfreq:
        if not p:
            if flag:
                return "NO"
            flag = True
    
    return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = gameOfThrones(s)

    fptr.write(result + '\n')

    fptr.close()
