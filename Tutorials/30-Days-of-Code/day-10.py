#!/bin/python3

if __name__ == '__main__':
    n = int(input())
    n_bin = bin(n)[2:]
    max_count = 0
    count = 0
    
    for b in n_bin:
        if b == '1':
            count+=1
        else:
            max_count = max(max_count, count)
            count = 0
            
    print(max(max_count, count))
