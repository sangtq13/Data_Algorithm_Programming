/**
 * @param {string} s
 * @return {number}
 */
function isdigit(char) {
  if (typeof char !== 'string') {
    return false;
  }

  if (char.trim() === '') {
    return false;
  }

  return !isNaN(char);
}

var myAtoi = function(s) {
    var num = 0
    var check_sign = false
    var check_digit = false
    var sign = 1
    var MAX_INT = Math.pow(2, 31) - 1
    var MIN_INT = -MAX_INT - 1
    for (i in s) {
        if (s[i] === ' ' && !check_sign && !check_digit) continue
        if (!isdigit(s[i])) {
            console.log(s[i])
            if (['-', '+'].includes(s[i]) === false || check_sign || check_digit) {
                break
            }
        }
        else {
            if (!check_digit) check_digit = true
            num = num * 10 + parseInt(s[i])
        }
        
        if (['-', '+'].includes(s[i])) {
            check_sign = true
            if (s[i] === '-') {
                sign = -1
            }
        }
    }

    num = sign * num
    if (num < MIN_INT) return MIN_INT
    if (num > MAX_INT) return MAX_INT
    return num
};
