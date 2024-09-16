listA=list(map(int,input().split()))
listB=list(map(int,input().split()))
listC=[]
for i in range(len(listA)):
    for j in range(len(listB)):
        if listA[i]==listB[j]:
            listC.append(listA[i])
print(listC)
