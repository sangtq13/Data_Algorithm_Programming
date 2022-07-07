/**
 * @param {string} s
 * @return {boolean}
 */
var next_state_map = {
    'BEGIN': ['DOT1', 'SIGN1', 'DIGIT1'],
    'SIGN1': ['DOT1', 'DIGIT1', 'DIGIT2', 'DIGIT3'],
    'DIGIT1': ['DOT2', 'DIGIT1', 'E'],
    'DOT1': ['DIGIT2'],
    'DOT2': ['DIGIT2', 'E'],
    'DIGIT2': ['E', 'DIGIT2'],
    'E': ['SIGN2', 'DIGIT3'],
    'SIGN2': ['DIGIT3'],
    'DIGIT3': ['DIGIT3'],
};

var state_validator = {
    'BEGIN': (c) => {return true;},
    'SIGN1': (c) => {return c === '+' || c === '-';},
    'DIGIT1': (c) => {return !isNaN(c);},
    'DOT1': (c) => {return c === '.';},
    'DOT2': (c) => {return c === '.';},
    'DIGIT2': (c) => {return !isNaN(c);},
    'E': (c) => {return c === 'E' || c === 'e';},
    'SIGN2': (c) => {return c === '+' || c === '-';},
    'DIGIT3': (c) => {return !isNaN(c);},
};

var isNumber = function(s) {
    var current_state = 'BEGIN'
    for (i in s) {
        var found = false
        for (j in next_state_map[current_state]) {
            if (state_validator[next_state_map[current_state][j]](s[i])) {
                current_state = next_state_map[current_state][j]
                found = true
                break;
            }
        }
        if (!found) {
            return false
        }
    }
    
    return current_state === 'DOT2' || current_state === 'DIGIT1' || current_state === 'DIGIT2' || current_state === 'DIGIT3';
};
