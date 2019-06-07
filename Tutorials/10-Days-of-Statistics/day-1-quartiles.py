def med(xs):
    if len(xs) % 2 == 1:
        return xs[len(xs) // 2]
    return (xs[len(xs)//2 - 1] + xs[len(xs)//2]) / 2

N = int(input())
arr = sorted(list(map(int, input().split())))

arr_med = med(arr)
arr_q1 = med(arr[0:N//2])
if (N % 2 == 1):
    arr_q2 = med(arr[N//2 + 1:])
else:
    arr_q2 = med(arr[N//2:])

print("{0:.0f}\n{1:.0f}\n{2:.0f}".format(arr_q1, arr_med, arr_q2))
