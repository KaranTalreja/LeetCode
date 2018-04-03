class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      int N = coins.size();
      if (!N) return -1;
      if (amount <= 0) return 0;
      vector<vector<int>> DP(N, vector<int>(amount+1, 0));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j <= amount; j++) {
          if (j == 0) { DP[i][j] = 0; continue;}
          DP[i][j] = ((i-1 >= 0) ? DP[i-1][j] : INT_MAX);
          if (j - coins[i] >= 0 && DP[i][j-coins[i]] < INT_MAX) DP[i][j] = min(DP[i][j], DP[i][j-coins[i]]+1);
        }
      }
      return (DP[N-1][amount] == INT_MAX) ? -1 : DP[N-1][amount];
    }
};
