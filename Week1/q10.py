n=int(input())
    student={}
    for _ in range(n):
        name_key=input()
        mark_value= list(map(int,input().split()))
        student[name_key]=mark_value
    required_name=input()
    marks=student.get(required_name)
    avg=sum(marks)/len(marks)
    avg_formatted= format(avg,".2f")
    print(avg_formatted)
 
