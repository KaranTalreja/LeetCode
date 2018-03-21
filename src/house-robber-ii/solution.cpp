class Solution {
  public:
    int rob(vector<int>& nums) {
      int size = nums.size();
      if (!size) return 0;
      vector<int> DP(size, 0);
      DP[0] = nums[0];
      // excluding last
      for (int i = 1; i < size-1; i++) {
        DP[i] = max(DP[i-1] , ((i - 2 >= 0) ? DP[i-2] : 0) + nums[i]);
      }
      int rc;
      if (size >= 2) rc = DP[size-2];
      else rc = DP[0];
      // exluding first
      DP[0] = 0;
      for (int i = 1; i < size; i++) {
        DP[i] = max(DP[i-1] , ((i - 2 >= 0) ? DP[i-2] : 0) + nums[i]);
      }
      if (rc < DP[size-1]) rc = DP[size-1];
      return rc;
    }
};
