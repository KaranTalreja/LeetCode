class Solution {
  public:
    int rob(vector<int>& nums) {
      int size = nums.size();
      if (!size) return size;
      vector<int> DP(size, 0);
      DP[0] = nums[0];
      for (int i = 1; i < size; i++) {
        DP[i] = max(DP[i-1], (i-2 >=0 ? DP[i-2] : 0) + nums[i]);
      }
      return DP[size-1];
    }
};
