#!/bin/python3
import math

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n, k = map(int, input().split())
        
        if (k-1) | k <= n:
            print(k-1)
        else:
            print(k-2)
