#!/usr/bin/python3
"""This module is of log_parsing"""
import sys


total_size = 0
status_counts = {}

try:
    for count, line in enumerate(sys.stdin, start=1):
        print(line)

except KeyboardInterrupt:
    print("cerro")
