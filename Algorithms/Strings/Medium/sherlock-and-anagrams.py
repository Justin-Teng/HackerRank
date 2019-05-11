#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s):
    total = 0
    for i in range(1, len(s)):
        substrings = []
        for j in range(len(s)-i+1):
            substrings.append(sorted(s[j:j+i]))
        substrings.sort()

        subtotal = 1
        for j in range(len(substrings)-1):
            if substrings[j] == substrings[j+1]:
                subtotal+=1
            else:
                total += (subtotal*(subtotal-1)) // 2
                subtotal = 1
        
        total += (subtotal*(subtotal-1)) // 2

    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
