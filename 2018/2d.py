def bio2a(n, w):
    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z']

    j = -1

    ring = ''
    for i in range(26):
        j += n
        while j > len(alphabet) - 1:
            j -= len(alphabet) - 1
            j -= 1
        ring += alphabet[j]
        alphabet.pop(j)
        j -= 1

    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z']
    encoded = ''
    for i in range(len(w)):
        idx = alphabet.index(w[i])
        if idx > 25:
            idx %= 25
            idx -= 1
        encoded += ring[idx]

    return encoded


longest = [0]
i = 2
last = 0
while 1:
    inputs = 'HGFEDCBA'  # the actual word doesn't seem to make a difference. It just has to be 8 letters long.
    original = 'HGFEDCBA'
    cnt = 1
    while 1:
        inputs = bio2a(i, inputs)
        if inputs == original:
            break
        cnt += 1

    if cnt > longest[0]:
        longest = [cnt, i]

    if not longest is last:
        last = longest
        print(last)
    i += 1

# This won't print anything after [1260, 1052], after a little while,
# however just this is not a valid proof that 1260 is the biggest possible.
# 1260
