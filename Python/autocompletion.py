class Tree(object):
    def __init__(self, isWord, children):
        self.isWord = isWord
        self.children = children

class Solution(object):
    def __init__(self):
        self.name = 'S->13'
        self.trie = Tree(False, {})

    def __buildTrie(self, words):
        for word in words:
            cur = self.trie
            for w in word:
                if w not in cur.children:
                    cur.children[w] = Tree(False, {})
                cur = cur.children[w]
            cur.isWord = True

    def __completeDFS(self, node, prefix, result):
        if node.isWord:
            result.append(prefix)

        for char, child in node.children.items():
            self.__completeDFS(child, prefix + char, result)

    # Time complexity: O(m*n)
    # Space complexity: O(m*n) in worst case
    def autocompletion(self, words, prefix):
        self.__buildTrie(words)
        cur = self.trie
        for p in prefix:
            if p not in cur.children:
                return []
            else:
                cur = cur.children[p]
        result = []
        self.__completeDFS(cur, prefix, result)
        return result

words = ['dog', 'dark', 'cat', 'door', 'dodge']
prefix = 'do'
print(Solution().autocompletion(words, prefix))


