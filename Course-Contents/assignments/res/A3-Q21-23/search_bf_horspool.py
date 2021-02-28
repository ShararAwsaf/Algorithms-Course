# brute force string search: search left to right
def search_key_text_bf(S, T):
    
    if len(T) < len(S):
        return -1
    
    si = 0
    for ti, t in enumerate(T):
        
        if si == len(S):
            return ti-si
            
        if S[si] == t:
            si += 1
        else:
            si = 0
    
    if si == len(S):
        return len(T)-si
    
    return -1
# horspool algorithm
# Matching occurs from end to start
def search_key_text_horspool(S, T):
    
    # preprocess so that for the characters mismatch, jump to end of word
    import string
    chars = string.printable
    
    HT = {k : len(S) for k in chars}
    # print(HT)
    
    # for character matches the processed characters are tracked and jump is done
    # to the HT[s] amount when a mismatch at a character occurs
    for si, s in enumerate(S):
        HT[s] = len(S) - si
        
    
    # text search : Traverse left to right but processing each word right to left
    ti = 0
    shifts = 0
    while ti + len(S) <= len(T):
        # print(ti)
        si = len(S) - 1
        while si >= 0 and T[ti+si] == S[si]:
            si -= 1
        
        if si < 0: # pattern fully matched
            print("SHIFTS:", shifts)
            return ti
        # else:
        #     print(ti, si, S[si], HT[S[si]])
        
        # jump to end from point of mismatch
        shifts += 1
        ti += HT[S[si]]
    
    print("SHIFTS:", shifts)
    return -1
    
# TA = 'we are tiger'
# TS = 'tiger'

TA = 'what is tiger'
TS = 'tiger'

# print('FINDING BF:', search_key_text_bf(TS, TA))

print('FINDING HORSPOOL:', search_key_text_horspool(TS, TA))

