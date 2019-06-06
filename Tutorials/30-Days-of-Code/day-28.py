#!/bin/python3

import re

if __name__ == '__main__':
    N = int(input())
    names = []

    pattern = re.compile('@gmail\.com$')
    for N_itr in range(N):
        name, email = input().split()
        
        if re.search(pattern, email):
            names.append(name)
    
    print(*sorted(names), sep='\n')
