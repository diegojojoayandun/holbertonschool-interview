#!/usr/bin/python3

""" lockboxes """


def canUnlockAll(boxes):
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        print("id: {} box {}".format(box_id, box))
        if not box:
            print(box)
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))