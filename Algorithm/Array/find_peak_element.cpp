class Solution {
public:

    // Time complexity: O(logn)
    // Space complexity: O(1)

    int findPeakElement(vector<int>& nums) {
        stack<pair<int, int>> s;
        int n = nums.size();
        s.push({0, n-1});
        while (!s.empty()) {
            pair<int, int> top = s.top();
            s.pop();
            int mid = (top.first + top.second) / 2;
            long long left_value = mid - 1 >= 0 ? nums[mid-1] : -2147483649;
            long long right_value = mid + 1 < n ? nums[mid + 1] : -2147483649;
            if ((long long)nums[mid] > left_value && (long long)nums[mid] > right_value) {
                return mid;
            }
            if (mid - 1 >= top.first) {
                s.push({top.first, mid-1});
            }
            if (mid + 1 <= top.second) {
                s.push({mid+1, top.second});
            }
        }

        return -1;
    }
};
