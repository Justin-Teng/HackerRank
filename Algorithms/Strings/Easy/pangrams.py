#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the pangrams function below.
def pangrams(s):
    letters = [False for _ in range(26)]
    for c in s:
        if not c.isalpha():
            continue
        letters[ord(c.lower()) - ord('a')] = True
    for letter in letters:
        if not letter:
            return 'not pangram'
    return 'pangram'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
