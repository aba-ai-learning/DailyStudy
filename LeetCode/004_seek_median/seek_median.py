
def seek_median(l1, l2):
    l1.append(l2)
    l1.sort()
    length = len(l1)
    num = (l1[(len + 1) / 2] + l1[(len + 2) / 2]) / 2
    print(num)
    return num


if __name__ == "__main__":
    l1 = [1, 2, 5, 8, 9]
    l2 = [3, 4, 6]

    seek_median(l1, l2)

