class Solution {
  public:
    int thirdMax(vector<int>& nums2) {
      vector<long int> nums(nums2.size());
      int length = nums.size();
      for (int i = 0; i < length; i++) {
        nums[i] = nums2[i];
      }
      long max = (long)INT_MIN - 1, abs_max = (long)INT_MIN -1;
      for (int j = 0; j < 3; j++) {
        for (int i = 0; i < length; i++) {
          if (max < nums[i])  max = nums[i];
        }
        if (j == 0) abs_max = max;
        if (j != 2) {
          for (int i = 0; i < length; i++) {
            if (max == nums[i])  {
              nums[i] = (long)INT_MIN-1;
            }
          }
          max = (long)INT_MIN-1;
        }
      }
      if (max == (long)INT_MIN-1) return abs_max;
      return max;
    }
};
