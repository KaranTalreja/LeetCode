class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int max = 0, size = prices.size();
      int buy = 0, sell = 0;
      for (int i = 0 ; i < size; i++) {
        if (prices[i] - prices[buy] > max) {
          sell = i;
          max = prices[sell] - prices[buy];
        }
        else if (prices[i] - prices[buy] < 0) {
          buy = i;
          sell = i;
        }
      }
      return max;
    }
};
