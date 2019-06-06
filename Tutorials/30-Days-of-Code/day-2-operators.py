#!/bin/python3

# Complete the solve function below.
def solve(meal_cost, tip_percent, tax_percent):
    return meal_cost * (1 + (tip_percent + tax_percent) / 100)
if __name__ == '__main__':
    meal_cost = float(input())

    tip_percent = int(input())

    tax_percent = int(input())

    print("The total meal cost is {0:.0f} dollars.".format(solve(meal_cost, tip_percent, tax_percent)))
    
