#!usr/bin/python3
"""
This program found the minimum operation necesary
for create the specific number
"""


def minOperations(n):
    num = n
    if n % 2 == 0 and n % 3 == 0:
        if num < 0:
            num *= -1
        return operations(num, 1)
    if n % 2 == 0 and n % 3 != 0:
        return operations(num, 0)
    if n % 3 == 0 and n % 2 != 0:
        return imparOperation(num, 1)
    if n % 2 != 0 and n % 3 != 0:
        return n


def operations(num, count):
    while num != 1:
        count = count + 1
        if num == 1:
            return count
        num = int(num / 2)
        count += 1
        if num == 1:
            return count


def imparOperation(num, count):
    while num != 1:
        count += 1
        if num == 1:
            return count
        num = int(num / 3)
        count += 1
        if num % 3 != 0 or num == 3:
            while num >= 1:
                num -= 1
                count += 1
            return count
