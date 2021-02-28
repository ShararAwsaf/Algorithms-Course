# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.


def countInvDC(A):
    c = [0]
    
    def splitArray(s,e):
        
        if s == e-1:
            return
        m = (s+e)//2
        
        splitArray(s,m)
        splitArray(m,e)
        print(A[s:m], A[m:e])
        mergeArrays(s,m,e)
        
    def mergeArrays(s,m,e):
        l, r, k = s, m, 0
        
        # ascending sort
        sortedSubarray = [0] * (e-s)
        smallerNumber = -1
        while l < m and r < e:
            if A[l] > A[r]:
                smallerNumber = A[r]
                c[-1] += m-l
                r += 1
            else:
                smallerNumber = A[l]
                l += 1
                
            sortedSubarray[k] = smallerNumber
            k += 1
            
        while l < m:
            sortedSubarray[k] = A[l]
            l += 1
            k += 1
        
        while r < e:
            sortedSubarray[k] = A[r]
            r += 1
            k += 1
            
        A[s:e] = sortedSubarray[:]
    
    splitArray(0, len(A))
    print(c[-1])
        
def countInvBrute(A):
    count = 0
    for i in range(0, len(A)-1):
        for j in range(i+1, len(A)):
            if A[i] > A[j]:
                count += 1
                
    print(count)

# T = [3,1,2,6,7,5]
T = [3,2,6,7,5]
# T = [6,8,5]
T.sort(reverse=True)
print(T)
countInvBrute(T)
countInvDC(T)