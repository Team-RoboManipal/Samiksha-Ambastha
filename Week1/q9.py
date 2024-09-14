n= int(input())
students= []
for i in range(n):
     name= input()  
     score= float(input()) 
     students.append([name,score])  
scores_student=sorted(set([student[1] for student in students]))  
second_low= scores_student[1]  
second_students= [student[0] for student in students if student[1] == second_low]
second_students.sort()
for name in second_students:
     print(name)
