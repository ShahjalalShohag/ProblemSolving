import sys
import math
n,m=map(int,(input().split()))
if m<n-1:
    print ("Impossible")
    sys.exit()
l=[]
for i in range(1,n):
    l.append((i,i+1))
m-=(n-1)
for i in range(1,n+1):
    if m==0: break
    for j in range(i+2,n+1):
        if (math.gcd(i,j))==1:
            l.append((i,j))
            m-=1
        if m==0: break
if m==0:
    print ("Possible")
    for a,b in l:
        print (a,b)
else: print ("Impossible")