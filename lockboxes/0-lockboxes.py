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
    if boxes == [[0]]:
        return True
    pos = 1
    num = boxes[0][0]
    for x in range(len(boxes) - 1):
        result = ""
        for i in range(len(boxes[x])):
            if boxes[x][i] == pos:
                result = "true"
            if num + boxes[x][i] == pos and result != "true":
                result = "true"
            if num - boxes[x][i] == pos and result != "true":
                result = "true"
            if boxes[x][i] != pos and result != "true":
                result = "false"
            num = boxes[x][i]
        pos += 1
        if result == "false":
            return False
    if result == "true":
        return True
    return False
