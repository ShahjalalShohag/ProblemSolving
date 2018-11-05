import math
def div(n):
    k=math.ceil(math.sqrt(n))
    ans=0
    for i in range(1,k):
        if n%i==0: ans+=2
    if k*k==n: ans+=1;
    return ans;
n=int(input())
print(div(n))