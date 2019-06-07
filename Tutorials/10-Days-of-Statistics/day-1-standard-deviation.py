N = int(input())
arr = list(map(int, input().split()))

arr_sum = 0
for x in arr:
    arr_sum += x

arr_mean = arr_sum / N

arr_std = 0
for x in arr:
    arr_std += pow(x - arr_mean, 2)
arr_std = pow(arr_std / N, 0.5)

print("{0:.1f}".format(arr_std))
