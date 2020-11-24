a=list(range(10))
# a=[0,0,2,3]

n=len(a)
temp=[[] for _ in range(n)]
print(n)

for i in range(1,len(a)):
    print(a[i]^a[0])
    temp[a[i]^a[0]].append(i)

print(0)
print(8^9)
print(temp)


