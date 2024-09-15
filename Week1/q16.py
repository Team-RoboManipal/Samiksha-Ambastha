def split_and_join(line):
    line=line.split(" ")
    b='-'.join(line)
    return(b)
    

if __name__ == '__main__':
    line = input()
    result= split_and_join(line)
    print(result)
