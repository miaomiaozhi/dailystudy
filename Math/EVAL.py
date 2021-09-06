n = int (input())
for i in range(n):
    ss = input()
    ss = ss.replace("x" , "*")
    ss = ss.replace("/" , "//")
    ans = eval(ss)
    print (ans)


