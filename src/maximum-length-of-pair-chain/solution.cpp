class Solution {
  public:
    static bool comp (vector<int>& a, vector<int>& b) {
      return (a[0] < b[0]) ? true : false;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
      int len = pairs.size();
      if (!len) return 0;
      sort(pairs.begin(), pairs.end(), comp);
      vector<int> DP(len, 1);
      for (int i = 1; i < len; i++) {
        int max = 1;
        for (int j = i-1; j >= 0; j--) {
          if (pairs[i][0] > pairs[j][1]) {
            if (max < DP[j] + 1) max = DP[j]+1;
          }
        }
        DP[i] = max;
      }
      return DP.back();
    }
};
