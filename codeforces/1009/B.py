s=input()
cnt=0;v=[]
for ch in s:
    if ch=='1': cnt+=1
    else: v.append(ch)
for ch in v:
    if ch=='2':
        for i in range(cnt): print(1,end='')
        cnt=0
    print(ch,end='')
for i in range(cnt): print(1,end='')