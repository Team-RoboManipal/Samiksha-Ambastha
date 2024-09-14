  x = int(input())
  y = int(input()) 
  z = int(input()) 
  n = int(input()) 
  p=[]  
  for i in range(x+1): 
    for j in range(y+1): 
      for k in range(z+1): 
         if i+j+k!=n:
            p.append([i,j,k]) 
  p_sorted=sorted(p) 
  print(p_sorted)
