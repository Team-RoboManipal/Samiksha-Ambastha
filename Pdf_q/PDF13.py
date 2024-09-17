x=list(map(int,input().split()))
element1=x[0]
for element in x:
    if element<element1:
        x.remove(element)
    element1=element
print(len(x))
        
