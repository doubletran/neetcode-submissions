class Node:

    def __init__(self):
        self.children = [0]* (ord('z') - ord('a'))
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        curr = self.root
        i = 0
        while i < len(word):
            letter = word[i]
            windex = ord(letter) - ord('a')
            if curr.children[windex] == 0:
                curr.children[windex] = Node()
            curr = curr.children[windex]
            i+=1
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root
        i = 0
        def rsearch(word, node):
            curr = node
            i = 0
            while i < len(word):
                if word[i] == '.':
                    valid = False
                    for child in curr.children:
                        if child == 0:
                            continue
                        if rsearch(word[i+1:], child):
                            return True
                    return False
                windex = ord(word[i]) - ord('a')
                if curr.children[windex] == 0:
                    return False
                    curr.children[windex] = Node()
                curr = curr.children[windex]
                i+= 1
            return curr.endOfWord
        return rsearch(word, curr)
        
