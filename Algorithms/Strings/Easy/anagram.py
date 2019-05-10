#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the anagram function below.
def anagram(s):
    if len(s) % 2 == 1:
        return -1
    
    freq = [0 for _ in range(26)]
    
    for c in s[0:len(s)//2]:
        freq[ord(c) - ord('a')]+=1
    
    for c in s[len(s)//2:]:
        freq[ord(c) - ord('a')]-=1
    
    total = 0
    for f in freq:
        total += abs(f)

    if total % 2 == 1:
        return -1
    return total//2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
