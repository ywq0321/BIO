from itertools import permutations


def swap(ary, idx1, idx2):
    # this will only work if idx1 and idx2 are adjacent
    ary = list(ary)
    ary.insert(idx2, ary.pop(idx1))
    return ''.join(ary)


def bio3a(n, cnt=1, results=None):
    if results is None:
        results = {n: 0}

    length = len(n)

    for i in range(1, length):
        if i == 1:
            if (n[0] < n[2] < n[1]) or (n[0] > n[2] > n[1]):
                next = swap(n, 0, 1)
                if next in results:
                    if results[next] > cnt:
                        results[next] = cnt
                        results = bio3a(next, cnt + 1, results)
                else:
                    results[next] = cnt
                    results = bio3a(next, cnt + 1, results)
        elif i == length - 1:
            if (n[length - 1] < n[length - 3] < n[length - 2]) or (n[length - 1] > n[length - 3] > n[length - 2]):
                next = swap(n, length-1, length-2)
                if next in results:
                    if results[next] > cnt:
                        results[next] = cnt
                        results = bio3a(next, cnt + 1, results)
                else:
                    results[next] = cnt
                    results = bio3a(next, cnt + 1, results)
        else:
            if (n[i] < n[i - 2] < n[i - 1]) or (n[i] > n[i - 2] > n[i - 1]) or (n[i] < n[i + 1] < n[i - 1]) or \
                    (n[i] > n[i + 1] > n[i - 1]):
                next = swap(n, i, i - 1)
                if next in results:
                    if results[next] > cnt:
                        results[next] = cnt
                        results = bio3a(next, cnt + 1, results)
                else:
                    results[next] = cnt
                    results = bio3a(next, cnt + 1, results)

    return results


perms = list(permutations('12345', 5))

equals = []
cnt = 0

for i in perms:
    output = bio3a(''.join(i))
    if len(output) > 1:
        print(output)
        for j in output.keys():
            perms.remove(tuple(j))


print(len(perms))
print(perms)
