class Solution {
public:
    int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b); 
    } 

    // Function to return LCM of two numbers  
    int lcm(int a, int b) 
    { 
        return (a / gcd(a, b)) * b; 
    }

    void rotate(vector<int>& nums, int k, int count, int start) {
        int c = 0;
        int n = nums.size();
        int pre = nums[start];
        while (c < count) {
            int new_index = (start + k) % n;
            int tmp = nums[new_index];
            nums[new_index] = pre;
            pre = tmp;
            start = new_index;
            c++;
        }
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return;
        int l = lcm(n, k);
        for (int i = 0; i < n / (l / k); ++i) {
            rotate(nums, k, l / k, i);
        }
    }
};

class Solution {
public:
    void swap(int& a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    // Time complexity: O(n)
    // Space complexity: O(1)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        for (int i = 0; i < (n-k)/2; ++i) {
            swap(nums[i], nums[n-k-1-i]);
        }

        for (int i = 0; i < k/2; ++i) {
            swap(nums[n-k+i], nums[n-1-i]);
        }

        for (int i = 0; i < n/2; ++i) {
            swap(nums[i], nums[n-1-i]);
        }
    }
};
