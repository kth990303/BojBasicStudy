def dfs(i,even):
  if i==N:
    return
  
  if even:
    born.append(total[-1])
    total.append(born[-1]*2-born[-4]-born[-5])
    dfs(i+1,not even)
  else:
    born.append(total[-1])
    total.append(born[-1]*2)
    dfs(i+1,not even)

N = int(input())
born=[0,1,1,2,4]
total=[0,1,2,4,7]
if N <= 4:
  print(total[N])
else:
  dfs(4,False)
  print(total[-1])
