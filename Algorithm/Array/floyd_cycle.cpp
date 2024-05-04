class Solution {
public:
    // This solution use Floyd’s Cycle algorithm
    // Time complexity: O(n)
    // Space complexity: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int finder = 0;
        // Find the entry of the cycle. 2 duplicated number have the same value and always go the the same point. 
        // That's why entry of the cycle is also the number with duplication
        while (true) {
            slow = nums[slow];
            finder = nums[finder];
            if (slow == finder) {
                return slow;
            }
        }

        return 0;
    }
};
