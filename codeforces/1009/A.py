n,m=map(int,raw_input().split())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
i=0;j=0;ans=0
while i<n and j<m:
    if a[i]<=b[j]:
        ans+=1;j+=1 
    i+=1
print ans