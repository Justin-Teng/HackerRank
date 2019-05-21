#!/bin/python3

import os
from operator import itemgetter

# Complete the jimOrders function below.
def jimOrders(orders):
    times = list(map(sum, orders))
    
    for i in range(len(times)):
        times[i] = (i+1, times[i])
    
    times.sort(key=itemgetter(1))
    
    return [x[0] for x in times]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    orders = []

    for _ in range(n):
        orders.append(list(map(int, input().rstrip().split())))

    result = jimOrders(orders)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
