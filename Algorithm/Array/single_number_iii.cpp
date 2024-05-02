class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        int num1 = 0;
        int num2 = 0;
        for (auto& n: nums) {
            x ^= n;
        }
        int i = 0;
        while ((x & (1 << i)) == 0) {
            i++;
        }

        for (auto& n: nums) {
            if (n & (1 << i)) {
                num1 ^= n;
            }
            else {
                num2 ^= n;
            }
        }
        return {num1, num2};
    }
};
