class Dict:
    def __init__(self) -> None:
        self.key = None
        self.data = None
    def __init__(self, k, d) -> None:
        self.key = k
        self.data = d
    
class Node:
    def __init__(self) -> None:
        self.dict = Dict()
        self.nextNode = None
        
    def __init__(self,k ,d, p) -> None:
        self.key = k
        self.data = d
        self.nextNode = p

############ LINEAR PROBING ################
def HashFun(key,size):
    amo = 0
    x = 1
    for i in key:
        amo += ((ord(i)-48)*x)
        x += 1
    hashKey = (amo % (size))    
    return hashKey


class Hash_LP:
    empty = "@"
    postDelete = "%"
    def __init__(self, Size) -> None:
        self.arr = []
        self.size = Size
        for i in range(Size):
            self.arr.append(Dict("@",-1))
   
    def SearchKey(self,key):
        hashKey = HashFun(key,self.size)
    
        for i in range(hashKey, self.size):
            if self.arr[i].key == key:
                return i
            elif self.arr[i].key == self.empty:
                return -1      
        
        for i in range(hashKey):
            if self.arr[i].key == key:
                return i
            elif self.arr[i].key == self.empty:
                return -1   
                
        return -1

    def insert(self, d) -> None:
        
        hashKey = HashFun(d.key,self.size)

        if self.arr[hashKey].key == self.empty:
            self.arr[hashKey].key = d.key
            self.arr[hashKey].data = d.data
            return
        else:
            for i in range(hashKey,self.size):
                if self.arr[i].key == self.empty or self.arr[i].key == self.postDelete:
                    self.arr[i].key = d.key
                    self.arr[i].data = d.data
                    return
            
            for i in range(hashKey):
                 if self.arr[i].key == self.empty or self.arr[i].key == self.postDelete:
                    self.arr[i].key = d.key
                    self.arr[i].data = d.data
                    return
                    
            print("Hash table is full, discarded ",d.key)
        
    def Search(self,key)->None:
        
        x = self.SearchKey(key)

        if x != (-1):
            print(key, " Key Found")
        else:
            print(key, " Key is not present in hash table")
        
        return

    def Remove(self, key) -> None:
        x = self.SearchKey(key)

        if x == (-1):
            print(key, "Element not found")
            return
        
        self.arr[x].key = self.postDelete #Deleted
        self.arr[x].data = -1 #Deleted
        print(key," Removed")
        return
    
    def DisplayHashTable(self):
        print("Key  :  Value")
        for i in self.arr:
            print(i.key, " : ", i.data)

################################## Chaining #######       
def HashFun_X(key,size):
    amo = 0
    x = size + 7
    for i in key:
        amo += ((ord(i)-48)*x*13)
        x -= 1
    hashKey = (amo % (size))    
    return hashKey


class Hash_Chain:
    empty = "@"
    postDelete = "%"
    
    def __init__(self, Size) -> None:
        self.size = Size
        self.arr = []
        for i in range(Size):
            self.arr.append(Node("Root"," ",None))
        
    def insert(self, d):
        hashKey = HashFun_X(d.key,self.size)
        x = self.arr[hashKey]
        while x.nextNode is not None:
            x = x.nextNode
        x.nextNode = Node(d.key,d.data,None)


    def Search(self,key):
        hashKey = HashFun_X(key,self.size)
        x = self.arr[hashKey]
        while x.nextNode != None:
            x = x.nextNode
            if x.key == key:
                print(key," Key found")
                return
            
        print(key," Not Found")
        return

    def Remove(self,key):
        hashkey = HashFun_X(key,self.size)
        x = self.arr[hashkey]
        p = x
        while x.nextNode is not None:
            x = x.nextNode
            if x.key == key:
                p.nextNode = x.nextNode
                x.nextNode = None
                print(key," Removed")
                return
            p = x
        print(key," Not Found")

    def DisplayHashTable(self):
        print("Key  :  Value")
        for i in range(self.size):
            x = self.arr[i]
            while x.nextNode is not None:
                print(x.key," -> ",x.data,end=" ; ")
                x = x.nextNode
            print(x.key," -> ",x.data)

########## MAIN ###########
print("CHAINING")
htable = Hash_Chain(int(10))#Chaining
htable.insert(Dict("95748564","John Warwick"))
htable.insert(Dict("93674562","Natsume Yamamoto"))
htable.insert(Dict("54896734","Mark Evans"))
htable.insert(Dict("90125634","Valt Aoi"))
htable.insert(Dict("78456354","Harutora Tsuchimikado"))
htable.insert(Dict("89345612","Gwendolyn Tennyson"))
htable.insert(Dict("89456342","Master Skylark"))
htable.DisplayHashTable()
print()
print()
htable.Search("78456354")
htable.Remove("95748564")
print()
htable.DisplayHashTable()


print()
print()
print("LINEAR PROBING")
htable1 = Hash_LP(int(10))#Linear probing
htable1.insert(Dict("95748564","John Warwick"))
htable1.insert(Dict("93674562","Natsume Yamamoto"))
htable1.insert(Dict("54896734","Mark Evans"))
htable1.insert(Dict("90125634","Valt Aoi"))
htable1.insert(Dict("78456354","Harutora Tsuchimikado"))
htable1.insert(Dict("89345612","Gwendolyn Tennyson"))
htable1.insert(Dict("89456342","Master Skylark"))
htable1.DisplayHashTable()
print()
print()
htable1.Search("89456342")
htable1.Remove("95748564")
print()
htable1.DisplayHashTable()
