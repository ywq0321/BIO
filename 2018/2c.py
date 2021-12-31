'''
No.
Because of the mechanism of 'move 1 a single position every time a letter is encrypted', only letters on the second dial
with index: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 will ever be used.
After 25, next letter will have index 1 ( (25 + 2) % 26 ), and the cycle repeats.
'''