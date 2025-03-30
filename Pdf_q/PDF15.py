def push(stk,ele):
    stk.append(ele)
def pop(stk):
    x=stk.pop()
    return x 
def display(stk):
    print(stk)
def check(stk):
    if len(stk)==0:
        return True
    else:
        return False
stk=[]
push(stk,5)
push(stk,10)
display(stk)
pop_element=pop(stk)
display(stk)
print(check(stk))
