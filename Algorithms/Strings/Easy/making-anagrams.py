#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makingAnagrams function below.
def makingAnagrams(s1, s2):
    freq1 = [0 for _ in range(26)]
    freq2 = [0 for _ in range(26)]

    for c in s1:
        freq1[ord(c) - ord('a')]+=1
    for c in s2:
        freq2[ord(c) - ord('a')]+=1
    
    total = 0
    for i in range(26):
        total += abs(freq1[i] - freq2[i])
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s1 = input()

    s2 = input()

    result = makingAnagrams(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
