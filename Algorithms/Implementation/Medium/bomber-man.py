#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    rcn = input().split()

    r = int(rcn[0])

    c = int(rcn[1])

    n = int(rcn[2])

    grid = []

    for _ in range(r):
        grid_item = list(input())
        grid.append(grid_item)

    for i in range(r):
        for j in range(c):
            if grid[i][j] == '.':
                grid[i][j] = False
            else:
                grid[i][j] = True

    grid1 = [[False for _ in range(c)] for _ in range(r)]
    grid2 = [[False for _ in range(c)] for _ in range(r)]

    it = 0

    for i in range(r):
        for j in range(c):
            if grid[i][j]:
                grid1[i][j] = True
            else:
                grid1[i][j] = False

    it = 1

    if n >= 2:
        it = 2
        for i in range(r):
            for j in range(c):
                if grid1[i][j]:
                    grid2[i][j] = False
                elif i != 0 and grid1[i-1][j]:
                    grid2[i][j] = False
                elif i != r-1 and grid1[i+1][j]:
                    grid2[i][j] = False
                elif j != 0 and grid1[i][j-1]:
                    grid2[i][j] = False
                elif j != c-1 and grid1[i][j+1]:
                    grid2[i][j] = False
                else:
                    grid2[i][j] = True

        for i in range(r):
            for j in range(c):
                grid[i][j] = True

    if n >= 3:
        it = 3
        for i in range(r):
            for j in range(c):
                if grid1[i][j]:
                    grid[i][j] = False
                    if i != 0:
                        grid[i-1][j] = False
                    if i != r-1:
                        grid[i+1][j] = False
                    if j != 0:
                        grid[i][j-1] = False
                    if j != c-1:
                        grid[i][j+1] = False
                grid1[i][j] = False


    while (n > 3):
        it += 1
        for i in range(r):
            for j in range(c):
                grid[i][j] = True
                if grid2[i][j]:
                    grid1[i][j] = False
                elif i != 0 and grid2[i-1][j]:
                    grid1[i][j] = False
                elif i != r-1 and grid2[i+1][j]:
                    grid1[i][j] = False
                elif j != 0 and grid2[i][j-1]:
                    grid1[i][j] = False
                elif j != c-1 and grid2[i][j+1]:
                    grid1[i][j] = False
                else:
                    grid1[i][j] = True
        if n % 2 == 0:
            break

        it += 1
        for i in range(r):
            for j in range(c):
                if grid2[i][j]:
                    grid[i][j] = False
                    if i != 0:
                        grid[i-1][j] = False
                    if i != r-1:
                        grid[i+1][j] = False
                    if j != 0:
                        grid[i][j-1] = False
                    if j != c-1:
                        grid[i][j+1] = False
                grid2[i][j] = False
        
        print(it)
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    print('O',end='')
                else:
                    print('.',end='')
            print('')
        if n % 4 == 1:
            break

        it += 1
        for i in range(r):
            for j in range(c):
                grid[i][j] = True
                if grid1[i][j]:
                    grid2[i][j] = False
                elif i != 0 and grid1[i-1][j]:
                    grid2[i][j] = False
                elif i != r-1 and grid1[i+1][j]:
                    grid2[i][j] = False
                elif j != 0 and grid1[i][j-1]:
                    grid2[i][j] = False
                elif j != c-1 and grid1[i][j+1]:
                    grid2[i][j] = False
                else:
                    grid2[i][j] = True

        it += 1
        for i in range(r):
            for j in range(c):
                if grid1[i][j]:
                    grid[i][j] = False
                    if i != 0:
                        grid[i-1][j] = False
                    if i != r-1:
                        grid[i+1][j] = False
                    if j != 0:
                        grid[i][j-1] = False
                    if j != c-1:
                        grid[i][j+1] = False
                grid1[i][j] = False
        break

    for i in range(r):
        for j in range(c):
            if grid[i][j]:
                fptr.write('O')
            else:
                fptr.write('.')
        fptr.write('\n')

    fptr.close()
