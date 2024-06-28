def ans(cases):
    results = []
    for case in cases:
        n, l, r, a = case
        pre = [0] * (n +1)
        for i in range(n):
            pre[i +1] = pre[i] +a[i]
        
        start = 0
        count = 0
        
        for end in range(n):
            while start <= end and (pre[end + 1] -pre[start] > r):
                start += 1
            if start <=end and l<= (pre[end + 1]- pre[start]) <= r:
                count+= 1
                start= end + 1
        
        results.append(count)
    return results

t = int(input())
for i in range(t):
    cases = []
    n, l, r = eval(input())
    # l = eval(input())
    # r = eval(input())
    aNode = []
    for i in range(n):
        x =input()
        aNode.append(x)
    cases.append(n)
    cases.append(l)
    cases.append(r)
    cases.append(aNode)
    

for i in ans(cases): 
    print(i)