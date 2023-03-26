class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        bool prime[1001];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= 1000; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= 1000; i += p)
                    prime[i] = false;
            }
        }
        
        for (int i = nums[0]-1; i > 1; --i) {
            if (prime[i] == true) {
                nums[0] -= i;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            bool check = false;
            for (int j = nums[i]-1; j > 1; --j) {
                if (prime[j] == true && nums[i] - j > nums[i-1]) {
                    nums[i] -= j;
                    check = true;
                    break;
                }
            }
            if (check == false && nums[i-1] >= nums[i]) {
                return false;
            }
        }
        
        return true;
    }
};
