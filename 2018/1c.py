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
            return float("{:.2f}".format(paid / 100))
        elif repay * debt < 500000:
            paid += 5000
            debt -= 5000
        else:
            paid += math.ceil((repay / 100) * debt)
            debt -= math.ceil((repay / 100) * debt)

maxRepaid = 0
interest = 0
repay = 0
for i in range(100):
    for j in range(100):
        if i == 50 and j < 34: # infinite loop
            continue
        try:
            out = bio1a(i, j)
        except:
            continue
        if out > maxRepaid:
            maxRepaid = out
            interest = i
            repay = j

print(interest, repay)
# 96 49, after a little while