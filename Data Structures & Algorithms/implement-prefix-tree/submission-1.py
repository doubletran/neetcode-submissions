class Node:
    def __init__(self):
        self.hashmap = dict()
        self.end = False

class PrefixTree:

    def __init__(self):
        self.root = Node()
        
    def insert(self, word: str) -> None:
        curr = self.root
        i = 0
        while i < len(word):
            letter = word[i]
            if letter not in curr.hashmap:
                curr.hashmap[letter] = Node()
            curr = curr.hashmap[letter]
            i+= 1
        curr.end = True

    def search(self, word: str) -> bool:

        curr= self.root
        i = 0
        while i < len(word):
            if word[i] in curr.hashmap:
                curr = curr.hashmap[word[i]]
                i += 1
            else:
                return False
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        i = 0
        while i < len(prefix):
            letter = prefix[i]
            if letter in curr.hashmap:
                curr = curr.hashmap[letter]
                i += 1
            else:
                return False
        return True

        
        