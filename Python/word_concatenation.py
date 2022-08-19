class Trie(object):
    def __init__(self):
        self.str = ''
        self.children = {}

class Solution():
    def __init__(self):
        self.name = 'S->13'
        self.trie = Trie()

    def __CanForm(self, word, words_dict, cache):
        if word in cache:
            return cache[word]
        for i in range(1, len(word)):
            prefix = word[:i]
            suffix = word[i:]
            if prefix in words_dict:
                if suffix in words_dict or self.__CanForm(suffix, words_dict, cache):
                    cache[word] = True
                    return True
        cache[word] = False
        return False

    # Time complexity: O(n*m^2/2)
    # Space complexity: O(n*m^2/2)
    def WordConcatenationA(self, words):
        words_dict = set(words)
        cache = {}
        return [word for word in words if self.__CanForm(word, words_dict, cache)]

    def BuildTrie(self, words):
        self.trie = Trie()
        for word in words:
            cur = self.trie
            for i in range(len(word)):
                if word[i] not in cur.children:
                    cur.children[word[i]] = Trie()
                cur = cur.children[word[i]]
            cur.str = word

    def Search(self, pre, word):
        cur = self.trie
        for i in range(len(word)):
            if word[i] in cur.children:
                cur = cur.children[word[i]]
                if cur.str and i < len(word)-1:
                    new_word = word[i+1:]
                    ret = self.Search(True, new_word)
                    if ret:
                        return True
            else:
                return False
        if pre and cur.str:
            return True
        return False

    # using Tree method
    # Time complexity: O(n * m^2/2)
    # Space complexity: O(n * m^2/2)
    def WordConcatenationB(self, words):
        self.BuildTrie(words)
        result = []
        for word in words:
            if self.Search(False, word):
                result.append(word)
        return result

s = Solution()
words = ["cat" ,"cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat", 'catsdog']
#Output: ["catsdogcats", "dogcatsdog", "ratcatdogcat"]
print(s.WordConcatenationA(words))
print(s.WordConcatenationB(words))
