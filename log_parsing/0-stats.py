#!/usr/bin/python3
"""This module is of log_parsing"""
import sys


total_size = 0
status_counts = {}

for line_num, line in enumerate(sys.stdin, start=1):
    args = line.split()
    if len(args) < 7:
        continue
    status = args[-2]
    size = int(args[-1])
    total_size += size

    if status.isdigit():
        status = int(status)
        status_counts[status] = status_counts.get(status, 0) + 1

    if line_num % 10 == 0:
        print(f"File size: {total_size}")
        for code, count in sorted(status_counts.items()):
            print(f"{code}: {count}")
