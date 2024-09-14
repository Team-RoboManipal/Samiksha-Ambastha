n=int(input())
word=input()
word_list=word.split()
x='aeiouy'
s=0
for words in word_list:
    vowel=sum(1 for char in words if char in x)
    if vowel%2==0:
        s+=2
    else:
        s+=1
        
print(s)
