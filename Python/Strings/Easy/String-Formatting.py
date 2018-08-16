def print_formatted(number):
    binlen = len(str(bin(number))) - 2
    for i in range(1, number+1):
        print("{0} {1} {2} {3}".format(str(i).rjust(binlen), str(oct(i))[1:].rjust(binlen), format(i, 'x').upper().rjust(binlen), bin(i)[2:].rjust(binlen)))
