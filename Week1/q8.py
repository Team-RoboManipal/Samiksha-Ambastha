if __name__ == '__main__':
    n = int(input())
    A= list(map(int,input().split()))
    winner= max(A)
    runnerup=[rank for rank in A if rank!=winner]
    runnerup_rank=max(runnerup)
    print(runnerup_rank)
