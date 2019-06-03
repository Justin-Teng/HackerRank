#!/bin/python3

import math
import os

def sumdigits(n):
    total = 0
    while n:
        total += n % 10
        n //= 10
    return total

# Complete the solve function below.
def solve(n):
    if n == 1:
        return 0

    sumn = sumdigits(n)

    counttwo = 0
    while n > 0 and n % 2 == 0:
        n //= 2
        counttwo+=1
    
    sumprimes = counttwo * 2

    i = 3
    while n > 1:
        count = 0
        while n % i == 0:
            n //= i
            count+=1
        
        sumprimes += count * sumdigits(i)
        i += 2
    
    if sumprimes == sumn:
        return 1
    return 0

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = solve(n)

    fptr.write(str(result) + '\n')

    fptr.close()
