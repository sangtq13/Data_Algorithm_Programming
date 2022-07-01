class Solution {
public:
    void swap(int&a, int&b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = (left + right) / 2;
        int tmp = nums[pivot];
        swap(nums[pivot], nums[left]);
        int index = left;
        for (int i = left+1; i < right+1; ++i) {
            if (nums[i] < nums[left]) {
                index++;
                swap(nums[i], nums[index]);
            }
        }
        swap(nums[index], nums[left]);
        return index;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int l = nums.size();
        int left = 0;
        int right = l-1;
        while(left <= right) {
            int pivot = partition(nums, left, right);
            if (pivot == l-k){
                return nums[pivot];
            }
            else if (pivot < l-k) {
                left = pivot + 1;
            }
            else {
                right = pivot - 1;
            }
        }
        return -1;
    }
};
