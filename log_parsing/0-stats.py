#!/usr/bin/python3
"""This module is of log_parsing"""
import sys


total_size = 0
status_counts = {}

try:
    for count, line in enumerate(sys.stdin, start=1):
        size = 1
        status = 2
        print(f"size {size}, status {status}")

except KeyboardInterrupt:
    print("cerro")
