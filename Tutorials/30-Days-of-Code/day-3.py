#!/bin/python3

if __name__ == '__main__':
    N = int(input())
    print("Weird") if N % 2 or N >= 6 and N <= 20 else print("Not Weird")
