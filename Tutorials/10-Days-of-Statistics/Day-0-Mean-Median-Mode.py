import statistics
from collections import Counter

N = int(input())
xs = list(map(int, input().split()))

c = Counter(xs)
mode_count = max(c.values())

mode_val = min([k for k,v in c.items() if v == mode_count])


print("{:.1f}\n{:.1f}\n{}".format(statistics.mean(xs), statistics.median(xs), mode_val))
