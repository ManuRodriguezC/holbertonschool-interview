#!/usr/bin/python3
""" This module check if the numbers is UTF-8"""


def validUTF8(data):
    position = 0
    while position < len(data):
        if data[position] < 128:
            position += 1
            continue

        num_bytes = 0
        if (data[position] & 0xE0) == 0xC0:
            num_bytes = 2
        elif (data[position] & 0xF0) == 0xE0:
            num_bytes = 3
        elif (data[position] & 0xF8) == 0xF0:
            num_bytes = 4
        else:
            return False

        if position + num_bytes > len(data):
            return False

        for j in range(position + 1, position + num_bytes):
            if (data[j] & 0xC0) != 0x80:
                return False

        position += num_bytes

    return True
