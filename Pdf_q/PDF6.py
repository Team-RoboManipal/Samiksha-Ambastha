def flatten(x):
    result = []
    for item in x:
        if isinstance(item , list):
            result.extend(item)
        else:
            result.append(item)
    return result
x=eval(input())
flattened = flatten(x)
print(flattened)
