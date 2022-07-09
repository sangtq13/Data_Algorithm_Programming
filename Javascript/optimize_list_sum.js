function Sum() {
    this.sums = [0]

    // Time complexity: O(n)
    // Space complexity: O(n)
    this.BuildSum = function (nums) {
        var sum = 0
        for (i in nums) {
            sum += nums[i]
            this.sums.push(sum)
        }
    }

    // Time complexity: O(1)
    this.OptimizeSum = function (start, end) {
        return this.sums[end] - this.sums[start]
    }
}

nums = [1,2,3,4,5,6,7,8,9,10]
var s = new Sum()
s.BuildSum(nums)
console.log(s.OptimizeSum(2,5))
