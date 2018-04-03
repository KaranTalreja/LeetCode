class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int size = nums.size();
      if (!size) return false;
      vector<bool> DP (size, false);
      DP[0] = true;
      for (int i = 1; i < size; i++) {
        for (int j = i-1; j >= 0; j--) {
          if (DP[j] == true && nums[j] >= i-j) {
            DP[i] = true;
            break;
          }
        }
      }
      return DP.back();
    }
};
