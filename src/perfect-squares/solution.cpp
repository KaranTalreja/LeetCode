class Solution {
  public:
    int numSquares(int n) {
      if (!n) return 0;
      static vector<int> DP = {-1};
      int m = DP.size();
      if (m < n+1) DP.resize(n+1, -1);
      for (int i = 1; i*i <= n; i++) {
        DP[i*i] = 1;
      }
      for (int i = 1; i <= n; i++) {
        if (DP[i] != 1) {
          int minNum = INT_MAX;
          for (int j = 1; (i - j*j) >= 1; j++) {
            int rc = DP[i-j*j] + 1;
            if (minNum > rc) minNum = rc;
          }
          DP[i] = minNum;
        }
      }
      return DP[n];
    }
};
