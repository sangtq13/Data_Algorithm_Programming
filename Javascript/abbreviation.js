function isLowerCase(myString) { 
    return (myString == myString.toLowerCase()) 
} 

const abbreviation = function(a, b) {
    var upper = 0
    var m = a.length
    var n = b.length
    var dp = Array(n).fill(false).map(x => Array(m).fill(false));
    if (a[0].toUpperCase() == b[0]) dp[0][0] = true
    
    for (var i = 1; i < m; ++i) {
        if (isLowerCase(a[i])) {
            if (a[i].toUpperCase() == b[0] && upper == 0) {
                dp[0][i] = true
            }
            else {
                dp[0][i] = dp[0][i-1];
            }
        }
        else {
            if (a[i] == b[0] && upper == 0) {
                dp[0][i] = true
            }
            upper++;
        }
    }
    for (var i = 1; i < n; ++i) {
        for (var j = i; j < m; ++j) {
            if (isLowerCase(a[j])) {
                if (a[j].toUpperCase() == b[i]) {
                    dp[i][j] = dp[i-1][j-1] | dp[i][j-1]
                }
                else {
                    dp[i][j] = dp[i][j-1]
                }
            }
            else {
                if (a[j] != b[i]) {
                    dp[i][j] = false
                }
                else {
                    dp[i][j] = dp[i-1][j-1]
                }
            }
        }
    }
    console.log(dp)
    return dp[n-1][m-1]
}

a = 'abcDef'
b = 'CDE'

console.log(abbreviation(a, b))
