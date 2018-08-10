#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter
from operator import itemgetter

if __name__ == '__main__':
    s = input()
    c = Counter()
    for ch in s:
        c[ch] += 1
    x = list(c.items())
    x.sort(key=itemgetter(0))
    x.sort(key=itemgetter(1), reverse=True)
    for i in range(3):
        print("{0} {1}".format(x[i][0], x[i][1]))
