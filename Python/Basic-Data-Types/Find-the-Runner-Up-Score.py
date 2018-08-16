if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    highest = -100
    nextHighest = -100
    for x in arr:
        if x > highest:
            nextHighest = highest
            highest = x
        elif x != highest and x > nextHighest:
            nextHighest = x
    print(nextHighest)
