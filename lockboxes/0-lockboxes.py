#!/usr/bin/python3

def canUnlockAll(boxes):
    size = len(boxes)
    pos = 1
    for list in boxes:
        for num in list:
            #print(num)
            if num == pos:
                #print(f"{num} = {pos}")
                result = "true"
            else:
                return False
        pos += 1
    if result == "true":
        return True