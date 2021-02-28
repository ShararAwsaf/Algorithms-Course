# find number of anagrams in an array given a string
def anagram_counter(S, A):
    c = 0
    sorted_S = sorted(S) # create signature for sorted s
    
    # sort A using length and break ties using signature ascending
    A.sort(key=lambda x : (len(x), sorted(x)) ) 
    
    print(A)
    print(sorted_S)
    
    l, r = 0, len(A)-1
    
    # binary searches for anagrams
    # if anagram length matches choose the side based on increasing on decreasing signature
    while l <= r:
        m =  (l+r)//2  # l+ (r-1) // 2 #
        
        if len(sorted_S) == len(A[m]):
            sorted_A = sorted(A[m])
            c += sorted_S == sorted_A
            if sorted_A > sorted_S:
                r = m-1
            else:
                l = m+1
            continue
            
        if len(sorted_S) > len(A[m]): # binary searching if s is less than middle item length
            l = m+1
        else:
            r = m-1

    return c

TA = ['act', 'aaa', 'dog', 'mad', 'catcat', 'cat', 'dts']
TS = "tac"
print("ANAGRAMS:",anagram_counter(TS, TA))