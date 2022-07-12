class Trie():
    def __init__(self):
        self.children = {}
        self.is_words = False


def BuildTrie(root, words):
    for word in words:
        cur = root
        for w in word:
            if w not in cur.children:
                cur.children[w] = Trie()
            cur = cur.children[w]
        cur.is_words = True
    return root

def IsWord(root, word):
    cur = root
    for w in word:
        if w not in cur.children:
            return False
        cur = cur.children[w]
    if cur.is_words:
        return True
    return False

# Using Trie solution
# Time complexity: O(n)
# Space complexity: O(n)
def Solution1(root, words):
    result = ""
    for word in words:
        cur = root
        check = False
        for i in range(len(word)):
            cur = cur.children[word[i]]
            if cur.is_words and IsWord(root, word[i+1:]):
                check = True
                result += "1"
                break
        if not check:
            result += "0"
    print(result)
    return result

# Using Set solution
# Time complexity: O(n)
# Space complexity: O(n)
def Solution2(words):
    s = set()
    result = ''
    for word in words:
        s.add(word)
    for word in words:
        check = True
        for i in range(len(words)):
            prefix = word[:i]
            suffix = word[i:]
            if prefix in s and suffix in s:
                result += '1'
                check = False
                break
        if check: result += '0'

    print(result)
    return result

n = int(input())
for i in range(n):
    root = Trie()
    words = []
    size = int(input())
    for i in range(size):
        s = str(input())
        words.append(s)
    root = BuildTrie(root, words)
    Solution1(root, words)
    Solution2(words)

# Input
# 3
# 5
# abab
# ab
# abc
# abacb
# c
# 3
# x
# xx
# xxx
# 8
# codeforc
# es
# codes
# cod
# forc
# forces
# e
# code

# Output
# 10100
# 011
# 10100101

