/**
 * @param {number[]} nums
 * @return {number[]}
 */
 
 // Time complexity: O(n)
 // Space complexity: O(n)
var sortedSquares = function(nums) {
    var ans = []
    var left = -1
    for (var i in nums) {
        if (nums[i] <= 0) {
            left++
        }
        else {
            break
        }
    }
    var right = left + 1;
    while (left > -1 && right < nums.length) {
        var left_square = nums[left] * nums[left]
        var right_square = nums[right] * nums[right]
        if (left_square < right_square) {
            ans.push(left_square)
            left--
        }
        else {
            ans.push(right_square)
            right++
        }
    }
    
    if (left > -1) {
        for (var i = left; i > -1; --i) {
            ans.push(nums[i] * nums[i])
        }
    }
    
    if (right < nums.length) {
        for (var i = right; i < nums.length; ++i) {
            ans.push(nums[i] * nums[i])
        }
    }
    
    return ans
};
