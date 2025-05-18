int digitSum(int num) {
    int s = 0;
    while (num > 0) {
        s += num % 10;
        num /= 10;
    }
    return s;
}

bool compare(int a, int b) {
    int sa = digitSum(a);
    int sb = digitSum(b);
    return sa < sb || ((sa == sb) && (a < b));
}

class Solution {
public:
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    int minSwaps(vector<int>& nums) {
        int swaps = 0;
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end(), compare);
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(temp[i] != nums[i]) {
                // Index of the element that should be at index i.
                int ind = pos[temp[i]];
                swap(nums[i], nums[ind]);
                // Update the indices in the hashmap
                pos[nums[i]] = i; 
                pos[nums[ind]] = ind;
                swaps++; 
            }
        }
        return swaps;
    }
};
