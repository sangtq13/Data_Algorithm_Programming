// Time complexity: O(nlogn)
// Space complexity: O(n)
var numSquares = function(n) {
    var i = 0;
    squares = []
    while (i * i <= n) {
        squares.push(i * i)
        i++
    }
    
    min_sums = new Array(n+1).fill(n)
    min_sums[0] = 0
    for (var i = 0; i <= n; ++i) {
        for (let s of squares) {
            if (i + s <= n) {
                min_sums[i + s] = Math.min(min_sums[i + s], min_sums[i] + 1)
            }
        }
    }
    return min_sums[min_sums.length-1]
};
