value=input()
numbers = list(map(int,value.split()))
largest = numbers[0]
for number in numbers:
    if number> largest:
        largest= number
print(largest)
