if __name__ == '__main__':
    s = input()
    flag1 = flag2 = flag3 = flag4 = flag5 = False
    for x in s:
        if x.isalnum():
            flag1 = True
        if x.isalpha():
            flag2 = True
        if x.isdigit():
            flag3 = True
        if x.islower():
            flag4 = True
        if x.isupper():
            flag5 = True
    print(flag1, flag2, flag3, flag4, flag5, sep='\n')
