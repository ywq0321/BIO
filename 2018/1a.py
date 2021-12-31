import math


def bio1a(interest, repay):
    interest = int(interest)
    repay = int(repay)

    paid = 0
    debt = 10000

    while 1:
        debt += math.ceil((interest / 100) * debt)
        if debt < 5000:
            paid += debt
            return "{:.2f}".format(paid / 100)
        elif repay * debt < 500000:
            paid += 5000
            debt -= 5000
        else:
            paid += math.ceil((repay / 100) * debt)
            debt -= math.ceil((repay / 100) * debt)


# auto check all test cases
with open('test1a.txt', 'r') as inputs:
    inputs = inputs.read().split('\n')

for i in inputs:
    case = i.split(' ')
    output = bio1a(int(case[0]), int(case[1]))
    if output == case[2]:
        print('Y')
    else:
        print(case[0], case[1])
        print(output, case[2], end=' ')
        print('N')
    print()

# manual input
# inputs = input().split(' ')
# print(bio1a(int(inputs[0]), int(inputs[1])))
