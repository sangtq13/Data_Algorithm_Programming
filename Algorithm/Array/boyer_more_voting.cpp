class Solution {
public:
    // Time complexity: O(n)
    // Space complextiy: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int elm1, elm2;
        int count1 = 0, count2 = 0;
        for (auto& num: nums) {
            if (num == elm1) {
                count1++;
            }
            else if (num == elm2) {
                count2++;
            }
            else if (count1 == 0) {
                count1++;
                elm1 = num;
            }
            else if (count2 == 0) {
                count2++;
                elm2 = num;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto& num: nums) {
            if (num == elm1) {
                count1++;
            }
            else if (num == elm2) {
                count2++;
            }
        }
        
        if (count1 > nums.size()/3) {
            ans.push_back(elm1);
        }
        if (count2 > nums.size()/3) {
            ans.push_back(elm2);
        }

        return ans;
    }
};
