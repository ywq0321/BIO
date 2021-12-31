palindromes = [None for _ in range(100000)]
numbers = [None for _ in range(100000)]

for i in range(100000):
    if str(i) == str(i)[::-1]:
        palindromes[i] = 1

for i in range(100000):
	if palindromes[i] == 1:
		for j in range(i, 100000):
			if palindromes[j] == 1:
				if i+j < 99999:
					numbers[i+j] = 1

print(99999-numbers.count(1))
# 9030






