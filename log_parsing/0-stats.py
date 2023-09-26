#!/usr/bin/python3
"""This module give stdin values, and count of the types status and sizes."""
import sys


total_size = 0
status_counts = {}

try:
    for line_num, line in enumerate(sys.stdin, start=1):
        parts = line.split()
        if len(parts) < 7:
            continue
        status_code = parts[-2]
        file_size = int(parts[-1])

        total_size += file_size

        if status_code.isdigit():
            status_code = int(status_code)
            status_counts[status_code] = status_counts.get(status_code, 0) + 1

        if line_num % 10 == 0:
            print(f"File size: {total_size}")
            for code, count in sorted(status_counts.items()):
                print(f"{code}: {count}")

except KeyboardInterrupt:
    print(f"File size: {total_size}")
    for code, count in sorted(status_counts.items()):
        print(f"{code}: {count}")
