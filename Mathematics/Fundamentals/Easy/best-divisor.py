#!/bin/python3

import math

def sumdigits(n):
    total = 0
    while n:
        total += n % 10
        n //= 10
    return total

if __name__ == '__main__':
    n = int(input())
    most_value = 0
    most_num = 0

    for i in range(1, math.floor(math.sqrt(n))+1):
        if n % i != 0:
            continue
        
        value = sumdigits(i)
        value2 = sumdigits(n//i)
        
        if value > most_value:
            most_value = value
            most_num = i
        elif value == most_value:
            most_num = min(i, most_num)
        
        if value2 > most_value:
            most_value = value2
            most_num = n//i
        elif value2 == most_value:
            most_num = min(n//i, most_num)
    
    print(most_num)
