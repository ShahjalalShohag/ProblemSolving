s=input()
for i in range(len(s)-2):
    if(set(s[i:i+3])==set("ABC")):
        print("Yes")
        exit(0)
print("No")