def med(xs):
    if len(xs) % 2 == 1:
        return xs[len(xs) // 2]
    return (xs[len(xs)//2 - 1] + xs[len(xs)//2]) / 2

N = int(input())
arr = list(map(int, input().split()))
freq = list(map(int, input().split()))

new_arr = []
for i in range(N):
    for j in range(freq[i]):
        new_arr.append(arr[i])
        
arr = sorted(new_arr)
N = len(arr)

arr_med = med(arr)
arr_q1 = med(arr[0:N//2])
if (N % 2 == 1):
    arr_q2 = med(arr[N//2 + 1:])
else:
    arr_q2 = med(arr[N//2:])

print("{0:.1f}".format(arr_q2 - arr_q1))
