class Solution {
public:
  // Time complexity: O(n)
  // Space complexity: O(1)
  int maxProfit(vector<int>& prices) {
    int i = 0;
    int n = prices.size();
    int profit = 0;
    while (i < n) {
      while (i < n-1 && prices[i] >= prices[i+1]) i++;
      int buy = prices[i];
      while (i < n-1 && prices[i] < prices[i+1]) i++;
      int sell = prices[i];
      profit += (sell - buy);
      if(i == n-1) break;
    }
    return profit;
  }
};
