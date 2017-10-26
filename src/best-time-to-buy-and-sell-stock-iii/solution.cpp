class Solution {
  public:
    int helper(vector<int>& prices, int i , vector<int>& DP, int depth) {
      if (depth > 1) return 0;
      if (i >= prices.size()) return 0;
      if (DP[i] != -1) return DP[i];
      int minP = prices[i];
      int retval = 0;
      for (int j = i; j < prices.size(); j++) {
        if (minP > prices[j]) minP = prices[j];
        if (prices[j] > minP) {
          int temp = max(prices[j] - minP + helper(prices, j+1, DP, depth+1), prices[j] - minP);
          if (retval < temp) retval = temp;
        }
      }
      DP[i] = retval;
      return retval;
    }

    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (!size) return 0;
      vector<int> DP(size, -1);
      return helper(prices, 0, DP, 0);
    }
};
