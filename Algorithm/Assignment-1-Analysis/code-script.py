def q3():

    a = [i for i in range(1,1000,2)]
    n = "3a"
    # print(a)
    # print(n, len(a), sum(a))
    
    n = "3b"
    b = []

    i = 2
    while i < 1025:
        b.append(i)
        i *= 2
    print(b)
    print(n, len(b), sum(b))

# q3()

def q6(A):
    n = len(A)
    for i in range(0,n-1):

        for j in range(i+1,n):

            if A[j] > A[i]:
                A[i], A[j] = A[j], A[i]


TA = [3,7,1,9,4,0,12,66,4,1,0,5,2]
r = q6(TA)
print(TA)


