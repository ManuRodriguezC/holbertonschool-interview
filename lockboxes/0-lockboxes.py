#!/usr/bin/python3
"""
This Module create the function that find
the specific number that lock the boxes
"""


def canUnlockAll(boxes):
    """
    Need to find the correct number,
    the number is the pisition of the next box
    """
    pos = 1
    for list in boxes:
        for num in list:
            # print(num)
            if num == pos:
                # print(f"{num} = {pos}")
                result = "true"
            else:
                return False
        pos += 1
    if result == "true":
        return True
