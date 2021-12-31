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
        idx = alphabet.index(w[i]) + i
        if idx > 25:
            idx %= 25
            idx -= 1
        encoded += ring[idx]

    return ring[:6] + '\n' + encoded


# auto check all test cases
with open('test2a.txt', 'r') as inputs:
    inputs = inputs.read().split('\n')

for i in range(0, len(inputs), 2):
    case = inputs[i].split(' ')
    output = bio2a(int(case[0]), case[1])
    if output == case[2] + '\n' + inputs[i + 1]:
        print('Y')
    else:
        print(case[0], case[1], case[2], inputs[i + 1])
        print(output, end=' ')
        print('N')
    print()

# manual input
# inputs = input().split(' ')
# print(bio2a(int(inputs[0]), inputs[1]))
