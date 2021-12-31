def bio2b(n, w):
    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z']

    j = -1

    ring = ''
    for i in range(26):
        j += n
        a = n / j
        j %= len(alphabet)
        ring += alphabet[j]
        alphabet.pop(j)
        j -= 1

    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z']
    encoded = ''
    for i in range(len(w)):
        idx = alphabet.index(w[i]) + i
        if idx > 25:
            idx %= 25
            idx -= 1
        encoded += ring[idx]

    return ring[:6] + '\n' + encoded


print(bio2b(1000000000, ''))
# LKBXIY
