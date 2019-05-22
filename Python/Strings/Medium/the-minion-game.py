def isvowel(letter):
    o = ord(letter)
    if o == 65 or o == 69 or o == 73 or o == 79 or o == 85:
        return True
    return False

def minion_game(string):
    running_count_kevin = 0
    total_kevin = 0
    running_count_stuart = 0
    total_stuart = 0
    
    for c in string:
        if isvowel(c):
            running_count_kevin += 1
        else:
            running_count_stuart += 1
        total_kevin += running_count_kevin
        total_stuart += running_count_stuart
    
    if total_kevin > total_stuart:
        print('Kevin {}'.format(str(total_kevin)))
    elif total_stuart > total_kevin:
        print('Stuart {}'.format(str(total_stuart)))
    else:
        print('Draw')

