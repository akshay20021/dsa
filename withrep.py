def HashFun(key,size):
    amo = 0
    x = 1
    for i in key:
        amo += ((ord(i)-48)*x)
        x += 1
    hashKey = (amo % (size))    
    return hashKey

class Dict:
    def __init__(self, k=-1, v=-1) -> None:
        self.key = k
        self.value = v


class Dictionary:
    deleted = -2

    def __init__(self, Size) -> None:
        self.size = Size
        self.hashTable = []
        self.link = []

        for i in range(self.size):
            self.hashTable.append(Dict())
            self.link.append(-1)

    def insert(self, D):
        hashed = HashFun(D.key, self.size)

        if self.hashTable[hashed].key == -1:
            self.hashTable[hashed] = D
            return
        else:
            newHashed = HashFun(self.hashTable[hashed].key, self.size)
            
            # If replacement is not going to happen
            if hashed == newHashed:
                while self.link[newHashed] != (-1):
                    newHashed = self.link[newHashed]
                # newhashed is our starting point
                hashed = newHashed
                for i in range(newHashed, self.size + newHashed):
                    if self.hashTable[i%self.size].key == -1 or self.hashTable[i%self.size].key == self.deleted:
                        self.hashTable[i%self.size] = D
                        self.link[newHashed] = i%self.size
                        self.link[i%self.size] = -1
                        return
            else:# Replacement is going to happen
                k = self.hashTable[hashed].key
                v = self.hashTable[hashed].value

                self.hashTable[hashed] = D
                for i in range(hashed, self.size + hashed):
                    if self.hashTable[i%self.size].key == -1 or self.hashTable[i%self.size].key == self.deleted:
                        self.link[newHashed] = i%self.size
                        self.link[i%self.size] = -1
                        self.hashTable[i%self.size].key = k
                        self.hashTable[i%self.size].value = v
                        return
        print("Dictionary is full!")

    def __internalSearch(self, k) -> None:
        hashed = HashFun(k, self.size)
        while self.hashTable[hashed].key != k and self.link[hashed] != -1:
            hashed = self.link[hashed]
        
        if self.hashTable[hashed].key == k:
            return hashed
        
        return -1

    def search(self, k):
        if self.__internalSearch(k) != (-1):
            return True
        return False

    def remove(self, k):
        index = self.__internalSearch(k)
        if index == -1:
            return
        
        if self.link[index] != -1:
            preIndex = index
            while self.link[index] != -1:
                index = self.link[index]
                self.hashTable[preIndex] = self.hashTable[index]
                self.link[preIndex] = self.link[index]
                preIndex = index
        
        self.link[index] = -1
        self.hashTable[index].key = -1
        self.hashTable[index].value = -1
        print("SuccessFul deletion of ", k)
        print()  
        pass

    def Display(self):
        for i in range(self.size):
            print("HashTable : ", self.hashTable[i].key,"       ,      ", self.hashTable[i].value, "        ", "   Link : ", self.link[i])
        pass


obj = Dictionary(int(10))
obj.insert(Dict("22","Mango"))
obj.insert(Dict("24","UnDefined"))
obj.insert(Dict("26","People"))
obj.insert(Dict("2","Juice"))
obj.insert(Dict("25","PineApple"))

obj.Display()
if obj.search("26") == True:
    print("Search Successful for ", 26)
else:
    print("Search UnSuccessful for ", 26) 

if obj.search("21") == True:
    print("Search Successful for 21")
else:
    print("Search UnSuccessful for 21") 

obj.remove("26")

obj.Display()