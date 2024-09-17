n=int(input())
dict={}
for _ in range(n):
    key=input()
    value=input()
    dict[key]=value
dict_sorted= sorted(dict.items(), key=lambda x : x[1])
print(dict_sorted)
