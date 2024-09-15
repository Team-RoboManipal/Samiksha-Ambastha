def numbercheck(y):
    return all( isinstance(item,int)for item in y )
if __name__ == '__main__':
    n=int(input())
    student={}
    line=[]
    for _ in range(n):
        line=input().split() 
        name_key=line[0] 
        mark_value= list(map(int,line[1:]))
        x=numbercheck(mark_value)
        if x==True:
         student[name_key]=mark_value
    required_name=input()
    marks=student.get(required_name)
    avg=sum(marks)/len(marks)
    avg_formatted= format(avg,".2f")
    print(avg_formatted)
 
