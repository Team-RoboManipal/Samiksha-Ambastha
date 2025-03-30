str1=input()
str2=input()
str1lower=str1.lower()
str2lower=str2.lower()
x=sorted(str1lower)
y=sorted(str2lower)
if x==y:
    print("anagram")
else:
    print("not anangram")
