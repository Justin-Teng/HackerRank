#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the separateNumbers function below.
def separateNumbers(s):
    if s[0] == '0':
        print('NO')
        return

    for i in range(1, (len(s)//2)+1):
        numdigits = i
        j = 0
        while True:
            x = int(s[j:j+numdigits])
            y = str(x+1)
            
            if j+numdigits == len(s):
                print("YES " + s[0:i])
                return
            
            if j+numdigits+len(y) > len(s):
                break

            if s[j+numdigits:j+numdigits+len(y)] != y:
                break

            j += numdigits
            numdigits = len(y)
    
    print("NO")
    return


if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)
