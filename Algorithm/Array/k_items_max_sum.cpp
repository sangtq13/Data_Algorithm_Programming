class Solution {
public:
  
    // Time complexity: O(1)
    // Space complexity: O(1)
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        }
        int left = k - numOnes;
        if (left <= numZeros) {
            return numOnes;
        }
        left -= numZeros;
        return numOnes - left;
    }
};
