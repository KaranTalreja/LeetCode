class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int retval = nums[0];
      int currSum = nums[0], prevSum = nums[0];
      int size = nums.size();
      for (int i = 1; i < size; i++) {
        currSum = max(prevSum+nums[i], nums[i]);
        if (currSum > retval) retval = currSum;
        prevSum = currSum;
      }
      return retval;
    }
};
