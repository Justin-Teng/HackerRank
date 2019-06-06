import datetime

month, day, year = map(int, input().split())
weekday = datetime.date(year, month, day).weekday()

if weekday == 0: print('MONDAY')
elif weekday == 1: print('TUESDAY')
elif weekday == 2: print('WEDNESDAY')
elif weekday == 3: print('THURSDAY')
elif weekday == 4: print('FRIDAY')
elif weekday == 5: print('SATURDAY')
else: print('SUNDAY')
