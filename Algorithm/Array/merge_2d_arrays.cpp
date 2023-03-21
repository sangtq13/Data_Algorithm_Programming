class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        int s1 = nums1.size();
        int s2 = nums2.size();
        
        while (i < s1 && j < s2) {
            if (nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i][0] > nums2[j][0]) {
                ans.push_back(nums2[j]);
                j++;
            }
            else {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }
        if (i < s1) {
            for (; i < s1; ++i) ans.push_back(nums1[i]);
        }
        if (j < s2) {
            for (; j < s2; ++j) ans.push_back(nums2[j]);
        }
        
        return ans;
    }
};
