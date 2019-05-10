#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the weightedUniformStrings function below.
def weightedUniformStrings(s, queries):
    counts = [0 for _ in range(26)]
    
    length = 1
    for i in range(len(s)):
        if i != len(s)-1:
            if s[i] == s[i+1]:
                length+=1
            else:
                length = 1
        counts[ord(s[i]) - ord('a')] = max(counts[ord(s[i]) - ord('a')], length)
    
    result = []

    for q in queries:
        flag = False
        for i in range(26):
            if q % (i+1) == 0 and counts[i] >= q / (i+1):
                result.append('Yes')
                flag = True
                break
        if not flag:
            result.append('No')
    
    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
