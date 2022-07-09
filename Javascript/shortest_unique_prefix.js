function Trie () {
    this.count=0
    this.children={}
}

function BuildTrie(trie,words) {
    for(i in words) {
        var root=trie;
        for(j in words[i]) {
            if(!(words[i][j] in root.children)) {
                root.children[words[i][j]] = new Trie()
            }
            root = root.children[words[i][j]]
            root.count += 1
        }
    }
}

// Time complexity: O(n)
// Space complexity: O(n)
function ShortestUniquePrefix(words) {
    var root = new Trie();
    var ans = [];
    BuildTrie(root,words)
    for(i in words) {
        var prefix = ''
        var cur = root
        var check = false
        for(j in words[i]) {
            prefix += words[i][j]
            if(cur.children[words[i][j]].count == 1) {
                ans.push(prefix)
                check = true
                break
            }
            cur = cur.children[words[i][j]]
        }
        if(!check)
        ans.push(prefix)
    }
    return ans;
}

console.log(ShortestUniquePrefix(['jon', 'john', 'jack', 'techlead']))
