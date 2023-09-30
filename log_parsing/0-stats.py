#!/usr/bin/python3
"""
Module that parses a log and prints stats to stdout
"""
from sys import stdin

total_size = 0
status_counts = {}


def print_status():
    """Print the list status"""
    print(f"File size: {total_size}")
    for code, count in sorted(status_counts.items()):
        print(f"{code}: {count}")


if __name__ == "__main__":    
    try:
        for line_num, line in enumerate(stdin, start=1):
            parts = line.split()
            if len(parts) < 7:
                continue
            status = parts[-2]
            file_size = int(parts[-1])

            total_size += file_size

            if status.isdigit():
                status = int(status)
                status_counts[status] = status_counts.get(status, 0) + 1

            if line_num % 10 == 0:
                print_status()

    except KeyboardInterrupt:
        print_status()
        raise
    print_status()
