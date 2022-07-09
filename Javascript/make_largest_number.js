/**
 * @param {number[]} nums
 * @return {string}
 */
// Time complexity: O(nlogn)
// Space complexity: O(logn) to O(n) depends on sorting method of js
var largestNumber = function(nums) {
    var s = nums.map(x => x + '')
    s.sort(function(a, b) {return (b+a) - (a+b)})
    if (s[0] == '0') return '0'
    return s.join('')
};
