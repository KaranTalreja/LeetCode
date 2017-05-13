class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      if (!nums.size()) return 0;
      vector<int> OPT(nums.size(),-1);
      int size = nums.size();
      int retval = 0;
      for (int i = 0; i < size; i++) {
        int maxS = 0;
        for (int j = 0; j < i; j++) {
          if (nums[j] < nums[i] && OPT[j] > maxS) maxS = OPT[j];
        }
        OPT[i] = max(maxS+1, 1);
        if (retval < OPT[i]) retval = OPT[i];
      }
      return retval;
    }
};
