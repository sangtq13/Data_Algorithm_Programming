class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int maxProduct(vector<int>& nums) {
        long long mp = -10;
        long long p = 1;
        long long pre_neg_p = -11;
        long long suf_neg_p = 1;
        bool positive = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (p < 0 && positive) {
                    p /= max(pre_neg_p, suf_neg_p);
                }
                if (positive || (!positive && p != 1)) {
                    mp = max(p, mp);
                }
                mp = max(mp, (long long)0);
                pre_neg_p = -11;
                suf_neg_p = 1;
                p = 1;
                positive = false;
                continue;
            }
            p *= nums[i];
            if (nums[i] < 0) {
                if (pre_neg_p == -11) {
                    pre_neg_p = p;
                }
                suf_neg_p = 1;
                if (p > 0) {
                    positive = true;
                }
            }
            else {
                positive = true;
            }
            if (pre_neg_p != -11) suf_neg_p *= nums[i];
        }

        // printf("p %ld pre %ld suf %ld mp %ld %d\n", p, pre_neg_p, suf_neg_p, mp, positive);

        if (p < 0 && positive) {
            p /= max(pre_neg_p, suf_neg_p);
        }
        if (positive || (!positive && p != 1)) {
            mp = max(p, mp);
        }

        return mp;
    }
};
