#!/bin/python3

import os

def validcross(len1, h, w, grid):
    if h+((len1-1)//2) >= len(grid):
        return False

    if w+((len1-1)//2) >= len(grid[h]):
        return False
    
    if 'B' in grid[h][w-((len1-1)//2) : w+((len1-1)//2)+1]:
        return False
    
    for i in range(h-((len1-1)//2), h+((len1-1)//2)+1):
        if i >= len(grid):
            return False
        
        if grid[i][w] == 'B':
            return False
    
    return True

def validcross2(len1, h, w, len2, h2, w2, grid):
    if h2+((len2-1)//2) >= len(grid):
        return False

    if w2+((len2-1)//2) >= len(grid[h]):
        return False
    
    for i in range(w-((len1-1)//2), w+((len1-1)//2)+1):
        grid[h][i] = 'B'
    
    for i in range(h-((len1-1)//2), h+((len1-1)//2)+1):
        grid[i][w] = 'B'
    
    flag = False

    if 'B' in grid[h2][w2-((len2-1)//2) : w2+((len2-1)//2)+1]:
        flag = True
    
    if not flag:
        for i in range(h2-((len2-1)//2), h2+((len2-1)//2)+1):
            if i >= len(grid):
                flag = True
                break
            
            if grid[i][w2] == 'B':
                flag = True
                break
    
    for i in range(w-((len1-1)//2), w+((len1-1)//2)+1):
        grid[h][i] = 'G'
    
    for i in range(h-((len1-1)//2), h+((len1-1)//2)+1):
        grid[i][w] = 'G'
    
    if flag:
        return False
    return True

# Complete the twoPluses function below.
def twoPluses(grid):
    height = len(grid)
    width = len(grid[0])
    maxdimension = max(height, width)

    maxproduct = 0

    for len1 in range(1, maxdimension+1, 2):
        print('length1: {}'.format(len1))
        for h in range((len1-1)//2, height):
            for w in range((len1-1)//2, width):
                # Check for first valid cross
                if validcross(len1, h, w, grid):
                    for len2 in range(1, maxdimension+1, 2):
                        for h2 in range((len2-1)//2, height):
                            for w2 in range((len2-1)//2, width):
                                # Check for second valid cross
                                if validcross2(len1, h, w, len2, h2, w2, grid):
                                    p = (2*(len1-1)+1) * (2*(len2-1)+1)
                                    maxproduct = max(maxproduct, p)

    return maxproduct

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    grid = []

    for _ in range(n):
        grid_item = list(input())
        grid.append(grid_item)

    result = twoPluses(grid)

    fptr.write(str(result) + '\n')

    fptr.close()
