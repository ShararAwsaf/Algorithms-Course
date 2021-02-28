def quick_sort(A):
    
    def partition(s, e):
        
        # check if start item is greater than end item
        if s >= e-1:
            return
        
        # choose the start item as pivot
        p = A[s]
        
        # rest items arranged so that the items less than pivot are on left and geq items right
        temp_A = [0] * (e-s-1) # s+1 : e
        l, r = 0, len(temp_A)-1
        for k in range(s+1,e):
            if A[k] >= p:
                temp_A[r] = A[k]
                r -= 1
            else:
                temp_A[l] = A[k]
                l += 1
                
        A[s+1:e] = temp_A[:]
        
        # swap the pivot item with end item of the left subarray less than pivot
        # this is the final position for the pivot item
        A[s], A[s+l] = A[s+l], A[s] 
        
        # solve the subarrays [s:s+l] and [s+l+1:e]
        partition(s, s+l)
        partition(s+l+1, e)
        
    partition(0, len(A))
    
TA = [20,2,5,1,19,7,3,8,0,9]
# TA = [2,5,1]
quick_sort(TA)

print(TA)