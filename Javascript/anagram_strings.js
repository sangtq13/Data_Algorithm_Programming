/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
const compare = (a, b) => {
    if (a.length !== b.length) return false
    for (let i = 0; i < a.length; ++i) {
        if (a[i] !== b[i]) return false
    }
    return true
};

var findAnagrams = function(s, p) {
    let lp = p.length
    let ls = s.length
    let a = "a".charCodeAt(0)
    if (ls < lp) return []
    let ks = Array(26).fill(0)
    let kp = Array(26).fill(0)
    let ret = []
    for (let i = 0; i < lp; ++i) {
        ks[s[i].charCodeAt(0) - a] += 1
        kp[p[i].charCodeAt(0) - a] += 1
    }
    
    if (compare(ks, kp)) {
        ret.push(0)
    }
    for (let i = 1; i < ls - lp + 1; ++i) {
        ks[s[i-1].charCodeAt(0) - a] -= 1
        ks[s[i+lp-1].charCodeAt(0) - a] += 1
        if (compare(ks, kp)) {
            ret.push(i)
        }
    }
    
    return ret;
};
