#!/bin/python3

import os
import datetime

# Complete the time_delta function below.
def time_delta(t1, t2):
    dateformat = '%a %d %b %Y %H:%M:%S %z'
    
    d1 = datetime.datetime.strptime(t1, dateformat)
    d2 = datetime.datetime.strptime(t2, dateformat)
    
    return int(abs((d1 - d2).total_seconds()))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()

        t2 = input()

        delta = str(time_delta(t1, t2))

        fptr.write(delta + '\n')

    fptr.close()
