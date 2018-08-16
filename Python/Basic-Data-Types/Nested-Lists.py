if __name__ == '__main__':
    lowest = 100
    secondLowest = 100
    lowestStudents = []
    secondLowestStudents = []
    for i in range(int(input())):
        name = input()
        score = float(input())
        if i == 0:
            lowest = score
            lowestStudents = [name]
            continue
        if score < lowest:
            secondLowest = lowest
            lowest = score
            secondLowestStudents = lowestStudents
            lowestStudents = [name]
        elif score == lowest:
            lowestStudents += [name]
        elif score < secondLowest:
            secondLowest = score
            secondLowestStudents = [name]
        elif score == secondLowest:
            secondLowestStudents += [name]
    for x in sorted(secondLowestStudents):
        print(x)
