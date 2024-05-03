class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size() - 1;
        int maxIndex = citations.size();
        int hIndex = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (citations[mid] >= (maxIndex - mid)) {
                hIndex = maxIndex - mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return hIndex;
    }
};
