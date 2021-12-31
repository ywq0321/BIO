import math


def bio1a(interest, repay):
    interest = int(interest)
    repay = int(repay)

    paid = 0
    debt = 10000
    i = 0

    while 1:
        i += 1
        debt += math.ceil((interest / 100) * debt)
        if debt < 5000:
            paid += debt
            return i
        elif repay * debt < 500000:
            paid += 5000
            debt -= 5000
        else:
            paid += math.ceil((repay / 100) * debt)
            debt -= math.ceil((repay / 100) * debt)


print(bio1a(50, 0))
# 5
