class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (auto &num : nums) {
                sum += (num >> i) & 1;
            }
            sum %= 3;
            result += sum << i;
        }
        return result;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
            cout << ones << " " << twos << endl;
        }

        return ones;
    }
};
