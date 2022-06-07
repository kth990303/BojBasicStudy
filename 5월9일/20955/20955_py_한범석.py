import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

def findParent(node):
  if parent[node] != node:
    parent[node] = findParent(parent[node])
  return parent[node]
  
N,M = list(map(int,input().split()))
parent = [i for i in range(N+1)]

cut = 0
for i in range(M):
  a,b = list(map(int,input().split()))
  aParent, bParent = findParent(a),findParent(b)
  if aParent == bParent:
    cut+=1
  else:
    parent[bParent] = aParent

edge = 0
grandParent = findParent(1)
for i in range(2,N+1):
  newParent = findParent(i)
  if grandParent != newParent:
    edge+=1
    parent[newParent] = grandParent
print(cut+edge)
