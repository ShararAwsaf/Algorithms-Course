

class CRCell:
    
    def __init__(self, C, R):
        self.C = C
        self.R = R

class TreeNode:
    
    def __init__(self, value):
        self.value = value
        self.left_subtree = None
        self.right_subtree = None
        
class Item:
    
    def __init__(self, v, prob):
        self.v = v
        self.prob = prob

        
def Construct_OBST_Table(K):
    # K is 1 indexed
    # assumes k is sorted
    n = len(K) - 1
    print("N:", n)
    
    CR_Table = [[CRCell(0, None) for _ in range(0, n+1)] for _ in range(0, n+2)]
    
    # initialize with base case
    for i in range(1, n+1):
        CR_Table[i][i-1] = CRCell(0, None)
        CR_Table[i][i] = CRCell(K[i].prob, i) # index to the nodes are held not the actual value
        
    CR_Table[n+1][n]  = CRCell(0, None)
    print("INITIALIZATION")
    print_CR_Table(CR_Table)
    
    # create table using bottom up
    for d in range(1, n): # diagonals 1 to n-1
        print('D: ',d)
        for i in range(1, n - d+1): # all rows until d
            j = d + i # i used as offset
            print("i: ", i, "j: ", j)
            min_cost = float('inf')
            min_root = None
            # finds the minimum among the Ci,j until current from left to right and bottom up
            for l in range(i, j+1): # i<= l <= j
                cost = CR_Table[i][l-1].C + CR_Table[l+1][j].C
                
                if cost < min_cost:
                    min_cost = cost
                    min_root = l
            W = 0
            for s in range(i, j+1):
                W += K[s].prob
            
            CR_Table[i][j] = CRCell(min_cost + W, min_root)
    
    
    return CR_Table    
    
def print_CR_Table(CR_Table):
    ROW = len(CR_Table)
    COL = len(CR_Table[0])
    
    print('I:', ROW, 'J:', COL)
    
    for i, r in enumerate(CR_Table):
        if i: # skip the 0-th row
            print('{}:'.format(i), end=' ')
            for cell in r:
                print("[({:.3f})({})] ".format(cell.C, cell.R), sep=' ', end=" ")
            print()
            


def ConstructTreeFromTable(CR_Table, K):

    def find_subtree_rec(L, R):
        R_lr = CR_Table[L][R].R

        node= TreeNode(K[R_lr])
        print("L:{} R:{}".format(L,R))

        print("Going Left ({})".format(node.value.v))
        node.left = None if R_lr-1 < L else find_subtree_rec(L, R_lr-1)
        
        print("Going Right ({})".format(node.value.v))
        node.right = None if R_lr+1 > R else find_subtree_rec(R_lr+1, R)
        return node

    T = find_subtree_rec(1, len(K)-1) # 1,n is the first root 
    return T


def CreateOBST(items):
    # Items are a list of items with their probabilities
    n = len(items)
    K = [Item(None, 0.0) for _ in range(0, n+1)]
    
    K[1:n+1] = sorted(items, key=lambda x:x.v)[:] # sort based on the value of the items and store them in 1 indexed K
    printItems(K)
    
    CR_Table = Construct_OBST_Table(K)

    print("COST-ROOT TABLE")
    print_CR_Table(CR_Table)
    T = ConstructTreeFromTable(CR_Table, K)

    print("LEVEL BY LEVEL TREE (L->R)")
    bfs(T)


def bfs(T):

    levels = [(T, 1)]
    level = 1
    frontier = [T]
    while frontier:
        nxt = []
        level += 1

        for v in frontier:
            
            
            # if v.left or v.right:
            levels.append((v.left, v.right, level))
            if v.left:
                # print("{}".format(v.left.value.v), end=' ')
                nxt.append(v.left)
            
            if v.right:
                # print("{}".format(v.right.value.v), end=' ')
                nxt.append(v.right)
            
        frontier=nxt
    
    levels.sort(key=lambda x: x[-1])

    prev_level = 1
    for L in levels:
        
        for x in range(0,len(L)-1):
            if prev_level != L[-1]:
                print()
            else:
                print(L[-1], end = " ")
            
            v = L[x].value.v if L[x] else None
            print("{}         ".format(v), end=' ') # print left to right (in-order)
        
            prev_level = L[-1]
    print()
    

def printItems(items):
    for i in items:
        print(" {} : {} ".format(i.v, i.prob))


TA = [
        Item('D', 0.100),
        Item('B', 0.020),
        Item('A', 0.213),
        Item('C', 0.547),
        Item('E', 0.12),
    ]

CreateOBST(TA)






    
    