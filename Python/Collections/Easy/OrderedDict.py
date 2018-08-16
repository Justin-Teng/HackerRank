from collections import OrderedDict

o_dict = OrderedDict()
N = int(input())

for _ in range(N):
    line = input().split()
    price = int(line[-1])
    name = ' '.join(line[0:-1])
    
    if (o_dict.get(name) == None):
        o_dict[name] = price
    else:
        o_dict[name] += price
        
for key, value in o_dict.items():
    print(key, value)
