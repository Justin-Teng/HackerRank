#!/usr/bin/python

def displayPathtoPrincess(n,grid):
    foundm = foundp = False
    for i in range(len(grid)):
        if not foundm and grid[i].find('m') != -1:
            m_x = grid[i].find('m')
            m_y = i
            foundm = True
        if not foundp and grid[i].find('p') != -1:
            p_x = grid[i].find('p')
            p_y = i
            foundp = True
    while m_x < p_x:
        print("RIGHT")
        m_x+=1
    while m_x > p_x:
        print("LEFT")
        m_x-=1
    while m_y < p_y:
        print("DOWN")
        m_y+=1
    while m_y > p_y:
        print("UP")
        m_y-=1

m = int(input())
grid = [] 
for i in range(0, m): 
    grid.append(input().strip())

displayPathtoPrincess(m,grid)
