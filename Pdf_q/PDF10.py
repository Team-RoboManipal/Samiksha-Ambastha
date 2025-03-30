n=int(input("no of elements"))
my_list=[]
for i in range(n):
    name=input("enter name")
    age=int(input("enter age"))
    my_list.append({"name":name , "age":age})
for i in range(n):
    listindex=i
    for j in range(i,n):
        if my_list[listindex]["age"] > my_list[j]["age"]:
            listindex=j
    temp = my_list.pop(listindex)
    my_list.insert(i, temp)
print(my_list)
