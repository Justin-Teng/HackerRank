if __name__ == '__main__':
    N = int(input())
    arr = []
    for _ in range(0,N):
        command = str(input())
        tokens = command.split(' ')
        if tokens[0] == 'insert':
            arr.insert(int(tokens[1]), int(tokens[2]))
        elif tokens[0] == 'print':
            print(arr)
        elif tokens[0] == 'remove':
            arr.remove(int(tokens[1]))
        elif tokens[0] == 'append':
            arr.append(int(tokens[1]))
        elif tokens[0] == 'sort':
            arr.sort()
        elif tokens[0] == 'pop':
            arr.pop()
        else:
            arr.reverse()
