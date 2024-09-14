if __name__ == '__main__':
 list=[]
 n = int(input())
 for _ in range(n):
    comm=input().split()
    if comm[0]=='insert':
        i=int(comm[1])
        e=int(comm[2])
        list.insert(i, e)
    elif comm[0]=='print':
        print(list)
    elif comm[0]=='remove':
        e=int(comm[1])
        list.remove(e)
    elif comm[0]=='append':
        e=int(comm[1])
        list.append(e)
    elif comm[0]=='sort':
        list.sort()
    elif comm[0]=='pop':
        list.pop()
    elif comm[0]=='reverse':
       list.reverse()
