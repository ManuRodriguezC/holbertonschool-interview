#!/usr/bin/python3
"""
This Module create the function that find
the specific number that lock the boxes
"""


def canUnlockAll(boxes):
    """
    The boxes contain a list of the list, this function
    found the list contain the numbers that open the all lists
    """
    # Initialize a set to keep track of opened boxes
    opened_boxes = {0}

    # Initialize a set to store newly discovered boxes
    new_boxes = {0}

    # Iterate through the newly discovered boxes set
    while new_boxes:
        # Create a copy of the new boxes set
        current_boxes = new_boxes.copy()
        new_boxes.clear()
        # Iterate through the current boxes set
        for box in current_boxes:
            # Iterate through the keys in the current box
            for key in boxes[box]:
                if key < len(boxes) and key not in opened_boxes:
                    opened_boxes.add(key)
                    new_boxes.add(key)

    # Check if all boxes have been opened
    return len(opened_boxes) == len(boxes)
