def swap_case(s):
    x=len(s)
    string=""
    for i in range(x):
        if s[i].isupper():
            string=string+s[i].lower()
        elif s[i].islower():
            string=string+s[i].upper()
        else :
            string=string+s[i]
    return (string)

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
