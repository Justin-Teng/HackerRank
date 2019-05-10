#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the toys function below.
def toys(w):
    w.sort()
    
    numcontainers = 0
    smallest = -1
    
    for x in w:
        if smallest == -1:
            smallest = x
            numcontainers+=1
        elif x > smallest+4:
            smallest = x
            numcontainers+=1
    
    return numcontainers


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    w = list(map(int, input().rstrip().split()))

    result = toys(w)

    fptr.write(str(result) + '\n')

    fptr.close()
