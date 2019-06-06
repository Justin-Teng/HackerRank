def average(array):
    s = set()
    for x in array:
        s.add(x)
    return sum(s) / len(s)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
