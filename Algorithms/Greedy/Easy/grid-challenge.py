#!/bin/python3

import os

# Complete the gridChallenge function below.
def gridChallenge(grid):
    for row in grid:
        row.sort()
    
    for row in range(len(grid)-1):
        for col in range(len(grid[row])):
            if ord(grid[row][col]) > ord(grid[row+1][col]):
                return 'NO'
    
    return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        grid = []

        for _ in range(n):
            grid_item = list(input())
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
