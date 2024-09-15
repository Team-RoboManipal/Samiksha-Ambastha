N=int(input())
M=N*3
list=[]
str=".|."
text="WELCOME"
y = (N - 1) // 2 + 1
for i in range(1,y):
    x=(M-(3*(2*i-1)))//2
    for _ in range(x):
        print("-",end="")
    for _ in range(2*i-1):
        print(str,end="")
    for _ in range(x):
        print("-",end="")
    print()
mid=text.center(M,'-')
print(mid)
for j in range(y,1,-1):
    x=(M-(3*(2*j-1)))//2
    for _ in range(x):
        print("-",end="")
    for _ in range(2*j-1):
        print(str,end="")
    for _ in range(x):
        print("-",end="")
    print()
