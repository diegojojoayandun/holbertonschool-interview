#!/usr/bin/python3

""" lockboxes """


def joining(T, R):
    """
    function to concatenate true and rigth
    """
    res = []
    for e in R:
        res += T[e]
    return res


def canUnlockAll(boxes):
    """
    main function
    """
    index = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for j in joining(boxes, total[index:]):
            if j not in total:
                total.append(j)
                index += 1
                added = True

    return len(total) == len(boxes)
