const int BEGIN = 0;
const int SIGN1 = 1;
const int DIGIT1 = 2;
const int DOT1 = 3;
const int DOT2 = 4;
const int DIGIT2 = 5;
const int E = 6;
const int SIGN2 = 7;
const int DIGIT3 = 8;

map<int, function<bool (char c)>> state_validator = {
    {BEGIN, [] (char c) -> bool {return true;}},
    {SIGN1, [] (char c) -> bool {return c == '+' || c == '-';}},
    {DIGIT1, [] (char c) -> bool {return isdigit(c);}},
    {DOT1, [] (char c) -> bool {return c == '.';}},
    {DOT2, [] (char c) -> bool {return c == '.';}},
    {DIGIT2, [] (char c) -> bool {return isdigit(c);}},
    {E, [] (char c) -> bool {return c == 'E' || c == 'e';}},
    {SIGN2, [] (char c) -> bool {return c == '+' || c == '-';}},
    {DIGIT3, [] (char c) -> bool {return isdigit(c);}},
};

map<int, vector<int>> next_state_map = {
    {BEGIN, {DOT1, SIGN1, DIGIT1}},
    {SIGN1, {DOT1, DIGIT1, DIGIT2, DIGIT3}},
    {DIGIT1, {DOT2, DIGIT1, E}},
    {DOT1, {DIGIT2}},
    {DOT2, {DIGIT2, E}},
    {DIGIT2, {E, DIGIT2}},
    {E, {SIGN2, DIGIT3}},
    {SIGN2, {DIGIT3}},
    {DIGIT3, {DIGIT3}},
};

class Solution {
public:
    bool isNumber(string s) {
        int current_state = BEGIN;
        for (auto &c : s) {
            bool found = false;
            for (auto& next_state : next_state_map[current_state]) {
                if (state_validator[next_state](c)) {
                    current_state = next_state;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }

        return current_state == DOT2 || current_state == DIGIT1 || current_state == DIGIT2 || current_state == DIGIT3;
    }
};
